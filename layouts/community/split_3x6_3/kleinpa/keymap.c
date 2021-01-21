#include QMK_KEYBOARD_H

enum planck_layers { _ALPHA = 0, _L1, _L2, _L3 };

// Set default base layer
#define B_ALPHA DF(_ALPHA)

// Momentary layer
#define M_L1 MO(_L1)
#define M_L2 MO(_L2)
#define M_L3 MO(_L3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
[_ALPHA] = LAYOUT_split_3x6_3(
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, M_L1,    KC_SPC,  KC_ENT,  M_L2,    KC_LGUI
),
[_L1] = LAYOUT_split_3x6_3(
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC,
    _______, KC_SLSH, KC_ASTR, KC_PLUS, KC_MINS, KC_EQL,  KC_CIRC, KC_AMPR, _______, _______, KC_PIPE, _______,
                               _______, _______, _______, _______, M_L3,    _______
),
[_L2] = LAYOUT_split_3x6_3(
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_APP,  KC_GRV, KC_TILD, KC_VOLD,  KC_VOLU, KC_DEL,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
    _______, KC_PSCR, KC_SLCK, KC_INS,  KC_F11,  KC_F12,  KC_PAUS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                               _______, M_L3,    _______, KC_DEL,  _______, _______
),

[_L3] = LAYOUT_split_3x6_3(
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    RESET,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  _______, _______, _______, _______, _______, _______,
    _______, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_F23,  KC_F24,  _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
),
    /* clang-format on */
};
