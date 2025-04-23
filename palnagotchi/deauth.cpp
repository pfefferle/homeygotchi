#include "deauth.h"

// Configuration
const int max_channel = 13;
const int check_interval = 1000; // in milliseconds
const int max_iterations = 3; // Number of times to iterate through all channels
const int deauth_threshold = 5; // Number of deauths per interval to trigger alert
const int timeout_seconds = 30; // Stop if no deauths detected for this long

// State tracking
static unsigned long last_check = 0;
static unsigned long last_deauth = 0;
static int current_channel = 1;
static int iteration_count = 0;
static bool is_sniffing = false;
static volatile int deauth_count = 0;

// WiFi configuration
wifi_promiscuous_filter_t deauth_filter = {
    .filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT
};

void deauthSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type) {
    if (type == WIFI_PKT_MGMT) {
        const wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;
        const uint8_t* payload = pkt->payload;

        uint8_t frame_type = payload[0];
        if ((frame_type & 0xF0) == 0xC0) { // 0xC0 is deauth frame
            Serial.println("Deauth detected");
            deauth_count++;
            last_deauth = millis();
        }
    }
}

void sniffForDeauth() {
    initDeauthSniffer();

    if (!is_sniffing) {
        // Start new sniffing session.
        is_sniffing = true;
        iteration_count = 0;
        current_channel = 1;
        last_check = millis();
        last_deauth = millis();
        deauth_count = 0;
        return;
    }

    // Check for timeout.
    unsigned long current_time = millis();
    if (current_time - last_deauth >= (timeout_seconds * 1000)) {
        Serial.println("No deauths detected for timeout period");
        is_sniffing = false;
        setState(STATE_WAKE);
        return;
    }

    // Update channel if needed.
    if (current_time - last_check >= check_interval) {
        // Check deauth count before switching channels.
        if (deauth_count >= deauth_threshold) {
            Serial.println("Deauth threshold reached");
            is_sniffing = false;
            setState(STATE_WAKE);
            return;
        }

        // Reset deauth count for next interval.
        deauth_count = 0;

        current_channel++;
        if (current_channel > max_channel) {
            current_channel = 1;
            iteration_count++;

            if (iteration_count >= max_iterations) {
                Serial.println("Completed all channel iterations");
                is_sniffing = false;
                setState(STATE_WAKE);
                return;
            }
        }

        esp_wifi_set_channel(current_channel, WIFI_SECOND_CHAN_NONE);
        last_check = current_time;
        Serial.printf("Switching to channel %d (iteration %d/%d)\n",
                     current_channel, iteration_count + 1, max_iterations);
    }
}

void initDeauthSniffer() {
    // Set up deauth configuration.
    wifi_promiscuous_filter_t deauth_filter = {
        .filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT
    };
    esp_wifi_set_promiscuous_filter(&deauth_filter);
    esp_wifi_set_promiscuous_rx_cb(&deauthSnifferCallback);
    esp_wifi_set_promiscuous(true);

    // Reset deauth sniffing state.
    esp_wifi_set_channel(random(0, 14), WIFI_SECOND_CHAN_NONE);
    delay(1);
}
