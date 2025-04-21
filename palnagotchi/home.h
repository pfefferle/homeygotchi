#ifndef HOME_H
#define HOME_H

#include <Arduino.h>
#include "BTHome.h"
#include "pwngrid.h"
#include "mood.h"

extern BTHome bthome;

void initHome();
void updateHome();

#endif // HOME_H