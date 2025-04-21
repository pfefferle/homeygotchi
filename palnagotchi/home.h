#ifndef HOME_H
#define HOME_H

#include <Arduino.h>
#include "BTHome.h"
#include "pwngrid.h"
#include "mood.h"
#include "config.h"

extern BTHome bthome;

void initHome();
void updateHome(bool force = false);

#endif // HOME_H