/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"
#include "action_tapping.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl+|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;^ |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift+|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl+| Alt  | Gui  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,        KC_Q,           KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,\
  CTL_T(KC_ESC), KC_A,           KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    LT(_NAV, KC_SCLN), KC_QUOT, \
  KC_LSFT,       KC_Z,           KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT), \
  TT(_ADJUST),   LCTL_T(KC_DEL), KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      | PrtSc|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,  \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    _______,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,   KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD,   KC_VOLU, KC_MPLY \
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |WhlUp | MUp  |WhlDn |      |      | Home | PgUp | PgBck| PgFwd|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MLeft |MDown |MRight|      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | End  | PgDn |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |MAccl1| Left Click  |RtClck| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP( \
  _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,   KC_NO,   KC_HOME, KC_PGUP, KC_WBAK, KC_WFWD, KC_NO,   _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_END,  KC_PGDN, KC_WFWD, KC_NO,   KC_NO,   _______, \
  _______, _______, _______, _______, KC_ACL1, KC_BTN1, KC_BTN1, KC_BTN2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Sleep|      |      |      |      |NmLock|   7  |   8  |   9  |   -  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |Aud on|Audoff|      |   /  |   4  |   5  |   6  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Next | Vol- | Vol+ | Play |      |   *  |   1  |   2  |   3  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mute |      |      |      |      |Space |   0  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
    RESET,   KC_SLEP, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_DEL, \
    KC_CAPS, KC_NO,   KC_NO,   AU_ON,   AU_OFF,  KC_NO,  KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_BSPC, \
    _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO,  KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_PENT, \
    _______, KC_MUTE, _______, _______, _______, KC_SPC, KC_SPC , KC_P0,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
)

};