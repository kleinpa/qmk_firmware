#include QMK_KEYBOARD_H

enum planck_layers {
    _BASE = 0,
    _LL,
    _LL1,
    _LR,
#ifdef MIDI_ENABLE
    _MIDI_CHROMATIC,
    _MIDI_MAJOR,
#endif
};

// Set default base layer
#define B_ALPHA DF(_BASE)

#ifdef MIDI_ENABLE
#    define B_MI_CR DF(_MIDI_CHROMATIC)
#    define B_MI_MJ DF(_MIDI_MAJOR)
#else
#    define B_MI_CR KC_NO
#    define B_MI_MJ KC_NO
#endif

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
[_BASE] = LAYOUT_ortho_4x12(
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, _______, KC_LALT, TD_LL,   KC_SPC,  KC_ENT,  M_LR,    KC_LGUI, _______, _______, _______
),
[_LL] = LAYOUT_ortho_4x12( /* numbers and most symbols */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC,
    KC_DOT,  KC_ASTR, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_CIRC, KC_AMPR, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_LR] = LAYOUT_ortho_4x12( /* navigation and f-keys */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_APP,  KC_GRV,  KC_TILD, KC_PIPE, KC_BSLS, KC_DEL,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    _______, KC_PSCR, KC_SLCK, KC_INS,  KC_F11,  KC_F12,  KC_PAUS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______,  _______, KC_DEL,  _______, _______, _______, _______, _______
),
[_LL1] = LAYOUT_ortho_4x12( /* left-hand nav and media */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT, KC_BSPC, _______, _______, _______, _______, _______, RESET,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
#ifdef MIDI_ENABLE
[_MIDI_MAJOR] = LAYOUT_ortho_4x12(
/* white-key notes arranged increasing from bottom to top then from left to right */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    MI_E,    MI_A,    MI_D_1,  MI_G_1,  MI_C_2,  MI_F_2,  MI_B_2,  MI_E_3,  MI_A_3,  MI_D_4,  MI_G_4,  MI_C_4,
    MI_D,    MI_G,    MI_C_1,  MI_F_1,  MI_B_1,  MI_E_2,  MI_A_2,  MI_D_3,  MI_G_3,  MI_C_4,  MI_F_4,  MI_B_4,
    MI_C,    MI_F,    MI_B,    MI_E_1,  MI_A_1,  MI_D_2,  MI_G_2,  MI_C_3,  MI_F_3,  MI_B_3,  MI_E_4,  MI_A_4,
    MI_OCT_0,MI_OCT_1,MI_OCT_2,MI_OCT_3,_______, MI_C,    MI_C,    _______, MI_CH1,  MI_CH2,  MI_CH3,  MI_CH10
),
[_MIDI_CHROMATIC] = LAYOUT_ortho_4x12(
/* cello inspired layout with rows in fifths and chromatic columns */
/* |        |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |        | */
    MI_D_1,  MI_Ds_1, MI_E_1,  MI_F_1,  MI_Fs_1, MI_G_1,  MI_Gs_1, MI_A_1,  MI_As_1, MI_B_1,  MI_C_2,  MI_Cs_2,
    MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,    MI_C_1,  MI_Cs_1, MI_D_1,  MI_Ds_1, MI_E_1,  MI_F_1,  MI_Fs_1,
    MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
    MI_OCT_1,MI_OCT_2,MI_OCT_3,MI_OCT_4,_______, MI_C,    MI_C,    _______, MI_CH1,  MI_CH2,  MI_CH3,  MI_CH10
),
#endif
    /* clang-format on */
};

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_noeeprom(0x00, 0x00, 0x00);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_enable_noeeprom();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state | default_layer_state)) {
        case _LL1:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
#    ifdef MIDI_ENABLE
        case _MIDI_CHROMATIC:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _MIDI_MAJOR:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
#    endif
        default:
            rgblight_sethsv_noeeprom(0, 0, 0);
            break;
    }
#endif
    return state;
}
