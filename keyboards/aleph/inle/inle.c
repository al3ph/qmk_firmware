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
          /*    0    */ /*    1    */ /*    2    */ /*    3    */
/*  0 */ {   0,   0 }, {  75,   0 }, { 149,   0 }, { 224,   0 },
/*  1 */ {   0,  15 }, {  75,  15 }, { 149,  15 }, { 224,  15 },
/*  2 */ {   0,  27 }, {  75,  27 }, { 149,  27 }, { 224,  34 },
/*  3 */ {   0,  40 }, {  75,  40 }, { 149,  40 },
/*  4 */ {   0,  52 }, {  75,  52 }, { 149,  52 }, { 224,  58 },
/*  5 */ {  37,  64 }, { 149,  64 },
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

void suspend_power_down_kb(void)
{
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}


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
