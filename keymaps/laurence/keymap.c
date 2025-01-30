// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _CANARY 0
#define _QWERTY 1
#define _NAVMEDIA 2
#define _NUMSYM 3

enum custom_keycodes {
  CANARY = SAFE_RANGE,
  QWERTY,
  NAVMEDIA,
  NUMSYM,
};

#define KC_QWRT QWERTY
#define KC_CNRY CANARY

// Left-hand home row mods
#define HOME_Z LGUI_T(KC_Z)
#define HOME_Q LGUI_T(KC_Q)
// #define HOME_A LGUI_T(KC_A)
// #define HOME_R LALT_T(KC_R)
// #define HOME_S LCTL_T(KC_S)
// #define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
// #define HOME_N RSFT_T(KC_N)
// #define HOME_E RCTL_T(KC_E)
// #define HOME_I LALT_T(KC_I)
// #define HOME_O RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_CANARY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                               KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                               KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    KC_COMM,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, HOME_Q,  KC_X,    KC_M,    KC_C,    KC_V,    KC_CAPS,          KC_DEL,  KC_K,    KC_P,    KC_DOT,  KC_MINUS,KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_ESC, LT(2,KC_RALT), KC_ENTER,              KC_SPC, LT(3,KC_BSPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, HOME_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS,          QK_BOOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_ESC, LT(2,KC_RALT), KC_ENTER,              KC_SPC, LT(3,KC_BSPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVMEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                            KC_PSCR, KC_SCRL, KC_INS,  _______, _______, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                            KC_SLSH, KC_7,    KC_8,    KC_9,    _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                            KC_PLUS, KC_4,    KC_5,    KC_6,    KC_0,    KC_COMM,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_LGUI, _______, _______, _______, KC_MUTE, KC_CNRY,          KC_QWRT, KC_MINS, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  _______, KC_ENTER,                  KC_SPC,  KC_BSPC, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMSYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC,                            KC_AT,   KC_AMPR, KC_ASTR, KC_9,    KC_0,    KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,                             KC_BSLS, KC_PLUS, KC_MINS, KC_SLSH, KC_DQUO, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH, KC_LGUI,          KC_F11,  KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  KC_RALT,  KC_ENTER,                 KC_SPC,  _______, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CANARY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CANARY);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
