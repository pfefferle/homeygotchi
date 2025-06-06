#include "mood.h"
#include "globals.h"

uint8_t Mood::currentMood = 0;
String Mood::currentFace = "";
String Mood::currentPhrase = "";
bool Mood::currentBroken = false;

uint8_t Mood::getId() { return currentMood; }
String Mood::getFace() { return currentFace; }
String Mood::getPhrase() { return currentPhrase; }
bool Mood::isBroken() { return currentBroken; }

void Mood::set(uint8_t mood, String face, String phrase, bool broken) {
    currentMood = mood;
    currentBroken = broken;
    currentFace = (face != "") ? face : homeygotchi_moods[currentMood];
    currentPhrase = (phrase != "") ? phrase : homeygotchi_moods_desc[currentMood];
}
