/* Copyright 2015-2017 Jack Humbert
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
  TD_LSHIFT_CAPS = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

extern keymap_config_t keymap_config;

enum layers {
BASE,
UP,
DOWN,
SPACE,
UP_DOWN
};

#define SPACE_FN LT(SPACE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_planck_mit(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,     KC_K,    KC_L,   KC_SCLN, RALT(KC_QUOT),
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT ,
  KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, MO(UP),    SPACE_FN,      MO(DOWN), KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT
),

/* UP
 * ,-----------------------------------------------------------------------------------.
 * |   °  |   +  |   ě  |   š  |   č  |   ř  |   ž  |   ý  |   á  |   í  |   é  | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ´   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |   !  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | GUI  | Alt  |  Up  |    Space    |Down  | Home | PgUp |  PgDn|  End |
 * `-----------------------------------------------------------------------------------'
 */
[UP] = LAYOUT_planck_mit(
  KC_TILD, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_INS,
  XXXXXXX, S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    KC_MINUS,
  _______, KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
  _______, _______,    _______,    _______,           _______,         _______,    _______,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END
),

/* DOWN
 * ,-----------------------------------------------------------------------------------.
 * |   ;  |      |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   /  |   [  |      |      |      |      |   ]  |   \  |   ú  |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |   {  |   }  |      |   <  |   >  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | GUI  | Alt  |  Up  |    Space    |Down  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[DOWN] = LAYOUT_planck_mit(
  KC_GRV,  RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),    RALT(KC_0),  KC_DEL,
  XXXXXXX, RALT(KC_A), S(KC_LBRC), RALT(KC_F), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_RBRC), RALT(KC_BSLS), KC_LBRC,     KC_EQUAL,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_B), RALT(KC_N), XXXXXXX,    RALT(KC_COMM), RALT(KC_DOT),  XXXXXXX,     XXXXXXX,
  _______, _______,    _______,    _______,    _______,           _______,         _______,    KC__MUTE,      KC__VOLUP,     KC__VOLDOWN, XXXXXXX
),


[SPACE] = LAYOUT_planck_mit(
  KC_PSCR,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,   XXXXXXX,     XXXXXXX,
  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,   XXXXXXX,     XXXXXXX,
  QK_REBOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,   XXXXXXX,     KC_MEDIA_PLAY_PAUSE,
  QK_BOOT,   RGB_TOG, RGB_VAI, RGB_MOD, XXXXXXX,      _______,     XXXXXXX, KC_MEDIA_PREV_TRACK,  KC__VOLUP, KC__VOLDOWN, KC_MEDIA_NEXT_TRACK
)


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

//#ifdef AUDIO_ENABLE
//  float plover_song[][2]     = SONG(PLOVER_SOUND);
//  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
//#endif

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case QWERTY:
//      if (record->event.pressed) {
//        print("mode just switched to qwerty and this is a huge string\n");
//        set_single_persistent_default_layer(_QWERTY);
//      }
//      return false;
//      break;
//    case COLEMAK:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_COLEMAK);
//      }
//      return false;
//      break;
//    case DVORAK:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_DVORAK);
//      }
//      return false;
//      break;
//    case LOWER:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case RAISE:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case BACKLIT:
//      if (record->event.pressed) {
//        register_code(KC_RSFT);
//        #ifdef BACKLIGHT_ENABLE
//          backlight_step();
//        #endif
//      } else {
//        unregister_code(KC_RSFT);
//      }
//      return false;
//      break;
//    case PLOVER:
//      if (record->event.pressed) {
//        #ifdef AUDIO_ENABLE
//          stop_all_notes();
//          PLAY_SONG(plover_song);
//        #endif
//        layer_off(_RAISE);
//        layer_off(_LOWER);
//        layer_off(_ADJUST);
//        layer_on(_PLOVER);
//        if (!eeconfig_is_enabled()) {
//            eeconfig_init();
//        }
//        keymap_config.raw = eeconfig_read_keymap();
//        keymap_config.nkro = 1;
//        eeconfig_update_keymap(keymap_config.raw);
//      }
//      return false;
//      break;
//    case EXT_PLV:
//      if (record->event.pressed) {
//        #ifdef AUDIO_ENABLE
//          PLAY_SONG(plover_gb_song);
//        #endif
//        layer_off(_PLOVER);
//      }
//      return false;
//      break;
//  }
//  return true;
//}
