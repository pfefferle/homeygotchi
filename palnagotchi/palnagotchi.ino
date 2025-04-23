#include <M5AtomS3.h>

#include <Arduino.h>
#include <M5Unified.h>
#include <esp_log.h>
#include "ui.h"
#include "home.h"
#include "state.h"
#include "pwngrid.h"
#include "deauth.h"

// Channel and timing variables
uint8_t current_channel = 1;
uint32_t last_mood_switch = 10001;
uint32_t last_home_update = 0;
uint32_t last_mode_switch = 0;
const uint32_t MODE_SWITCH_INTERVAL = 30000; // Switch modes every 30 seconds

void initM5() {
    auto cfg = M5.config();
    M5.begin();
    M5.Display.begin();
    Serial.begin(115200);
}

void initWiFi() {
    // Disable WiFi logging
    esp_log_level_set("wifi", ESP_LOG_NONE);

    // Basic WiFi initialization
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_start();
}

void setup() {
    initM5();
    initWiFi();
    initUi();
    initHome();
    setState(STATE_INIT);
}

void wakeUp() {
    for (uint8_t i = 0; i < 3; i++) {
        setMood(i);
        updateUi();
        sendMoodToHome();
        delay(1250);
    }
}

void advertise(uint8_t channel) {
    uint32_t elapsed = millis() - last_mood_switch;
    if (elapsed > 5000) {
        Serial.println("Switching mood");
        setMood(random(2, 21));
        last_mood_switch = millis();
    }

    esp_err_t result = pwngridAdvertise(channel, getCurrentMoodFace());

    if (result == ESP_ERR_WIFI_IF) {
        setMood(MOOD_BROKEN, "", "Error: invalid interface", true);
        setState(STATE_HALT);
    } else if (result == ESP_ERR_INVALID_ARG) {
        setMood(MOOD_BROKEN, "", "Error: invalid argument", true);
        setState(STATE_HALT);
    } else if (result != ESP_OK) {
        setMood(MOOD_BROKEN, "", "Error: unknown", true);
        setState(STATE_HALT);
    }

    elapsed = millis() - last_home_update;
    if (elapsed > 10000) {
        Serial.println("Sending mood to home");
        sendMoodToHome();
        last_home_update = millis();
    }
}

void loop() {
    M5.update();

    if (getCurrentState() == STATE_HALT) {
        return;
    }

    if (getCurrentState() == STATE_INIT) {
        wakeUp();
        setState(STATE_WAKE);
    }

    if (getCurrentState() == STATE_WAKE) {
        checkPwngridGoneFriends();
        advertise(current_channel++);
        if (current_channel == 15) {
            current_channel = 1;
        }
    }

    if (getCurrentState() == STATE_PWNAGOTCHI_FOUND) {
        sniffForDeauth();
    }

    updateUi(true);
}
