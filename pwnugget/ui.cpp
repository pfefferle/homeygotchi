#include "ui.h"

M5Canvas UI::canvas_top(&M5.Display);
M5Canvas UI::canvas(&M5.Display);
M5Canvas UI::canvas_bot(&M5.Display);

int32_t UI::display_w;
int32_t UI::display_h;
int32_t UI::canvas_h;
int32_t UI::canvas_center_x;
int32_t UI::canvas_top_h;
int32_t UI::canvas_bot_h;

bool UI::menu_open = false;

void UI::init() {
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
    canvas.createSprite(display_w, canvas_h);
}

bool UI::toggleMenuBtnPressed() {
    // Add a small delay to prevent multiple presses
    delay(100);
    return M5.BtnA.isPressed();
}

void UI::update(bool show_toolbars) {
    if (toggleMenuBtnPressed()) {
        menu_open = !menu_open;
    }

    uint8_t mood_id = Mood::getId();
    String mood_face = Mood::getFace();
    String mood_phrase = Mood::getPhrase();
    bool mood_broken = Mood::isBroken();

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
    canvas.pushSprite(0, canvas_top_h);
    M5.Display.endWrite();
}

String UI::getRssiBars(signed int rssi) {
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

void UI::drawBottomCanvas(uint8_t friends_run, uint8_t friends_tot,
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

void UI::drawNearbyMenu() {
    canvas.clear(BLACK);
    canvas.setTextSize(2);
    canvas.setTextColor(GREEN);
    canvas.setColor(GREEN);
    canvas.setTextDatum(top_left);

    pwngrid_peer* pwngrid_peers = getPwngridPeers();
    uint8_t len = getPwngridRunTotalPeers();

    if (len == 0) {
        canvas.setTextColor(TFT_DARKGRAY);
        canvas.setCursor(0, PADDING);
        canvas.println("No nearby Pwnagotchis. Seriously?");
    }

    char display_str[50] = "";
    for (uint8_t i = 0; i < len; i++) {
        int y = PADDING + (i * ROW_SIZE / 2);
        canvas.drawString(pwngrid_peers[i].name, 0, y);
    }
}

void UI::drawMood(String face, String phrase, bool broken) {
    if (broken == true) {
        canvas.setTextColor(RED);
    } else {
        canvas.setTextColor(GREEN);
    }

    canvas.setTextSize(4);
    canvas.setTextDatum(middle_center);
    canvas.fillSprite(BLACK);
    canvas.drawString(face, canvas_center_x, canvas_h / 2);
    canvas.setTextDatum(bottom_center);
    canvas.setTextSize(1);
    canvas.drawString(phrase, canvas_center_x, canvas_h - 23);
}
