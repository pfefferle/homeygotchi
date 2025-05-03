#include "home.h"

BTHome bthome;

void initHome() {
    // Initialize BTHome with device name.
    String device_name = homeygotchi_name;
    bthome.begin(device_name, false, "", false);
}

void sendMoodToHome() {
    // Add current face as a text measurement.
    String face = Mood::getFace();
    uint8_t face_bytes[face.length() + 1];
    face.getBytes(face_bytes, face.length() + 1);

    // Add current mood as a text measurement.
    String phrase = Mood::getPhrase();
    uint8_t phrase_bytes[phrase.length() + 1];
    phrase.getBytes(phrase_bytes, phrase.length() + 1);

    // Reset previous measurements.
    bthome.resetMeasurement();

    bthome.addMeasurement(ID_TEXT, face_bytes, face.length() + 1);
    bthome.addMeasurement(ID_TEXT, phrase_bytes, phrase.length() + 1);

    bthome.sendPacket();
    bthome.stop();

    delay(1000);
}
