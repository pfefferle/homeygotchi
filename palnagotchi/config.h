#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

const String homeygotchi_name = "HomeyGotchi";

// ASCII equivalent
const String palnagotchi_moods[] = {
  "(v_v)",  // 0 - sleeping
  "(=_=)",  // 1 - awakening
  "(O_O)",  // 2 - awake
  "(o_O)",  // 3 - observing (neutral) right
  "(O_o)",  // 4 - observig (neutral) left
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
  "(#_#)",  // 20 - debugging,
  "8=D",    // 21 - ultra random easter egg
};

const String palnagotchi_moods_desc[] = {
  "Zzzz...",              // 0 - sleeping
  "...",                  // 1 - awakening
  "Let's MAKE FRIENDS!",  // 2 - awake
  "Anybody here?",        // 3 - observing (neutral) right
  "WANTED: FRIENDS",      // 4 - observig (neutral) left
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
  "Wtf?",                 // 20 - debugging,
  "What?",                // 21 - ultra random easter egg
};

const String pwnagotchi_moods[] = {
  "(⇀‿‿↼)",  // 0 - sleeping
  "(≖‿‿≖)",  // 1 - awakening
  "(◕‿‿◕)",  // 2 - awake
  "( ⚆_⚆)",  // 3 - observing (neutral) right
  "(☉_☉ )",  // 4 - observig (neutral) left
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

#endif // CONFIG_H