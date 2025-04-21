#include "home.h"

BTHome bthome;

void initHome() {
    // Initialize BTHome with device name "Palnagotchi"
    String deviceName = "Palnagotchi";
    bthome.begin(deviceName, false, "", false);
}

void updateHome() {
    // Reset previous measurements
    bthome.resetMeasurement();

    // Add mood as a state measurement
    //bthome.addMeasurement_state(STATE_GENERIC_BOOLEAN, getCurrentMoodId());

    // Add battery level (placeholder)
    bthome.addMeasurement(ID_BATTERY, (uint64_t)100);

    // Add current face as a text measurement
    String face = getCurrentMoodFace();
    uint8_t faceBytes[face.length() + 1];
    face.getBytes(faceBytes, face.length() + 1);
    bthome.addMeasurement(ID_TEXT, faceBytes, face.length() + 1);

    // Add current mood as a text measurement
    String phrase = getCurrentMoodPhrase();
    uint8_t phraseBytes[phrase.length() + 1];
    phrase.getBytes(phraseBytes, phrase.length() + 1);
    bthome.addMeasurement(ID_TEXT, phraseBytes, phrase.length() + 1);

    bthome.buildPaket();

    // Send the packet
    bthome.sendPacket();

    bthome.stop();
}