#include "ui.h"

M5Canvas canvas_top(&M5.Display);
M5Canvas canvas_main(&M5.Display);
M5Canvas canvas_bot(&M5.Display);

int32_t display_w;
int32_t display_h;
int32_t canvas_h;
int32_t canvas_center_x;
int32_t canvas_top_h;
int32_t canvas_bot_h;

bool menu_open = false;

void initUi() {
    M5.Display.setTextFont(&fonts::Font0);
    M5.Display.setTextSize(1);
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextColor(GREEN);
    M5.Display.setColor(GREEN);

    display_w = M5.Display.width();
    display_h = M5.Display.height();
    canvas_h = display_h * .8;
    canvas_center_x = display_w / 2;
    canvas_top_h = display_h * .1;
    canvas_bot_h = display_h * .1;

    canvas_top.createSprite(display_w, canvas_top_h);
    canvas_bot.createSprite(display_w, canvas_bot_h);
    canvas_main.createSprite(display_w, canvas_h);
}

bool toggleMenuBtnPressed() {
    // Add a small delay to prevent multiple presses
    delay(100);
    return M5.BtnA.isPressed();
}

void updateUi(bool show_toolbars) {
    if (toggleMenuBtnPressed()) {
        menu_open = !menu_open;
    }

    uint8_t mood_id = getCurrentMoodId();
    String mood_face = getCurrentMoodFace();
    String mood_phrase = getCurrentMoodPhrase();
    bool mood_broken = isCurrentMoodBroken();

    drawBottomCanvas(getPwngridRunTotalPeers(), getPwngridTotalPeers(),
                    getPwngridLastFriendName(), getPwngridClosestRssi());
    // If menu is open, return to main menu
    // If not, toggle menu
    if (menu_open) {
        drawNearbyMenu();
    } else {
        drawMood(mood_face, mood_phrase, mood_broken);
    }

    M5.Display.startWrite();
    if (show_toolbars) {
        canvas_top.pushSprite(0, 0);
        canvas_bot.pushSprite(0, canvas_top_h + canvas_h);
    }
    canvas_main.pushSprite(0, canvas_top_h);
    M5.Display.endWrite();
}

String getRssiBars(signed int rssi) {
    String rssi_bars = "";

    if (rssi != -1000) {
        if (rssi >= -67) {
            rssi_bars = "||||";
        } else if (rssi >= -70) {
            rssi_bars = "|||";
        } else if (rssi >= -80) {
            rssi_bars = "||";
        } else {
            rssi_bars = "|";
        }
    }

    return rssi_bars;
}

void drawBottomCanvas(uint8_t friends_run, uint8_t friends_tot,
                      String last_friend_name, signed int rssi) {
    canvas_bot.fillSprite(BLACK);
    canvas_bot.setTextSize(1);
    canvas_bot.setTextColor(GREEN);
    canvas_bot.setColor(GREEN);
    canvas_bot.setTextDatum(top_left);

    String rssi_bars = getRssiBars(rssi);
    char stats[25] = "FRND 0 (0)";
    if (friends_run > 0) {
        sprintf(stats, "FRND %d (%d) [%s] %s", friends_run, friends_tot,
                last_friend_name, rssi_bars);
    }

    canvas_bot.drawString(stats, 0, 5);
    canvas_bot.drawLine(0, 0, display_w, 0);
}

#define ROW_SIZE 40
#define PADDING 10

void drawNearbyMenu() {
    canvas_main.clear(BLACK);
    canvas_main.setTextSize(2);
    canvas_main.setTextColor(GREEN);
    canvas_main.setColor(GREEN);
    canvas_main.setTextDatum(top_left);

    pwngrid_peer* pwngrid_peers = getPwngridPeers();
    uint8_t len = getPwngridRunTotalPeers();

    if (len == 0) {
        canvas_main.setTextColor(TFT_DARKGRAY);
        canvas_main.setCursor(0, PADDING);
        canvas_main.println("No nearby Pwnagotchis. Seriously?");
    }

    char display_str[50] = "";
    for (uint8_t i = 0; i < len; i++) {
        int y = PADDING + (i * ROW_SIZE / 2);
        canvas_main.drawString(pwngrid_peers[i].name, 0, y);
    }
}

void drawMood(String face, String phrase, bool broken) {
    if (broken == true) {
        canvas_main.setTextColor(RED);
    } else {
        canvas_main.setTextColor(GREEN);
    }

    canvas_main.setTextSize(4);
    canvas_main.setTextDatum(middle_center);
    canvas_main.fillSprite(BLACK);
    canvas_main.drawString(face, canvas_center_x, canvas_h / 2);
    canvas_main.setTextDatum(bottom_center);
    canvas_main.setTextSize(1);
    canvas_main.drawString(phrase, canvas_center_x, canvas_h - 23);
}
