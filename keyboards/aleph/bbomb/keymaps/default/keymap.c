/* Copyright 2019
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

enum custom_keycodes {
	QMKBBOMB=SAFE_RANGE,
	QMKSHRUG,
};

enum layers {
  _FN0 = 0,
  _FN1,
  _FN2,
  _FN3,
  _FN4,
  _FN5,
  _FN6,
  _FN7,
  _FN8,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_FN0] = LAYOUT(KC_7,KC_8,KC_9,KC_4,LT(8,KC_5),KC_6,KC_1,KC_2,KC_3),
  [_FN1] = LAYOUT(KC_HOME,KC_UP,KC_PGUP,KC_LEFT,LT(8,KC_ENT),KC_RGHT,KC_END,KC_DOWN,KC_PGDN),
  [_FN2] = LAYOUT(RGB_HUI,RGB_SAI,RGB_VAI,RGB_HUD,LT(8,RGB_SAD),RGB_VAD,RGB_SPI,KC_NO,RGB_SPD),
  [_FN3] = LAYOUT(RGB_TOG,RGB_MOD,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN4] = LAYOUT(QMKBBOMB,QMKSHRUG,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN5] = LAYOUT(KC_NO,KC_NO,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN6] = LAYOUT(KC_MPLY,KC_MNXT,KC_MPRV,KC_VOLU,LT(8,KC_MSTP),KC_VOLD,KC_NO,KC_NO,KC_NO),
  [_FN7] = LAYOUT(RESET,DEBUG,MAGIC_TOGGLE_NKRO,KC_NO,LT(8,KC_NO),KC_NO,KC_PWR,KC_SLEP,KC_WAKE),
  [_FN8] = LAYOUT(DF(5),DF(6),DF(7),DF(3),KC_TRNS,DF(4),DF(0),DF(1),DF(2)),
};

void matrix_init_user(void) {
	if(get_unicode_input_mode() != UC_LNX)
		set_unicode_input_mode(UC_LNX);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
	case QMKBBOMB:
		if(record->event.pressed)
			SEND_STRING("BBomb!!!");
		return false;
	break;
	case QMKSHRUG:
		if(record->event.pressed)
			send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
		return false;
	break;
	}
	return true;
}
