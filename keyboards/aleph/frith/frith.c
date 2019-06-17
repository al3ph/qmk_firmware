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
#include "frith.h"
#include "quantum/rgb_matrix.h"
#define _NL NO_LED
#define _KL LED_FLAG_KEYLIGHT
#define _UL LED_FLAG_UNDERGLOW

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
/*          0     1     2     3      4     5     6     7     8     9     A     B     C     D     E     F     G */  \
/* 0 */ {  21,  _NL,   20,   19,    18,   17,   16,   15,   14,   13,   12,   11,   10,    9,    6,    7,    8 }, \
/* 1 */ {  22,   23,   24,   25,    26,   27,   28,   29,   30,   31,   32,   33,   34,   35,    5,    4,    3 }, \
/* 2 */ {  48,   47,   46,   45,    44,   43,   42,   41,   40,   39,   38,   37,   36,  _NL,    0,    1,    2 }, \
/* 3 */ {  49,   50,   51,   52,    53,   54,   55,   56,   57,   58,   59,   60,   61,   62,  _NL,  _NL,  _NL }, \
/* 4 */ {  75,   74,   73,   72,    71,   70,   69,   68,   67,   66,   65,   64,   63,  _NL,  _NL,   87,  _NL }, \
/* 5 */ {  76,   77,   78,  _NL,   _NL,  _NL,   79,  _NL,  _NL,  _NL,   80,   81,   82,   83,   84,   85,   86 }  \
  },
  { 
    // #define RGB_MATRIX_CENTER { 112, 32 }
    // x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION = 13
    // y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION = 13
    // LED Index to Physical Position
  /*   0 */ { 195,  26 }, { 208,  26 }, { 221,  26 }, { 221,  13 }, { 208,  13 }, 
  /*   5 */ { 195,  13 }, { 195,   0 }, { 208,   0 }, { 221,   0 }, { 182,   0 }, 
  /*  10 */ { 169,   0 }, { 156,   0 }, { 143,   0 }, { 124,   0 }, { 111,   0 }, 
  /*  15 */ {  98,   0 }, {  85,   0 }, {  65,   0 }, {  52,   0 }, {  39,   0 }, 
  /*  20 */ {  26,   0 }, {   0,   0 }, {   0,  13 }, {  13,  13 }, {  26,  13 }, 
  /*  25 */ {  39,  13 }, {  52,  13 }, {  65,  13 }, {  78,  13 }, {  91,  13 }, 
  /*  30 */ { 104,  13 }, { 117,  13 }, { 130,  13 }, { 143,  13 }, { 156,  13 }, 
  /*  35 */ { 175,  13 }, { 159,  26 }, { 146,  26 }, { 133,  26 }, { 120,  26 }, 
  /*  40 */ { 107,  26 }, {  94,  26 }, {  81,  26 }, {  68,  26 }, {  55,  26 }, 
  /*  45 */ {  42,  26 }, {  29,  26 }, {  16,  26 }, {   3,  26 }, {   5,  39 }, 
  /*  50 */ {  18,  39 }, {  31,  39 }, {  44,  39 }, {  57,  39 }, {  70,  39 }, 
  /*  55 */ {  83,  39 }, {  96,  39 }, { 109,  39 }, { 122,  39 }, { 135,  39 }, 
  /*  60 */ { 148,  39 }, { 161,  39 }, { 174,  32 }, { 159,  52 }, { 146,  52 }, 
  /*  65 */ { 133,  52 }, { 120,  52 }, { 107,  52 }, {  94,  52 }, {  81,  52 }, 
  /*  70 */ {  68,  52 }, {  55,  52 }, {  42,  52 }, {  29,  52 }, {  16,  52 }, 
  /*  75 */ {   0,  52 }, {   0,  66 }, {  16,  66 }, {  36,  66 }, {  91,  66 }, 
  /*  80 */ { 130,  66 }, { 146,  66 }, { 163,  66 }, { 179,  66 }, { 195,  66 }, 
  /*  85 */ { 208,  66 }, { 221,  66 }, { 208,  52 }, {   0,   0 }, {   0,   0 }, 
  /*  90 */ {   0,   0 }, {   0,   0 }, {   0,   0 }, {   0,   0 }, {   0,   0 }, 
  /*  95 */ {   0,   0 }, {   0,   0 }, {   0,   0 }, {   0,   0 }, {   0,   0 }, 
  /* 100 */ {   0,   0 }, {   0,   0 }, {   0,   0 }, {   0,   0 }, 
  },
  {
    // LED Index to Flag
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _KL, _KL, _KL, _KL, _KL, _KL, _KL, _KL, 
    _UL, _UL, _UL, _UL, _UL, _UL, _UL, _UL, 
    _UL, _UL, _UL, _UL, _UL, _UL, _UL, _UL 
  }   
};

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

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
