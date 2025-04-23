#ifndef PALNAGOTCHI_MOOD_H
#define PALNAGOTCHI_MOOD_H

#include <Arduino.h>

// Mood definitions
enum Mood {
    MOOD_BROKEN = 19
};

// Function declarations
void setMood(uint8_t mood, String face = "", String phrase = "", bool broken = false);
uint8_t getCurrentMoodId();
String getCurrentMoodFace();
String getCurrentMoodPhrase();
bool isCurrentMoodBroken();

#endif // PALNAGOTCHI_MOOD_H
