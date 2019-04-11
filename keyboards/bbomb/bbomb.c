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
#include "rgblight.h"
#include <print.h>

void matrix_init_user(void) {
	debug_enable=true;
	debug_matrix=true;
	rgblight_enable_noeeprom();
	rgblight_setrgb(64,0,0);
	print("hello");
	dprint("hello");
}

void keyboard_post_init_user(void) {
	debug_enable=true;
	debug_matrix=true;
	rgblight_enable_noeeprom();
	rgblight_setrgb(64,0,0);
	print("hello");
	dprint("hello");
}


