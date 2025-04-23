#ifndef PALNAGOTCHI_DEAUTH_H
#define PALNAGOTCHI_DEAUTH_H

#include <Arduino.h>
#include <esp_wifi.h>
#include "state.h"

// External variables
extern volatile int deauthCount;
extern unsigned long lastDeauthCheck;
extern unsigned long lastChannelSwitch;
extern int currentChannel;
extern wifi_promiscuous_filter_t deauth_filter;

// Function declarations
void deauthSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
void sniffForDeauth();
void initDeauthSniffer();

#endif // PALNAGOTCHI_DEAUTH_H
