#ifndef PWNUGGET_HOME_H
#define PWNUGGET_HOME_H

#include <Arduino.h>
#include "src/BTHome/BTHome.h"
#include "src/wifi/pwngrid.h"
#include "mood.h"
#include "config.h"

// External variables
extern BTHome bthome;

// Function declarations
void initHome();
void sendMoodToHome();

#endif // PWNUGGET_HOME_H
