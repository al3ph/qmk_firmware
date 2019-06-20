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
#include "inle.h"
#include "quantum/rgb_matrix.h"

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
      { 0,  1,  2,  3 },
      { 4,  5,  6,  7 },
      { 8,  9, 10, 11 },
      { 12, 13, 14, NO_LED },
      { 15, 16, 17, 18 },
      { 19, NO_LED, 20, NO_LED  },
  },
  {
    // LED Index to Physical Position
    {   0,   0 }, {  74,   0 }, { 149,   0 }, { 224,   0 },
    {   0,  15 }, {  74,  15 }, { 149,  15 }, { 224,  15 },
    {   0,  27 }, {  74,  27 }, { 149,  27 }, { 224,  33 },
    {   0,  39 }, {  74,  39 }, { 149,  39 },
    {   0,  51 }, {  74,  51 }, { 149,  51 }, { 224,  57 },
    {  37,  63 }, { 149,  63 }, 
    {   0,   0 }, { 224,   0 }, {   0,  64 }, { 224,  64 }
  },
  {
    // LED Index to Flag
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
    LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
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
