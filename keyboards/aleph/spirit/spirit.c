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
#include "spirit.h"
#include "quantum/rgb_matrix.h"
#define _NL NO_LED
#define _KL LED_FLAG_KEYLIGHT
#define _UL LED_FLAG_UNDERGLOW

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
/*          0     1     2     3      4     5     6     7     8     9     A     B     C     D */  \
/* 0 */ {   0,    1,    2,    3,     4,    5,    6,    7,    8,    9,   10,   11,   12,   13, }, \
/* 1 */ {  26,   25,   24,   23,    22,   21,   20,   19,   18,   17,   16,   15,   14,  _NL, }, \
/* 2 */ {  27,   28,   29,   30,    31,   32,   33,   34,   35,   36,   37,   38,   39,   40, }, \
/* 3 */ {  53,   52,   51,   50,    49,   48,   47,   46,   45,   44,   43,   42,   41,  _NL, }, \
/* 4 */ {  54,   55,   56,  _NL,   _NL,  _NL,   57,  _NL,  _NL,  _NL,   58,   59,   60,   61  }  \
  },
  {
     // #define RGB_MATRIX_CENTER { 112, 32 }
    // x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION = 13
    // y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION = 13
    // LED Index to Physical Position
  /*   */ {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 }, {  80,   0 }, {  96,   0 }, { 112,   0 }, { 128,   0 }, { 144,   0 }, { 160,   0 }, { 176,   0 }, { 192,   0 }, { 216,   0 },
  /*   */ { 222,  24 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, 
  /*   */ {   4,  16 }, {   6,  32 }, {  28,  32 }, {  44,  32 }, {  60,  32 }, {  76,  32 }, {  92,  32 }, { 108,  32 }, { 124,  32 }, { 140,  32 }, { 156,  32 }, { 172,  32 }, { 188,  32 }, { 204,  32 },
  /*   */ { 210,  48 }, { 180,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  36,  48 }, {  20,  48 }, {   2,  48 }, 
  /*   */ {   2,  64 }, {  22,  64 }, {  42,  64 }, { 102,  64 }, { 162,  64 }, { 182,  64 }, { 202,  64 }, { 222,  64 },
  /*   */           
  /*   */ need under leds
  },

   









  {
    // LED Index to Flag
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL,
    _KL,
    _UL, _UL, _UL, _UL, _UL, _UL, _UL, _UL,
    _UL, _UL, _UL, _UL, _UL, _UL, _UL, _UL
  }
};

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

// void suspend_power_down_kb(void)
// {
//     rgb_matrix_set_suspend_state(true);
//     rgb_matrix_set_color_all(0, 0, 0);
//     suspend_power_down_user();
// }

// void suspend_wakeup_init_kb(void)
// {
//     rgb_matrix_set_suspend_state(false);
//     suspend_wakeup_init_user();
// }


/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/
