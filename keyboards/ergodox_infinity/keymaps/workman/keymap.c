#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_layers {
    _WORKMAN,
    _NUM,
    _PROGRAMMER,
    _FUNCTION,
    _UTILITY
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  CHTSHT
};


char *layerNames[] = {
  [_WORKMAN]="Workman",
  [_NUM]="NumPad",
  [_PROGRAMMER]="Programmer",
  [_FUNCTION]="Function",
  [_UTILITY]="Utility"
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic Workman layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |   Esc    |  1  |  2  |  3  |  4  |  5  |Util|           | Util |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  D  |  R  |  W  |  B  |  [{  |           |  ]}  |  J  |  F  |  U  |  P  |  '  |   =    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  BSPC  |  A  |  S  |  H  |  T  |  G  |------|           |------|  Y  |  N  |  E  |  O  |  I  |   ;    |
 * |--------+-----+-----+-----+-----+-----|Enter |           |Enter |-----+-----+-----+-----+-----+--------|
 * | LGUI   |  Z  |  X  |  M  |  C  |  V  |      |           |      |  K  |  L  |  ,  |  .  |  /  |  RGui  | 
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |LShft |LCtrl|  `  |  \  |  -  |                                     |Hyper| Pgup|PgDn |RCtrl|Lshft|
 *   `------------------------------'                                     `-----------------------------'
 *                                   ,------------.          ,------------.                  
 *                                   |Lprog|LNum  |          | Left |Right|
 *                              ,----|-----|------|          |------+-----+-----.
 *                             |    |      | Home |          | Up   |     |     |
 *                            |Space|LAlt  |------|          |------|Ralt |Space|
 *                             |    |      | End  |          | Down |     |     |
 *                              `-----------------'          `------------------'
 */
[_WORKMAN] = LAYOUT_ergodox(
  // left hand
  KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,     KC_5,            TG(_UTILITY),
  KC_TAB,       KC_Q,    KC_D,    KC_R,    KC_W,     KC_B,            KC_LBRACKET,
  KC_BSPACE,    KC_A,    KC_S,    KC_H,    KC_T,     KC_G,
  OSM(MOD_LGUI),KC_Z,    KC_X,    KC_M,    KC_C,     KC_V,            KC_ENTER,
  KC_LSPO,      KC_LCTL, KC_GRV,  KC_BSLS, KC_MINUS,

                                                   TG(_PROGRAMMER), TG(_NUM),
                                                                    KC_HOME,
                                         KC_SPACE, KC_LALT,         KC_END,

  // right hand
  TG(_UTILITY),KC_6, KC_7,            KC_8,    KC_9,    KC_0,     KC_MINUS,
  KC_RBRACKET, KC_J, KC_F,            KC_U,    KC_P,    KC_QUOT,  KC_EQUAL,
               KC_Y, KC_N,            KC_E,    KC_O,    KC_I,     KC_SCOLON,
  KC_ENTER,    KC_K, KC_L,            KC_COMM, KC_DOT,  KC_SLASH, KC_RGUI,
                     KC_KP_ASTERISK,  KC_PGUP, KC_PGDN, KC_RCTL,  KC_RSPC,

  KC_LEFT, KC_RIGHT,
  KC_UP,
  KC_DOWN, KC_RALT, KC_SPACE
),

/* Programmer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  !   |  @   |  £   |  $   |  %   |ChtSht|           |      |  ^   |  &   |  *   |  (   |  )   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |  ~   |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      | CLIP |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_PROGRAMMER] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, CHTSHT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS,

                                               KC_TRNS, LGUI(KC_M),
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,

  // right hand
  KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Function
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   F11   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_FUNCTION] = LAYOUT_ergodox(
  // left hand
  KC_F11, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,

  // right hand
  KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Utility
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |      |      |      |      |      | Util |           | Util |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |BL_INC|      |           |      |BL_INC|      |      |      |      |        |
 * |---------+------+------+------+------+------| RESET|           |RESET |------+------+------+------+------+--------|
 * |         |      |      |      |      |BL_DEC|------|           |------|BL_DEC|      |      |      |      |        |
 * |---------+------+------+------+------+------| DEBUG|           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |BL_TOG|      |           |DEBUG |BL_TOG|      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_UTILITY] = LAYOUT_ergodox(
  // left hand
  VRSN,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   TG(_UTILITY),
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_INC,  RESET,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_DEC,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_TOGG, DEBUG,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                                     KC_NO,   KC_NO,
                                              KC_NO,
                              KC_NO, KC_NO,   KC_NO,

  // right hand
  TG(_UTILITY), KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  RESET,        BL_INC,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                BL_DEC,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  DEBUG,        BL_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_NO, KC_NO,
  KC_NO,
  KC_NO, KC_NO, KC_NO
),

/* Keymap 2: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  {   |  }   |  |   |      |           |      |      |  7   |  8   |  9   |  *   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |      |  1   |  2   |  3   |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  .   |  0   |  0   |  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  KC_F12,  KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,         KC_F11,
  _______, _______, KC_KP_7,   KC_KP_8, KC_KP_9, KC_KP_ASTERISK, _______,
           _______, KC_KP_4,   KC_KP_5, KC_KP_6, KC_KP_PLUS,     _______,
  _______, _______, KC_KP_1,   KC_KP_2, KC_KP_3, KC_KP_SLASH,    _______,
                    KC_KP_DOT, KC_KP_0, KC_KP_0, KC_KP_EQUAL,    _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

};

uint8_t oldLayer = 255;
char* layerName = "";
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case EPRM:
                eeconfig_init();
                return false; break;
            case VRSN:
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false; break;
            case CHTSHT:
              register_code(KC_LSHIFT);
              register_code(KC_LGUI);
              register_code(KC_SLASH);
              unregister_code(KC_SLASH);
              unregister_code(KC_LGUI);
              unregister_code(KC_LSHIFT);
              return false; break;
        }

    }
    return true;
};

/**
 * Runs just one time when the keyboard initializes.
 */
void matrix_init_user(void) {

};

/**
 * Runs constantly in the background, in a loop.
 */
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  if (layer != oldLayer) {
    oldLayer = layer;
    ergodox_led_all_off();
    layerName = layerNames[layer];
    switch (layer) {
      case _WORKMAN:
        ergodox_right_led_1_on();
      break;
      case _PROGRAMMER:
        ergodox_right_led_2_on();
      break;
      case _NUM:
        ergodox_board_led_off();
      break;
      case _UTILITY:
        ergodox_right_led_3_on();
      break;
    }
  }
};
