#ifndef PWNUGGET_PWNGRID_H
#define PWNUGGET_PWNGRID_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <EEPROM.h>
#include <M5Unified.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include "state.h"
#include "mood.h"
#include "config.h"
// #include "freertos/FreeRTOS.h"

// Peer information structure
typedef struct {
    int epoch;
    String face;
    String grid_version;
    String identity;
    String name;
    int pwnd_run;
    int pwnd_tot;
    String session_id;
    int timestamp;
    int uptime;
    String version;
    signed int rssi;
    int last_ping;
    bool gone;
} pwngrid_peer;

// Function declarations
void pwnSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
void initPwngrid();
void pwngridLoop();
void pwngridAddPeer(JsonDocument& json, int rssi);
esp_err_t pwngridAdvertise(uint8_t channel, String face);
pwngrid_peer* getPwngridPeers();
uint8_t getPwngridRunTotalPeers();
uint8_t getPwngridTotalPeers();
String getPwngridLastFriendName();
signed int getPwngridClosestRssi();
void checkPwngridGoneFriends();

#endif // PWNUGGET_PWNGRID_H
