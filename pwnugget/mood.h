#ifndef PWNUGGET_MOOD_H
#define PWNUGGET_MOOD_H

#include <Arduino.h>

const uint8_t MOOD_BROKEN = 19;

class Mood {
public:
    static void set(uint8_t mood, String face = "", String phrase = "", bool broken = false);
    static uint8_t getId();
    static String getFace();
    static String getPhrase();
    static bool isBroken();
    static void change();

private:
    static uint8_t currentMood;
    static String currentFace;
    static String currentPhrase;
    static bool currentBroken;
};

#endif // PWNUGGET_MOOD_H
