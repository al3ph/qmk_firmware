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
  [_FN0] = LAYOUT_ortho_3x3(KC_P7,KC_P8,KC_P9,KC_P4,LT(8,KC_P5),KC_P6,KC_P1,KC_P2,KC_P3),
  [_FN1] = LAYOUT_ortho_3x3(RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,LT(8,RGB_TOG),RGB_M_SN,RGB_M_K,RGB_M_X,RGB_M_G),
  [_FN2] = LAYOUT_ortho_3x3(RGB_HUI,RGB_SAI,RGB_VAI,RGB_HUD,LT(8,RGB_SAD),RGB_VAD,RGB_SPI,KC_NO,RGB_SPD),
  [_FN3] = LAYOUT_ortho_3x3(KC_NO,KC_NO,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN4] = LAYOUT_ortho_3x3(KC_NO,KC_NO,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN5] = LAYOUT_ortho_3x3(KC_MPLY,KC_MNXT,KC_MPRV,KC_VOLU,LT(8,KC_MSTP),KC_VOLD,KC_NO,KC_NO,KC_NO),
  [_FN6] = LAYOUT_ortho_3x3(KC_NO,KC_NO,KC_NO,KC_NO,LT(8,KC_NO),KC_NO,KC_NO,KC_NO,KC_NO),
  [_FN7] = LAYOUT_ortho_3x3(RESET,DEBUG,MAGIC_TOGGLE_NKRO,KC_NO,LT(8,KC_NO),KC_NO,KC_PWR,KC_SLEP,KC_WAKE),
  [_FN8] = LAYOUT_ortho_3x3(TG(0),TG(1),TG(2),TG(3),KC_NO,TG(4),TG(5),TG(6),TG(7)),
};

