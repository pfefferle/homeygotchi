#ifndef MOOD_H
#define MOOD_H

#include <Arduino.h>

#define MOOD_BROKEN 19

void setMood(uint8_t mood, String face = "", String phrase = "",
             bool broken = false);
uint8_t getCurrentMoodId();
String getCurrentMoodFace();
String getCurrentMoodPhrase();
bool isCurrentMoodBroken();

#endif // MOOD_H
