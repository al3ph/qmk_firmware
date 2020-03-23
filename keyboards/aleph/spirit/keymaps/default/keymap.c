/* Copyright 2019 aleph
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
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  // DYNAMIC_MACRO_RANGE,
};
// #include "dynamic_macro.h"
enum layer_number {
  _QWERTY = 0,
  _FN,
  _KEYB,
  _ADMIN,
  _MISC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, 
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSPO, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, 
    KC_LCTL, KC_LGUI, KC_LALT, KC_MUTE, KC_SPC, KC_RALT, MO(_FN), KC_APP, KC_RCTL
  ),
  [_FN] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, 
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_HOME, KC_PGUP, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, MO(_KEYB), KC_TRNS, MO(_ADMIN), MO(_MISC)
  ),
  [_KEYB] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_RMOD, RGB_SPI, RGB_SPD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS,
    AU_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    CK_TOGG, KC_TRNS, KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    MU_ON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    MU_MOD, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_ADMIN] = LAYOUT(
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    MAGIC_TOGGLE_NKRO, KC_TRNS, KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_MISC] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
  // [1] = LAYOUT(RESET, KC_PWR, KC_SLEP, KC_WAKE, KC_NO, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DM_RSTP, RGB_HUI, RGB_SAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUD, RGB_SAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAI, AU_TOG, KC_NO, KC_NO, KC_NO, CK_TOGG, KC_TRNS, MU_ON, MU_MOD, KC_NO, RGB_VAD, KC_NO)
};

float my_song[][2] = SONG(QWERTY_SOUND);
float bye_song[][2] = SONG(GOODBYE_SOUND);   
void dynamic_macro_record_start_user(void) {
      PLAY_SONG(my_song);
}

void dynamic_macro_record_end_user(int8_t direction) {
    PLAY_SONG(bye_song);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (!process_record_dynamic_macro(keycode, record)) {
  //         return false;
  //     }
  switch (keycode) {
    case KC_PWR:
      PLAY_SONG(bye_song);
      break;

    case KC_SLEP:
      PLAY_SONG(bye_song);
      break;

    case RGB_TOG:
      PLAY_SONG(my_song);
      break;

    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

#define GLED E4
#define RLED E5
#define BLED E7
#define WLED E6

int LAYER_current_mode;

layer_state_t layer_state_set_user(layer_state_t state) {
    LAYER_current_mode = get_highest_layer(state);
    switch (get_highest_layer(state)) {
    case _FN:
      writePin(RLED, false);
      writePin(GLED, false);
      writePin(BLED, false);
      writePin(WLED, true);
      break;
    case _KEYB:
      writePin(RLED, true);
      writePin(GLED, false);
      writePin(BLED, false);
      writePin(WLED, false);
      break;
    case _ADMIN:
      writePin(RLED, false);
      writePin(GLED, true);
      writePin(BLED, false);
      writePin(WLED, false);
      break;
    case _MISC:
      writePin(RLED, false);
      writePin(GLED, false);
      writePin(BLED, true);
      writePin(WLED, false);
      break;
    // case _ADJUST:
    //   break;
    default: //  for any other layers, or the default layer
      writePin(RLED, false);
      writePin(GLED, false);
      writePin(BLED, false);
      writePin(WLED, false);
      break;
    }
  return state;
}


void oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);

    // switch (get_highest_layer(layer_state)) {
    //     case _QWERTY:
    //         oled_write_P(PSTR("Default\n"), false);
    //         break;
    //     case _FN:
    //         oled_write_P(PSTR("FN\n"), false);
    //         break;
    //     case _ADJ:
    //         oled_write_P(PSTR("ADJ\n"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("--- SPIRIT BOARD ---\n"), false);

    oled_write_P(LAYER_current_mode ==  _FN ? PSTR("FN  ") : PSTR("    "), false);
    oled_write_P(LAYER_current_mode ==  _KEYB ? PSTR("KEYB ") : PSTR("    "), false);
    oled_write_P(LAYER_current_mode ==  _ADMIN ? PSTR("ADMN ") : PSTR("    "), false);
    oled_write_P(LAYER_current_mode ==  _MISC ? PSTR("MISC   ") : PSTR("    "), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    switch(LAYER_current_mode) {
      case _FN:
        if (clockwise) 
          process_rgb(RGB_RMOD, NULL);
         else 
          process_rgb(RGB_MOD, NULL);
        break;
      case _KEYB:
        if (clockwise) 
          process_rgb(RGB_VAD, NULL);
         else 
          process_rgb(RGB_VAI, NULL);
        break;
      case _MISC:
        if (clockwise) 
          process_rgb(RGB_HUD, NULL);
         else 
          process_rgb(RGB_HUI, NULL);
        break;
    default: //  for any other layers, or the default layer
        if (clockwise) 
          tap_code(KC_VOLD);
         else 
          tap_code(KC_VOLU);
        break;

    }
  }
}
#endif