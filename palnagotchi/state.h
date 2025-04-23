#ifndef PALNAGOTCHI_STATE_H
#define PALNAGOTCHI_STATE_H

#include <Arduino.h>

// State definitions
enum State {
    STATE_INIT = 0,
    STATE_WAKE = 1,
    STATE_PWNAGOTCHI_FOUND = 10,
    STATE_DEAUTH_DETECTED = 30,
    STATE_HALT = 255
};

// Function declarations
void setState(uint8_t newState);
uint8_t getCurrentState();

#endif // PALNAGOTCHI_STATE_H
