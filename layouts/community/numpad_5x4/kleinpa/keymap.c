#include QMK_KEYBOARD_H

enum { _BASE = 0, _L1, _L2};

// Tap Dance declarations
uint16_t dance_layers[] = {_L1, _L2};
void     dance_layer_cycle(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count - 1 < (sizeof(dance_layers) / sizeof(dance_layers[0]))) {
        layer_move(dance_layers[state->count - 1]);
    }
}
void dance_layer_reset(qk_tap_dance_state_t *state, void *user_data) { layer_clear(); }
enum {
    TD_LAYER_CYCLE,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER_CYCLE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_layer_cycle, NULL, dance_layer_reset),
};
#define TD_LAYR TD(TD_LAYER_CYCLE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
[_BASE] = LAYOUT_numpad_5x4(
/* |        |        |        |        | */
    TD_LAYR, KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,
    KC_P0,            KC_PDOT, KC_PENT
),
[_L1] = LAYOUT_numpad_5x4(
/* |        |        |        |        | */
    _______, _______, KC_DEL,  KC_BSPC,
    KC_NLCK, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______,
    _______,          _______, _______
),
[_L2] = LAYOUT_numpad_5x4(
/* |        |        |        |        | */
    _______, _______, _______, RESET,
    _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______,
    _______,          _______, _______
),
    /* clang-format on */
};
