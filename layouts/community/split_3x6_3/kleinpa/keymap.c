#include QMK_KEYBOARD_H

// Layers
enum { _BASE = 0, _LL, _LL1, _LR };

// Set default base layer
#define B_ALPHA DF(_BASE)

// Momentary layer
#define M_LR MO(_LR)
#define M_LLR MO(_LLR)

// Tap Dance declarations
uint16_t dance_left_layers[] = {_LL, _LL1};

void dance_left_layer_cycle(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count - 1 < (sizeof(dance_left_layers) / sizeof(dance_left_layers[0]))) {
        layer_move(dance_left_layers[state->count - 1]);
    }
}
void dance_left_layer_reset(qk_tap_dance_state_t *state, void *user_data) { layer_clear(); }
enum {
    TD_LEFT_LAYER_CYCLE,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT_LAYER_CYCLE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_left_layer_cycle, NULL, dance_left_layer_reset),
};
#define TD_LL TD(TD_LEFT_LAYER_CYCLE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
[_BASE] = LAYOUT_split_3x6_3( /* base alpha layer */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, TD_LL,    KC_SPC,  KC_ENT,  M_LR,    KC_LGUI
),
[_LL] = LAYOUT_split_3x6_3( /* numbers and most symbols */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC,
    KC_DOT,  KC_ASTR, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_CIRC, KC_AMPR, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
),
[_LR] = LAYOUT_split_3x6_3( /* navigation and f-keys */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_APP,  KC_GRV,  KC_TILD, KC_PIPE, KC_BSLS, KC_DEL,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    _______, KC_PSCR, KC_SLCK, KC_INS,  KC_F11,  KC_F12,  KC_PAUS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                               _______, _______,  _______, KC_DEL,  _______, _______
),
[_LL1] = LAYOUT_split_3x6_3( /* left-hand nav and media */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT, KC_BSPC, _______, _______, _______, _______, _______, RESET,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
),
    /* clang-format on */
};
