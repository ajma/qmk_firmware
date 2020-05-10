/* Copyright 2020
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define CTRL_ESC LCTL_T(KC_ESCAPE)
#define LOCK LCTL(LGUI(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | GUI  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Alt  | Left |Right |Lower |    Space    |Raise | Up   | Down |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,     KC_BSPC, 
        KC_LGUI,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN,  KC_QUOT, 
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_ENT, 
        CTRL_ESC, KC_LALT, KC_LEFT, KC_RGHT, LOWER, KC_SPC, KC_SPC, RAISE, KC_UP,   KC_DOWN, _______, _______),

    /* Lower
     */
    [_LOWER] = LAYOUT_ortho_4x12(
        _______, KC_BTN2, _______, KC_MS_U, _______, KC_WH_U, _______, KC_HOME, KC_UP,   KC_PGUP, _______, KC_TRNS,
        KC_TRNS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, 
        KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_END,  _______, KC_PGDN, _______, _______, 
        KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLASH, 
        KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_VAI, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_VAD, _______, _______, _______, 
        LOCK,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {30, 30, 30};

const rgblight_segment_t PROGMEM lower_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_BLUE}
);

const rgblight_segment_t PROGMEM raise_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_WHITE}
);

const rgblight_segment_t PROGMEM adjust_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer_rgb,
    raise_layer_rgb,
    adjust_layer_rgb
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    int active_state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(active_state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(active_state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(active_state, _ADJUST));
    return active_state;
}