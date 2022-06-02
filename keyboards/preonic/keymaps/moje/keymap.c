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
#include <wait.h>

#define XXXXXXX KC_NO

enum {
  TD_LSHIFT_CAPS = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

enum Layers
{
BASE,
UP,
DOWN,
SPACE,
UP_DOWN
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
};
#endif

#define SPACE_FN LT(SPACE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_preonic_1x2uC(
        KC_ESC,              KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,     KC_8,    KC_9,   KC_0,    KC_BSPC, \
        KC_MEDIA_PLAY_PAUSE, KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,   KC_P,    RALT(KC_QUOT),
        KC_TAB,              KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        TD(TD_LSHIFT_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
        KC_LCTL,             KC_LGUI, KC_LGUI, KC_LALT, MO(UP),   SPACE_FN,    MO(DOWN), KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT
    ),

    [UP] = LAYOUT_preonic_1x2uC(
        KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQUAL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

    [DOWN] = LAYOUT_preonic_1x2uC(
        KC_GRV,  _______,    RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),    RALT(KC_0), KC_DEL,
        _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       RALT(KC_9),    RALT(KC_0), S(KC_EQUAL),
        _______, RALT(KC_A), S(KC_LBRC), RALT(KC_F), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_RBRC), RALT(KC_BSLS), KC_LBRC,    KC_MINUS,
        _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_B), RALT(KC_N), XXXXXXX,    RALT(KC_COMM), RALT(KC_DOT),  XXXXXXX,    _______,
        _______, _______,    _______,    _______,    _______,           _______,         _______,    KC_HOME,       KC_PGUP,       KC_PGDN,    KC_END
    ),

    [SPACE] = LAYOUT_preonic_1x2uC(
        _______, _______,    _______,    _______,     _______, _______, _______, _______, _______,  _______,     _______,   _______, \
        KC_PSCR, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX,
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX,
        _______, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   _______,
        RESET,   MU_TOG,     CK_TOGG,    XXXXXXX,     XXXXXXX,      _______,     XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX
    ),

    [UP_DOWN] = LAYOUT_preonic_1x2uC(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
        KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, _______,      _______,     _______, _______, CK_UP, CK_DOWN, _______
    )
};

static bool is_layer_up_pressed = false;
static bool is_layer_down_pressed = false;
static bool layer4_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == MO(1))
  {is_layer_down_pressed = record->event.pressed;}

  if (keycode == MO(2))
    {is_layer_up_pressed = record->event.pressed;}

  if (is_layer_down_pressed && is_layer_up_pressed)
  {
    if (!layer4_on)
    {
      layer4_on = true;
      layer_move(UP_DOWN);
    }
  }
  else if (layer4_on)
  {
    layer4_on = false;
    layer_move(BASE);
  }

    return true;
}

    }
}

//bool encoder_update_user(uint8_t index, bool clockwise) {
//    if (IS_LAYER_ON(1))
//    {
//         if (clockwise) {
//            tap_code(KC_MS_WH_UP);
//        } else {
//            tap_code(KC_MS_WH_DOWN);
//        }
//    }
//    else if (IS_LAYER_ON(2))
//    {
//         if (clockwise) {
//            tap_code(KC_MS_UP);
//        } else {
//            tap_code(KC_MS_DOWN);
//        }
//    }else {
//        if (clockwise) {
//            tap_code(KC__VOLUP);
//        } else {
//            tap_code(KC__VOLDOWN);
//        }
//    }
//
//    return false;
//}

float tone_caps_on[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);

void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

     wait_ms(10);
    //_delay_ms(10); // gets rid of tick

    if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
    {
        PLAY_SONG(tone_caps_on);
    }
    else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK)))
    {
        PLAY_SONG(tone_caps_off);
    }

    old_usb_led = usb_led;
}

// void dip_switch_update_user(uint8_t index, bool active) {
   // switch (index) {
   //     case 0:
   //         if (active) {
   //             layer_on(_ADJUST);
   //         } else {
   //             layer_off(_ADJUST);
   //         }
   //         break;
   //     case 1:
   //         if (active) {
   //             muse_mode = true;
   //         } else {
   //             muse_mode = false;
   //         }
   // }
//}


//void matrix_scan_user(void) {
//#ifdef AUDIO_ENABLE
//    if (muse_mode) {
//        if (muse_counter == 0) {
//            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//            if (muse_note != last_muse_note) {
//                stop_note(compute_freq_for_midi_note(last_muse_note));
//                play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                last_muse_note = muse_note;
//            }
//        }
//        muse_counter = (muse_counter + 1) % muse_tempo;
//    } else {
//        if (muse_counter) {
//            stop_all_notes();
//            muse_counter = 0;
//        }
//    }
//#endif
//}

// bool music_mask_user(uint16_t keycode) {
 // switch (keycode) {
 //   case RAISE:
 //   case LOWER:
 //     return false;
 //   default:
 //     return true;
 // }
//}
