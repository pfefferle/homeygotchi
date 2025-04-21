#include "home.h"

BTHome bthome;

uint32_t last_update = 10001;

void initHome() {
    // Initialize BTHome with device name.
    String device_name = homeygotchi_name;
    bthome.begin(device_name, false, "", false);

    // Send initial update.
    updateHome(true);
}

void updateHome(bool force) {
    // Update only every 10 minutes.
    if (!force && millis() - last_update < 600000) {
        return;
    }
    last_update = millis();

    // Reset previous measurements.
    bthome.resetMeasurement();

    // Add current face as a text measurement.
    String face = getCurrentMoodFace();
    uint8_t face_bytes[face.length() + 1];
    face.getBytes(face_bytes, face.length() + 1);
    bthome.addMeasurement(ID_TEXT, face_bytes, face.length() + 1);

    // Add current mood as a text measurement.
    String phrase = getCurrentMoodPhrase();
    uint8_t phrase_bytes[phrase.length() + 1];
    phrase.getBytes(phrase_bytes, phrase.length() + 1);
    bthome.addMeasurement(ID_TEXT, phrase_bytes, phrase.length() + 1);

    // Send the packet.
    bthome.sendPacket();

    bthome.stop();
}