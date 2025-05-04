#ifndef PALNAGOTCHI_UI_H
#define PALNAGOTCHI_UI_H

#include "mood.h"
#include "pwngrid.h"

class UI {
public:
    static void init();
    static void wakeUp();
    static void drawMood(String face, String phrase, bool broken = false);
    static void drawBottomCanvas(uint8_t friends_run = 0, uint8_t friends_tot = 0,
                     String last_friend_name = "", signed int rssi = -1000);
    static void drawNearbyMenu();
    static void update(bool show_toolbars = false);
    static bool toggleMenuBtnPressed();
    static String getRssiBars(signed int rssi);
private:
    // Static member variable declarations
    static M5Canvas canvas_top;
    static M5Canvas canvas;
    static M5Canvas canvas_bot;

    static int32_t display_w;
    static int32_t display_h;
    static int32_t canvas_h;
    static int32_t canvas_center_x;
    static int32_t canvas_top_h;
    static int32_t canvas_bot_h;

    static bool menu_open;
};

#endif // PALNAGOTCHI_UI_H
