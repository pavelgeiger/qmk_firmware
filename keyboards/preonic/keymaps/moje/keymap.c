/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum {
  TD_LSHIFT_CAPS = 0
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_LSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

enum layers {
    BASE,
    UP,
    DOWN,
    SPACE
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [UP] = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [DOWN] = { ENCODER_CCW_CW(KC_HOME, KC_END)},
    [SPACE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}
};
#endif

#define SPACE_FN LT(SPACE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[BASE] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_MPLY, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,      KC_U,     KC_I,    KC_O,    KC_P,    RALT(KC_QUOT),
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,      KC_J,     KC_K,    KC_L,    KC_SCLN, KC_MINUS,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,      KC_M,     KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
  KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, MO(UP),  SPACE_FN, SPACE_FN,  MO(DOWN), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[UP] = LAYOUT_preonic_grid(
  KC_TILD, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX, KC_INS,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX, KC_EQUAL,
  _______, RALT(KC_A), S(KC_LBRC), RALT(KC_F), RALT(KC_9), RALT(KC_B), RALT(KC_N), RALT(KC_0), RALT(KC_RBRC), RALT(KC_BSLS), KC_LBRC, XXXXXXX,
  _______, KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,         KC_F10,        KC_F11,  KC_F12,
  _______, _______,    _______,    _______,    _______,      _______,  _______,    _______,    _______,       _______,       _______,   _______
),

[DOWN] = LAYOUT_preonic_grid(
  KC_GRV,  RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),   RALT(KC_0), KC_DEL,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,    XXXXXXX,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,         KC_RGHT,      XXXXXXX,    XXXXXXX,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_COMM), RALT(KC_DOT), XXXXXXX,    _______,
  _______, _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______,   _______
),

[SPACE] = LAYOUT_preonic_grid(
  UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, MS_BTN1, MS_UP,   MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_SLSH:
        case KC_LSFT:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

