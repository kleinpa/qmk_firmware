#include QMK_KEYBOARD_H

// Layers
enum { LAYER_BASE = 0, LAYER_L, LAYER_R, LAYER_LL, LAYER_RR };

// Set default base layer
#define B_ALPHA DF(LAYER_BASE)

// Momentary layer
#define M_L MO(LAYER_L)
#define M_R MO(LAYER_R)

// Tap Dance declarations
uint16_t dance_left_layers[] = {LAYER_L, LAYER_LL};
void dance_left_layer_cycle(tap_dance_state_t *state, void *user_data) {
    if (state->count - 1 < (sizeof(dance_left_layers) / sizeof(dance_left_layers[0]))) {
        layer_move(dance_left_layers[state->count - 1]);
    }
}
void dance_left_layer_reset(tap_dance_state_t *state, void *user_data) { layer_clear(); }

uint16_t dance_right_layers[] = {LAYER_R, LAYER_RR};
void dance_right_layer_cycle(tap_dance_state_t *state, void *user_data) {
    if (state->count - 1 < (sizeof(dance_right_layers) / sizeof(dance_right_layers[0]))) {
        layer_move(dance_right_layers[state->count - 1]);
    }
}
void dance_right_layer_reset(tap_dance_state_t *state, void *user_data) { layer_clear(); }
enum {
    TD_LEFT_LAYER_CYCLE,
    TD_RIGHT_LAYER_CYCLE,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT_LAYER_CYCLE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_left_layer_cycle, NULL, dance_left_layer_reset),
    [TD_RIGHT_LAYER_CYCLE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_right_layer_cycle, NULL, dance_right_layer_reset),
};
#define TD_LL TD(TD_LEFT_LAYER_CYCLE)
#define TD_RR TD(TD_RIGHT_LAYER_CYCLE)

// win-left/right to move windows around
#define WI_PRWI LGUI(KC_LEFT)
#define WI_NXWI LGUI(KC_RIGHT)

// win-control-left/right to change windows desktops
#define WI_PRDS LGUI(LCTL(KC_LEFT))
#define WI_NXDS LGUI(LCTL(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
[LAYER_BASE] = LAYOUT_split_3x6_3( /* base alpha layer */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, TD_LL,   KC_SPC,  KC_ENT,  TD_RR,   KC_LGUI
),
[LAYER_L] = LAYOUT_split_3x6_3( /* numbers and most symbols */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV, KC_TILD, KC_CIRC, KC_PIPE,  KC_BSLS, _______,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC,
    _______,  KC_ASTR, KC_PLUS, KC_MINS, KC_EQL,  KC_DOT,  KC_APP, KC_PAUS, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
),
[LAYER_R] = LAYOUT_split_3x6_3( /* navigation and f-keys */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_DEL,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_AMPR,
    _______, KC_PSCR, KC_SCRL, KC_INS,  KC_F11,  KC_F12,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                               _______, _______,  _______, KC_DEL,  _______, _______
),
[LAYER_LL] = LAYOUT_split_3x6_3( /* left-hand nav and media */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT, KC_BSPC, _______, _______, _______, _______, _______, QK_BOOT,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
),
[LAYER_RR] = LAYOUT_split_3x6_3( /* windows and desktop navigation */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, _______, _______, _______, _______, _______, _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______,
    _______, _______, _______, _______, _______, _______, WI_PRWI, KC_F17,  KC_F18,  KC_F19,  KC_F20,  WI_NXWI,
    _______, _______, _______, _______, _______, _______, WI_PRDS, KC_F21,  KC_F22,  KC_F23,  KC_F24,  WI_NXDS,
                               _______, _______, _______, _______, _______, _______
),
    /* clang-format on */
};
