#ifndef PALNAGOTCHI_STATE_H
#define PALNAGOTCHI_STATE_H

#include <Arduino.h>

class State {
public:
    // State constants
    static const uint8_t INIT      = 0;
    static const uint8_t WAKE      = 1;
    static const uint8_t SLEEP     = 2;
    static const uint8_t PWNAGOTCHI_FOUND = 10;
    static const uint8_t DEAUTH_DETECTED  = 30;
    static const uint8_t HALT      = 255;

    // State management
    static void set(uint8_t newState);
    static uint8_t get();
    static void change();

private:
    static uint8_t currentState;
    static uint32_t lastSwitch;
    static uint32_t nextSwitch;
};

#endif // PALNAGOTCHI_STATE_H
