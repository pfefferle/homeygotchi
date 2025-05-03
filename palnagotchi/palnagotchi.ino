#include <M5AtomS3.h>

#include <Arduino.h>
#include <M5Unified.h>
#include <esp_log.h>
#include "ui.h"
#include "home.h"
#include "state.h"
#include "mood.h"
#include "pwngrid.h"
#include "deauth.h"

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
    State::set(State::INIT);
}

void wakeUp() {
    for (uint8_t i = 0; i < 3; i++) {
        Mood::set(i);
        updateUi();
        delay(1250);
    }
}

void loop() {
    M5.update();
    uint32_t current_time = millis();

    switch (State::get()) {
        case State::HALT:
            return;
        case State::INIT:
            wakeUp();
            State::set(State::WAKE);
            break;
        case State::WAKE:
            Mood::set(random(2, 13));
            pwngridLoop();
            break;
        case State::SLEEP:
            Mood::set(random(0, 2));
            delay(10000);
            break;
    }

    State::change();

    updateUi(true);
    delay(1000);
}
