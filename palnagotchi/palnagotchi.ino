#include <M5AtomS3.h>

#include <Arduino.h>
#include <M5Unified.h>
#include <esp_log.h>
#include "ui.h"
#include "home.h"
#include "state.h"
#include "mood.h"
#include "pwngrid.h"

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
    UI::init();
    initHome();
    State::set(State::INIT);
}

void wakeUp() {
    for (uint8_t i = 0; i < 3; i++) {
        Mood::set(i);
        UI::update();
        delay(1250);
    }
}

void loop() {
    M5.update();
    
    switch (State::get()) {
        case State::HALT:
            return;
        case State::INIT:
            wakeUp();
            State::set(State::WAKE);
            break;
        case State::WAKE:
            Mood::set(random(7, 14));
            break;
        case State::BORED:
            Mood::set(random(15, 16));
            break;
        case State::CURIOUS:
            Mood::set(random(2, 6));
            pwngridLoop();
            break;
        case State::ANGRY:
            Mood::set(17);
            break;
        case State::SAD:
            Mood::set(18);
            break;
        case State::SLEEP:
            Mood::set(0);
            break;
    }

    delay(10000);

    State::change();
    UI::update(true);
}
