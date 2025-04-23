#include "state.h"

// Current state variable
static uint8_t currentState = STATE_INIT;

void setState(uint8_t newState) {
    currentState = newState;
}

uint8_t getCurrentState() {
    return currentState;
}
