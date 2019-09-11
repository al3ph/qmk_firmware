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
  QMKURL
};

float my_song[][2] = SONG(QWERTY_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_ESC, KC_TAB, MO(1), KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_P7, KC_P8, KC_P9, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_P1, KC_P2, KC_P3, KC_P0, KC_PDOT, KC_PENT),
  [1] = LAYOUT(RGB_TOG, CK_TOGG, KC_TRNS, RESET, RGB_HUD, RGB_HUI, KC_PWR, EEP_RST, RGB_VAD, RGB_VAI, KC_SLEP, RGB_SPD, RGB_SPI, KC_NO, RGB_MOD, RGB_SAD, RGB_SAI, KC_NO, CK_TOGG, RESET, RGB_RMOD)
  // [0] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_P7, KC_P8, KC_P9, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_P1, KC_P2, KC_P3, KC_P0, KC_PDOT, KC_PENT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
