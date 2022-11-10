#include QMK_KEYBOARD_H



#include "joystick.h"
#include "analog.h"


const uint16_t PROGMEM test_combo1[] = {JS_BUTTON0, JS_BUTTON2,JS_BUTTON13, JS_BUTTON16, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, RESET),
};


enum { _BASE = 0};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
[_BASE] = LAYOUT_numpad_5x4(
/* |        |        |        |        | */
    JS_BUTTON13, JS_BUTTON14, JS_BUTTON15, JS_BUTTON16,
    JS_BUTTON10, JS_BUTTON11,   JS_BUTTON12,
    JS_BUTTON6,  JS_BUTTON7,   JS_BUTTON8,   JS_BUTTON9,
    JS_BUTTON3,  JS_BUTTON4,   JS_BUTTON5,
    JS_BUTTON0,  JS_BUTTON1, JS_BUTTON2
),
    /* clang-format on */
};
