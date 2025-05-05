#include "state.h"
#include "mood.h"

extern unsigned long lastDetection;

// Duration table for each state
const StateDuration stateDurations[] = {
    { State::WAKE,    30000, 90000 },
    { State::BORED,   20000, 60000 },
    { State::CURIOUS, 30000, 90000 },
    { State::ANGRY,   10000, 30000 },
    { State::SAD,     10000, 30000 },
    { State::SLEEP,   60000, 300000 }
};
const size_t stateDurationsCount = sizeof(stateDurations) / sizeof(StateDuration);

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

unsigned long State::getMinDuration(uint8_t state) {
    for (size_t i = 0; i < stateDurationsCount; ++i) {
        if (stateDurations[i].state == state) return stateDurations[i].minDuration;
    }
    return 10000; // default
}

unsigned long State::getMaxDuration(uint8_t state) {
    for (size_t i = 0; i < stateDurationsCount; ++i) {
        if (stateDurations[i].state == state) return stateDurations[i].maxDuration;
    }
    return 60000; // default
}

bool State::shouldBeBored(uint32_t currentTime) {
    extern unsigned long lastDetection;
    unsigned long threshold = 3UL * 3600UL * 1000UL + 33UL * 60UL * 1000UL; // 3h 33m in ms
    return (currentTime - lastDetection > threshold);
}

void State::change() {
    uint32_t currentTime = millis();
    if (shouldBeBored(currentTime) && get() != State::BORED) {
        set(State::BORED);
        lastDetection = currentTime; // reset boredom timer
        return;
    }

    // Handle timed state transitions globally
    if (currentTime >= nextSwitch) {
        switch (get()) {
            case State::WAKE: {
                uint8_t map[3] = {State::CURIOUS, State::WAKE, State::SLEEP};
                set(map[random(0, 3)]);
                break;
            }
            case State::SLEEP:
                set(State::WAKE);
                break;
            case State::BORED:
                set(State::SLEEP);
                break;
            case State::CURIOUS: {
                // Either Angry or Sad
                uint8_t map[4] = {State::ANGRY, State::SAD, State::CURIOUS, State::WAKE};
                set(map[random(0, 4)]);
                break;
            }
            case State::ANGRY:
                set(State::SAD);
                break;
            case State::SAD:
                set(State::BORED);
                break;
            default:
                set(State::WAKE);
                break;
        }

        Serial.print(Mood::getFace());
        Serial.print(" - ");
        Serial.printf("State changed to %d\n", get());

        lastSwitch = currentTime;
        nextSwitch = currentTime + random(getMinDuration(get()), getMaxDuration(get()));
    }
}
