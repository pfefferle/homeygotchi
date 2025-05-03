#include "state.h"

// Current state variable
uint8_t State::currentState = State::INIT;
uint32_t State::lastSwitch = 0;
uint32_t State::nextSwitch = millis() + random(10000, 60000);

void State::set(uint8_t newState) {
    currentState = newState;
}

uint8_t State::get() {
    return currentState;
}

void State::change() {
    // Switch between states and sleep for random time
    uint32_t currentTime = millis();

    switch (get()) {
        case State::WAKE:
            if (currentTime >= nextSwitch) {
                set(State::SLEEP);
                lastSwitch = currentTime;
                nextSwitch = currentTime + random(5000, 30000);
            }
            break;
        case State::SLEEP:
            if (currentTime >= nextSwitch) {
                set(State::WAKE);
                lastSwitch = currentTime;
                nextSwitch = currentTime + random(10000, 60000);
            }
            break;
        default:
            set(State::WAKE);
            break;
    }
}
