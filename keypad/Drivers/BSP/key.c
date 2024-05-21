#include "Key.h"
#include <stdbool.h>

// Default constructor
void Key_init(Key *key) {
    key->kchar = NO_KEY;
    key->kstate = IDLE;
    key->stateChanged = false;
}

// Constructor
void Key_initChar(Key *key, char userKeyChar) {
    key->kchar = userKeyChar;
    key->kcode = -1;
    key->kstate = IDLE;
    key->stateChanged = false;
}

void Key_keyUpdate(Key *key, char kchar, KeyState kstate, bool stateChanged) {
    key->kchar = kchar;
    key->kstate = kstate;
    key->stateChanged = stateChanged;
}
