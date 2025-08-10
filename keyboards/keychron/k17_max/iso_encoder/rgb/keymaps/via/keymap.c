/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

// Definitions - stick to 8 chars or less to help with layout in the keymaps
#define RESET TO(MAC_BASE)
#define FN_CAPS LT(_FL, KC_CAPS)
#define ALT_TAB LALT(KC_TAB)

// Custom keycodes
enum keyboard_keycodes {
    TL_NAV = SAFE_RANGE,
    TL_MACRO,
    EMAIL_PE,
    EMAIL_WO,
};

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  MACRO,
  NAVIGATION,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [TEMPLATE] = LAYOUT_105_iso(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,            _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______         ),
    //
    [MAC_BASE] = LAYOUT_105_iso(
        KC_ESC,         KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,       RGB_MOD,  KC_DEL,   KC_F13,   KC_F14,   KC_F15,   KC_MUTE,
        KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,       KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                 KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_ESC,         KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,        KC_HOME,  KC_P4,    KC_P5,    KC_P6,
        OSM(MOD_LSFT),  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             OSM(MOD_RSFT), KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LGUI,        KC_LALT,  KC_LCTL,                                KC_SPC,                                 KC_RCTL,  KC_RGUI, TT(MAC_FN), KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,              KC_PDOT         ),

    [MAC_FN] = LAYOUT_105_iso(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  RGB_TOG,  TG(MACRO),  _______,  _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,  _______,
        TG(NAVIGATION),  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,    _______,    _______,                      _______,  _______,  _______,  _______,  _______,
        RESET,    RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,            KC_END,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______, RESET,        _______,  _______,  _______,  _______,            _______         ),

    [WIN_BASE] = LAYOUT_105_iso(
        KC_ESC,        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,    KC_PSCR, RGB_MOD,  KC_DEL,   _______,  _______,  _______,  KC_MUTE,
        KC_GRV,        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,    KC_BSPC, KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,            KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_ESC,        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,    KC_ENT, KC_HOME,  KC_P4,    KC_P5,    KC_P6,
        OSM(MOD_LSFT), KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,         OSM(MOD_RSFT), KC_UP,             KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LWIN,       KC_LALT,  KC_LCTL,                                KC_SPC,                                 KC_RCTL,  KC_RWIN,  OSL(WIN_FN), KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,              KC_PDOT         ),

    [WIN_FN] = LAYOUT_105_iso(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            KC_END,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,  _______,            _______         ),

    [MACRO] = LAYOUT_105_iso(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET  ,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
        _______,  _______,  EMAIL_WO,  EMAIL_PE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
        RESET  ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______, RESET,   _______,  _______,  _______,  _______,            _______         ),

    [NAVIGATION] = LAYOUT_105_iso(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
        RESET  ,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,   _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
        RESET  ,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RIGHT,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, LALT(KC_H),  LALT(KC_J), LALT(KC_K),  LALT(KC_L),   _______,            _______,  _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                 _______,  _______,  RESET,  _______,  _______,  _______,  _______,            _______         ),

};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]     = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]     = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MACRO]      = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [NAVIGATION] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};

// clang-format on
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ENTER:
      if (record->event.pressed) {
      }
      return true; // Let QMK send the enter press/release events

    case EMAIL_PE:
      if (record->event.pressed) {
        SEND_STRING("Personal email");
      }
      return true; // Let QMK send the enter press/release events

    case EMAIL_WO:
      if (record->event.pressed) {
        SEND_STRING("Work Email");
      }
      return true; // Let QMK send the enter press/release events

    case TL_MACRO:
      if (record->event.pressed) {
          layer_on(MACRO);
          SEND_STRING("Toggle Macro...");
      }
      return true; // Let QMK send the enter press/release events

    case TL_NAV:
      if (record->event.pressed) {
          layer_on(NAVIGATION);
          SEND_STRING("Toggle Navigation...");
      }
      return true; // Let QMK send the enter press/release events

    default:
      return true; // Process all other keycodes normally
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

