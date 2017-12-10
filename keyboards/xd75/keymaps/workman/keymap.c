/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _WM 0
#define _PROGRAMMER 1
#define _FN 2


// TAPDANCE

// Enums
// TD_CPX
// copy / paste / cut button
//
// TD_UNDO_CHMP
// cmd+z / select previous and delete / shift+cmd+z
enum {
 TD_CPX = 0,
 TD_UNDO_CHMP,
 TD_PGRM_ENT,
 TD_SPC_ENTER
};

void dance_cpx_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LGUI);
    register_code(KC_C);
  } else if (state->count == 2)  {
    register_code(KC_LGUI);
    register_code(KC_V);
  } else if (state->count == 3)  {
    register_code(KC_LGUI);
    register_code(KC_X);
  }
}

void dance_cpx_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LGUI);
    unregister_code(KC_C);
  } else if (state->count == 2) {
    unregister_code(KC_LGUI);
    unregister_code(KC_V);
  } else if (state->count == 3)  {
    unregister_code(KC_LGUI);
    unregister_code(KC_X);
  }
}

void dance_undo_cmp_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LGUI);
    register_code(KC_Z);
  } else if (state->count == 2) {
    register_code(KC_LSFT);
    register_code(KC_LALT);
    register_code(KC_LEFT);
    register_code(KC_BSPACE);
  } else if (state->count == 3) {
    register_code(KC_LSFT);
    register_code(KC_LGUI);
    register_code(KC_Z);
  }

}

void dance_undo_cmp_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LGUI);
    unregister_code(KC_Z);
  } else if (state->count == 2) {
    unregister_code(KC_BSPACE);
    unregister_code(KC_LSFT);
    unregister_code(KC_LALT);
    unregister_code(KC_LEFT);
  }
  else if (state->count == 3) {
    unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
    unregister_code(KC_Z);
  }
}

void dance_pgent_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LGUI);
    register_code(KC_RIGHT);
    register_code(KC_ENTER);
  } else if (state->count == 2) {
    SEND_STRING(SS_LCTRL("a")SS_LCTRL("k")SS_TAP(X_BSPACE));
  }

}
void dance_pgent_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LGUI);
    unregister_code(KC_RIGHT);
    unregister_code(KC_ENTER);
  } else if (state->count == 2) {


  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
//ACTION_TAP_DANCE_FN_ADVANCED(on_each_tap_fn, on_dance_finished_fn, on_dance_reset_fn)
 [TD_CPX] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cpx_finished, dance_cpx_reset),
 [TD_UNDO_CHMP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_undo_cmp_finished, dance_undo_cmp_reset),
 [TD_PGRM_ENT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_pgent_finished, dance_pgent_reset),
 [TD_SPC_ENTER]  = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_ENTER)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WORKMAN
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | L_FN   | L_PROG | HYPER  | 6      | 7      | 8      | 9      | 0      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | D      | R      | W      | B      | [      | \      | ]      | J      | F      | U      | P      | '      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKS  | A      | S      | H      | T      | G      | HOME   | DEL    | PG UP  | Y      | N      | E      | O      | I      |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LGUI   | Z      | X      | M      | C      | V      | END    | UP     | PG DN  | K      | L      | ,      | .      | /      | RGUI   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LSHFT  | LCTRL  | `      | \      |    -   | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RSHFT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_WM] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,             TG(_FN), TG(_PROGRAMMER), KC_KP_ASTERISK,   KC_6,             KC_7,             KC_8,    KC_9,    KC_0,    KC_MINS },
  { KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,     KC_B,             KC_LBRC, KC_BSLS,         KC_RBRC,          KC_J,             KC_F,             KC_U,    KC_P,    KC_QUOT, KC_EQUAL },
  { KC_BSPC, KC_A,    KC_S,    KC_H,    KC_T,     KC_G,             KC_HOME, KC_DEL,          KC_PGUP,          KC_Y,             KC_N,             KC_E,    KC_O,    KC_I,    KC_SCLN  },
  { KC_LGUI, KC_Z,    KC_X,    KC_M,    KC_C,     KC_V,             KC_END,  KC_UP,           KC_PGDN,          KC_K,             KC_L,             KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI },
  { KC_LSPO, KC_LCTL, KC_GRV,  KC_BSLS, KC_MINUS, TD(TD_SPC_ENTER), KC_LEFT, KC_DOWN,         KC_RGHT,          TD(TD_SPC_ENTER), TD(TD_SPC_ENTER), MO(_FN), KC_RALT, KC_RGUI, KC_R},
 },

/* PROGRAMMER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |   !    |   @    |   #    |   $    |   %    |        |        |        |   ^    |   &    |   *    |    (   |    )   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |  CLIP  |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        | C/P/X  |        |  LGUI[ |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |  U/CMP |        |  LGUI] |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_PROGRAMMER] = {
  { KC_TRNS, KC_EXLM, KC_AT,  LALT(KC_3), KC_DLR, KC_PERC, KC_TRNS,           KC_TRNS,       KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS, LGUI(KC_M),        KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS, TD(TD_CPX),        LGUI(KC_LBRC), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS, TD(TD_UNDO_CHMP),  LGUI(KC_RBRC), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS,           KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }, 
 },
/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | PR SCR |KC_ASRP | P7     | P8     | P9     | -      |        |RGB_VAI |RGB_SAI |RGB_HUI |RGB_SMOD|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | SCR LK |KC_ASUP | P4     | P5     | P6     | +      |        |RGB_VAD |RGB_SAD |RGB_HUD |RGB_MOD |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        | PR SCR |KC_ASDN | P1     | P2     | P3     | PENT   |        |RGB_M_K |RGB_M_SW|RGB_M_B |RGB_M_P |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        | FN     |        |        | P0     |        | P.     | PENT   |RGB_M_G |RGB_M_X |RGB_M_SN|RGB_M_R |RGB_TOG |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  RGB_SMOD },
  { KC_MSEL, KC_CALC, KC_TRNS, KC_MAIL, KC_SPC, KC_ASRP, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_SPC,  RGB_VAI, RGB_SAI,  RGB_HUI, KC_TRNS },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_SPC, KC_ASUP, KC_P6,   KC_P5,   KC_P4,   KC_PLUS, KC_SPC,  RGB_VAD, RGB_SAD,  RGB_HUD, RGB_MOD },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  KC_SPC, KC_ASDN, KC_P3,   KC_P2,   KC_P1,   KC_TRNS, KC_SPC,  RGB_M_K, RGB_M_SW, RGB_M_B, RGB_M_P },
  { RESET,   KC_TRNS, KC_TRNS, MO(_FN), KC_SPC, KC_SPC,  KC_KP_0, KC_TRNS, KC_PDOT, KC_PENT, RGB_M_G, RGB_M_X, RGB_M_SN, RGB_M_R, RGB_TOG },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
