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
#include "bbomb.h"
// #include "rgblight.h"
#include "quantum/rgb_matrix.h"
#include <print.h>

led_config_t g_led_config = {
	{
  // Key Matrix to LED Index
  		{ 0, 1, 2, 3, 4, 5, 6, 7, 8 },
  	},
    {
	  // LED Index to Physical Position
  		{ 0,  0 }, { 112,  0 }, { 224,  0 },
  		{ 0,  32 }, { 112,  32 }, { 224,  32 },
  		{ 0,  64 }, { 112,  64 }, { 224,  64 }
	},
	{
		// LED Index to Flag
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
	} 	
};

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


// void matrix_init_user(void) {
// 	debug_enable=true;
// 	debug_matrix=true;
// 	rgblight_enable_noeeprom();
// 	rgblight_setrgb(64,0,0);
// 	print("hello");
// 	dprint("hello");
// }

// void keyboard_post_init_user(void) {
// 	debug_enable=true;
// 	debug_matrix=true;
// 	rgblight_enable_noeeprom();
// 	rgblight_setrgb(64,0,0);
// 	print("hello");
// 	dprint("hello");
// }


