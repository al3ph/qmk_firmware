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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_FN0] = LAYOUT_ortho_3x3(
  KC_P7,KC_P8,KC_P9,KC_P4,KC_P5,KC_P6,LT(0,KC_P1),LT(1,KC_P2),LT(2,KC_P3)
  ),
  [_FN1] = LAYOUT_ortho_3x3(
  RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,RGB_M_SN,RGB_M_K,LT(0,RGB_M_X),LT(1,RGB_M_G),LT(2,RGB_TOG)
  ),
  [_FN2] = LAYOUT_ortho_3x3(
  RGB_HUI,RGB_SAI,RGB_VAI,RGB_HUD,RGB_SAD,RGB_VAD,LT(0,RGB_SPI),LT(1,RGB_SPD),LT(2,RESET)
  ),
};

