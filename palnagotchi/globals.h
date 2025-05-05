#ifndef PALNAGOTCHI_GLOBALS_H
#define PALNAGOTCHI_GLOBALS_H

#include "config.h"

#include <Arduino.h>

// Global variable declaration
extern unsigned long lastDetection = 0;

// ASCII mood faces
const String homeygotchi_moods[] = {
    "(v_v)",  // 0 - sleeping
    "(=_=)",  // 1 - awakening
    "(O_O)",  // 2 - awake
    "(o_O)",  // 3 - observing (neutral) right
    "(O_o)",  // 4 - observing (neutral) left
    "(o_0)",  // 5 - observing (happy) right
    "(0_o)",  // 6 - observing (happy) left
    "(+_+)",  // 7 - intense
    "(@_@)",  // 8 - cool
    "(0_0)",  // 9 - happy
    "(^_^)",  // 10 - grateful
    "(a_a)",  // 11 - excited
    "(+_+)",  // 12 - smart
    "(*_*)",  // 13 - friendly
    "(@_@)",  // 14 - motivated
    "(>_<)",  // 15 - demotivated
    "(-_-)",  // 16 - bored
    "(T_T)",  // 17 - sad
    "(;_;)",  // 18 - lonely
    "(X_X)",  // 19 - broken
    "(#_#)",  // 20 - debugging
    "8=D"     // 21 - ultra random easter egg
};

// Mood descriptions
const String homeygotchi_moods_desc[] = {
    "Zzzz...",              // 0 - sleeping
    "...",                  // 1 - awakening
    "Let's MAKE FRIENDS!",  // 2 - awake
    "Anybody here?",        // 3 - observing (neutral) right
    "WANTED: FRIENDS",      // 4 - observing (neutral) left
    "Looking around...",    // 5 - observing (happy) right
    "Hello, friend?",       // 6 - observing (happy) left
    "YEAH! pwnagotchis!",   // 7 - intense
    "Coolest pal around",   // 8 - cool
    "More friends!!!",      // 9 - happy
    "<3 PWNAGOTCHIS!",      // 10 - grateful
    "I like it.",           // 11 - excited
    "3.14159",              // 12 - smart
    "HEY YOU!",             // 13 - friendly
    "IT RUNS!",             // 14 - motivated
    "WHY???",               // 15 - demotivated
    "Seriously?",           // 16 - bored
    "hands off!!!",         // 17 - sad
    "pwnagotchis? where?",  // 18 - lonely
    "Works on my end.",     // 19 - broken
    "Wtf?",                 // 20 - debugging
    "What?"                 // 21 - ultra random easter egg
};

// Unicode mood faces
const String pwnagotchi_moods[] = {
    "(⇀‿‿↼)",  // 0 - sleeping
    "(≖‿‿≖)",  // 1 - awakening
    "(◕‿‿◕)",  // 2 - awake
    "( ⚆_⚆)",  // 3 - observing (neutral) right
    "(☉_☉ )",  // 4 - observing (neutral) left
    "( ◕‿◕)",  // 5 - observing (happy) right
    "(◕‿◕ )",  // 6 - observing (happy) left
    "(°▃▃°)",  // 7 - intense
    "(⌐■_■)",  // 8 - cool
    "(•‿‿•)",  // 9 - happy
    "(^‿‿^)",  // 10 - grateful
    "(ᵔ◡◡ᵔ)",  // 11 - excited
    "(✜‿‿✜)",  // 12 - smart
    "(♥‿‿♥)",  // 13 - friendly
    "(☼‿‿☼)",  // 14 - motivated
    "(≖__≖)",  // 15 - demotivated
    "(-__-)",  // 16 - bored
    "(╥☁╥ )",  // 17 - sad
    "(ب__ب)",  // 18 - lonely
    "(☓‿‿☓)",  // 19 - broken
    "(#__#)"   // 20 - debugging
};

// Content arrays
const String pwnagotchi_spam_faces[] = {
    "NOPWND!\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"
    "(STOP)",
    "(.)(.)",
    "Ⴚ(●ტ●)Ⴢ",
    "ᗧ(｡◝‿◜｡)ᗤ",
    "(‿ˠ‿)",
    "@(･ェ･)@",
    "(X‿‿X)",
    "(u W u)",
    "(EVIL)",
    "(.)(.)",
    "ლ(o_oლ)",
    "(O﹏o)",
    "(✖╭╮✖)",
    "SKIDZ!",
    "(ɹoɹɹƎ)",
    "(H4cK)",
    "┌∩┐(◣_◢)┌∩┐",
    "(╯°□°)╯╭╮(XoX)"
};

const String pwnagotchi_spam_names[] = {
    "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"
    "Security Alert",
    "System Warning",
    "Critical Error",
    "Reboot Required",
    "System Breached oups",
    "Unauthorized Access",
    "Security  Compromised.. reboot",
    "DON'T BE A SKID",
    "STOP DEAUTH SKIDZ!",
    "Critical Error need reboot",
    "No more Battery",
    "Check Evil-M5Project",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you"
};

const char ssids[] PROGMEM = {
    "Mom Use This One\n"
    "Abraham Linksys\n"
    "Benjamin FrankLAN\n"
    "Martin Router King\n"
    "John Wilkes Bluetooth\n"
    "Pretty Fly for a Wi-Fi\n"
    "Bill Wi the Science Fi\n"
    "I Believe Wi Can Fi\n"
    "Tell My Wi-Fi Love Her\n"
    "No More Mister Wi-Fi\n"
    "LAN Solo\n"
    "The LAN Before Time\n"
    "Silence of the LANs\n"
    "House LANister\n"
    "Winternet Is Coming\n"
    "Ping's Landing\n"
    "The Ping in the North\n"
    "This LAN Is My LAN\n"
    "Get Off My LAN\n"
    "The Promised LAN\n"
    "The LAN Down Under\n"
    "FBI Surveillance Van 4\n"
    "Area 51 Test Site\n"
    "Drive-By Wi-Fi\n"
    "Planet Express\n"
    "Wu Tang LAN\n"
    "Darude LANstorm\n"
    "Never Gonna Give You Up\n"
    "Hide Yo Kids, Hide Yo Wi-Fi\n"
    "Loading...\n"
    "Searching...\n"
    "VIRUS.EXE\n"
    "Virus-Infected Wi-Fi\n"
    "Starbucks Wi-Fi\n"
    "Yell 'Leeroy Jenkins' for Password\n"
    "The Password Is 1234\n"
    "Free Public Wi-Fi\n"
    "No Free Wi-Fi Here\n"
    "Get Your Own Damn Wi-Fi\n"
    "It Hurts When IP\n"
    "Dora the Internet Explorer\n"
    "404 Wi-Fi Unavailable\n"
    "Porque-Fi\n"
    "Titanic Syncing\n"
    "Test Wi-Fi Please Ignore\n"
    "Drop It Like It's Hotspot\n"
    "Life in the Fast LAN\n"
    "The Creep Next Door\n"
    "Ye Olde Internet\n"
};

#endif // PALNAGOTCHI_GLOBALS_H
