#ifndef PALNAGOTCHI_HOME_H
#define PALNAGOTCHI_HOME_H

#include <Arduino.h>
#include "src/BTHome/BTHome.h"
#include "pwngrid.h"
#include "mood.h"
#include "config.h"

// External variables
extern BTHome bthome;

// Function declarations
void initHome();
void sendMoodToHome();

#endif // PALNAGOTCHI_HOME_H
