#ifndef KEYPAD_H
#define KEYPAD_H

#include "Key.h"
#include <stdbool.h>

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef INPUT
#define INPUT 0
#endif

#ifndef OUTPUT
#define OUTPUT 1
#endif

#ifndef INPUT_PULLUP
#define INPUT_PULLUP 2
#endif

#ifndef INPUT_PULLUP
#define INPUT_PULLUP 0x2
#endif

#define OPEN LOW
#define CLOSED HIGH

typedef char KeypadEvent;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef uint8_t byte;


typedef struct {
    byte rows;
    byte columns;
} KeypadSize;

#define LIST_MAX 10
#define MAPSIZE 10
#define MAX_KEYS 16  // Define MAX_KEYS as the maximum number of keys in your keypad


typedef struct {
//    GPIO_TypeDef** rowPorts;
//    GPIO_TypeDef** colPorts;
	uint32_t* rowPorts;
	uint32_t* colPorts;
    uint16_t* rowPins;
    uint16_t* colPins;
    uint8_t numRows;
    uint8_t numCols;
    char* keymap;
    uint8_t bitMap[MAX_KEYS / 8]; // Bitmap to store key states
    uint16_t debounceTime;
    uint16_t holdTime;
    uint32_t startTime;
    bool single_key;
    void (*keypadEventListener)(char);
    Key key[MAX_KEYS];
} Keypad_HandleTypeDef;

typedef struct {
    uint bitMap[MAPSIZE];
    Key key[LIST_MAX];
    ulong holdTimer;
    char *keymap;
    byte *rowPins;
    byte *columnPins;
    KeypadSize sizeKpd;
    uint debounceTime;
    uint holdTime;
    bool single_key;
    ulong startTime;
    void (*keypadEventListener)(char);
} Keypad;

void Keypad_begin(Keypad* keypad, char *userKeymap);
char Keypad_getKey(Keypad *keypad);
int Keypad_findInList(Keypad* keypad, char keyChar);
_Bool Keypad_updateList(Keypad* keypad);
bool Keypad_getKeys(Keypad *keypad);
KeyState Keypad_getState(Keypad *keypad);
void Keypad_setDebounceTime(Keypad_HandleTypeDef *keypad, uint16_t debounce);
void Keypad_setHoldTime(Keypad_HandleTypeDef *keypad, uint16_t hold);
void Keypad_addEventListener(Keypad_HandleTypeDef *keypad, void (*listener)(char));
bool Keypad_isPressed(Keypad *keypad, char keyChar);
char Keypad_waitForKey(Keypad *keypad);
bool Keypad_keyStateChanged(Keypad *keypad);
byte Keypad_numKeys(Keypad *keypad);

#endif
