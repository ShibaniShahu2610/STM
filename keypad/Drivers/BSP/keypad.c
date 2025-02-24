#include "keypad.h"
#include "stm32l0xx_hal.h" // Include the STM32 HAL library
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_rcc.h"

// Private function prototypes
static void Keypad_scanKeys(Keypad_HandleTypeDef *keypad);
static void Keypad_nextKeyState(Keypad_HandleTypeDef *keypad, uint8_t idx, uint8_t button);

void Keypad_init(Keypad_HandleTypeDef *keypad, char *userKeymap, GPIO_TypeDef* rowPorts[], GPIO_TypeDef* colPorts[], uint16_t rowPins[], uint16_t colPins[], uint8_t numRows, uint8_t numCols) {
    keypad->rowPorts = rowPorts;
    keypad->colPorts = colPorts;
    keypad->rowPins = rowPins;
    keypad->colPins = colPins;
    keypad->numRows = numRows;
    keypad->numCols = numCols;
    keypad->keymap = userKeymap;
    keypad->debounceTime = 10; // Default debounce time
    keypad->holdTime = 500; // Default hold time
    keypad->startTime = 0;
    keypad->single_key = false;
    keypad->keypadEventListener = NULL;
    memset(keypad->bitMap, 0, sizeof(keypad->bitMap));

    // Initialize GPIO pins for rows as input pull-up
    for (uint8_t r = 0; r < numRows; r++) {
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = rowPins[r];
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        HAL_GPIO_Init(rowPorts[r], &GPIO_InitStruct);
    }

    // Initialize GPIO pins for columns as output
    for (uint8_t c = 0; c < numCols; c++) {
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = colPins[c];
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(colPorts[c], &GPIO_InitStruct);
    }
}

void Keypad_scanKeys(Keypad_HandleTypeDef *keypad) {
    for (uint8_t r = 0; r < keypad->numRows; r++) {
        HAL_GPIO_WritePin(keypad->colPorts[r], keypad->colPins[r], GPIO_PIN_RESET); // Begin column pulse output.
        for (uint8_t c = 0; c < keypad->numCols; c++) {
            uint8_t button = HAL_GPIO_ReadPin(keypad->rowPorts[c], keypad->rowPins[c]); // Read button state
            if (button == GPIO_PIN_RESET) {
                keypad->bitMap[r] |= (1 << c); // Set the corresponding bit in the bitmap
            } else {
                keypad->bitMap[r] &= ~(1 << c); // Clear the corresponding bit in the bitmap
            }
        }
        HAL_GPIO_WritePin(keypad->colPorts[r], keypad->colPins[r], GPIO_PIN_SET); // End column pulse output.
    }
}

void Keypad_nextKeyState(Keypad_HandleTypeDef *keypad, uint8_t idx, uint8_t button) {
    switch (keypad->key[idx].kstate) {
        case IDLE:
            if (button == CLOSED) {
                keypad->key[idx].kstate = PRESSED;
                keypad->key[idx].startTime = HAL_GetTick(); // Get ready for next HOLD state.
            }
            break;
        case PRESSED:
            if ((HAL_GetTick() - keypad->key[idx].startTime) > keypad->holdTime) {
                keypad->key[idx].kstate = HOLD;
            } else if (button == OPEN) {
                keypad->key[idx].kstate = RELEASED;
            }
            break;
        case HOLD:
            if (button == OPEN) {
                keypad->key[idx].kstate = RELEASED;
            }
            break;
        case RELEASED:
            keypad->key[idx].kstate = IDLE;
            break;
    }
}

void Keypad_update(Keypad_HandleTypeDef *keypad) {
    // Scan keys
    Keypad_scanKeys(keypad);

    // Update key states
    for (uint8_t r = 0; r < keypad->numRows; r++) {
        for (uint8_t c = 0; c < keypad->numCols; c++) {
            uint8_t button = (keypad->bitMap[r] >> c) & 1; // Check the corresponding bit in the bitmap
            uint8_t keyIndex = r * keypad->numCols + c;
            if (keyIndex < MAX_KEYS) {
                if (keypad->keymap[keyIndex] != NO_KEY) {
                    Keypad_nextKeyState(keypad, keyIndex, button);
                }
            }
        }
    }

    // Handle keypad events
    if (keypad->keypadEventListener != NULL) {
        for (uint8_t i = 0; i < MAX_KEYS; i++) {
            if (keypad->key[i].kstate == PRESSED || keypad->key[i].kstate == HOLD) {
                keypad->keypadEventListener(keypad->keymap[i]);
            }
        }
    }
}

void Keypad_setDebounceTime(Keypad_HandleTypeDef *keypad, uint16_t debounce) {
    keypad->debounceTime = debounce;
}

void Keypad_setHoldTime(Keypad_HandleTypeDef *keypad, uint16_t hold) {
    keypad->holdTime = hold;
}

void Keypad_addEventListener(Keypad_HandleTypeDef *keypad, void (*listener)(char)) {
    keypad->keypadEventListener = listener;
}
