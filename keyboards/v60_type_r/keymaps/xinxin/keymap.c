/* Copyright 2018 Christon DeWan (Xton)
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

#define _______ KC_TRNS
#define X_____X KC_NO

enum layers {
  _QWERTY,
  _FUN,
  _MOVE,
  _MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  X_____X, KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_BSLS, \
        LT(_MOVE, KC_CAPS),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
        KC_LSFT, X_____X,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, X_____X,  \
        KC_LCTL, KC_LALT, KC_LGUI,               LT(_MOUSE, KC_SPC),                          KC_RGUI, KC_APP,  KC_RCTL, MO(_FUN)),


    [_MOVE] = LAYOUT_all(
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X,
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, KC_HOME, KC_PGDN, KC_PGUP, KC_END, X_____X, X_____X, X_____X, X_____X,
        _______, X_____X, LGUI(KC_LBRC), LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), LGUI(KC_RBRC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, X_____X, X_____X, X_____X,
        _______, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, _______,
        _______,   _______,   _______,               _______,                                                      _______,   _______,  _______,  _______),


    [_FUN] = LAYOUT_all(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  X_____X, KC_DEL, \
	       X_____X,   X_____X,  KC_UP,    RGB_TOG,  RGB_RI,  RGB_GI,  RGB_BI,   X_____X, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    X_____X,          KC_INS, \
	       X_____X,   KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_RD,  RGB_GD,  RGB_BD,   X_____X, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          KC_ENT,          \
	       _______,   X_____X,  BL_INC,   BL_STEP,  BL_DEC,   X_____X,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN, _______, X_____X,  \
	       _______,   _______,  _______,            _______,                                                           _______,  _______, X_____X, _______
    ),

    [_MOUSE] = LAYOUT_all(
        X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X, \
        X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X, X_____X,   X_____X, X_____X, X_____X, X_____X,          X_____X, \
        X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, X_____X, X_____X,           KC_MS_BTN1,          \
        X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   X_____X,   KC_SPC, KC_MS_BTN1, KC_MS_BTN2, X_____X,  X_____X, X_____X,           X_____X,  KC_MS_BTN2,  \
        X_____X,   X_____X,   X_____X,               _______,                                                      X_____X,   X_____X,  X_____X,  X_____X
    )
};


void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRE  |=  (1<<PE6);
        PORTE &= ~(1<<PE6);
    }
    else {
        // Hi-Z
        DDRE  &= ~(1<<PE6);
        PORTE &= ~(1<<PE6);
    }
}

