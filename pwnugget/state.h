#ifndef PWNUGGET_STATE_H
#define PWNUGGET_STATE_H

#include <Arduino.h>

struct StateDuration {
    uint8_t state;
    unsigned long minDuration;
    unsigned long maxDuration;
};

class State {
public:
    // ...
    static bool shouldBeBored(uint32_t currentTime);
public:
    // State constants
    static const uint8_t INIT    = 0;
    static const uint8_t WAKE    = 10;
    static const uint8_t CURIOUS = 20;
    static const uint8_t ANGRY   = 30;
    static const uint8_t SAD     = 40;
    static const uint8_t HAPPY   = 50;
    static const uint8_t BORED   = 100;
    static const uint8_t SLEEP   = 200;
    static const uint8_t HALT    = 255;

    // State management
    static void set(uint8_t newState);
    static uint8_t get();
    static void change();

    // Duration helpers
    static unsigned long getMinDuration(uint8_t state);
    static unsigned long getMaxDuration(uint8_t state);

private:
    static uint8_t currentState;
    static uint32_t lastSwitch;
    static uint32_t nextSwitch;
};

#endif // PWNUGGET_STATE_H
