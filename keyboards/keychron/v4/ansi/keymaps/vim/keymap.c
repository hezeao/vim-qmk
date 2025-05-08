/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers {
    MAC_BASE,
    WIN_BASE,
    NORMAL,
    VISUAL,
    REPLACE
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_ESC,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        XXXXXXX, KC_LCTL,  KC_LCMD,                            KC_SPC,                             KC_LOPT,  KC_RCMD,  KC_RCTL,  XXXXXXX),

    [WIN_BASE] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_ESC,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        XXXXXXX, KC_LCTL,  KC_LALT,                            KC_SPC,                             KC_LWIN,  KC_RALT,  KC_RCTL,  XXXXXXX),

    [NORMAL] = LAYOUT_60_ansi(
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TAB,  XXXXXXX,  XXXXXXX, C(KC_RGHT), KC_F2,   XXXXXXX, C(KC_C), C(KC_Z), KC_I,    XXXXXXX, C(KC_V),  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_ESC,  XXXXXXX,  XXXXXXX, KC_DEL,  C(KC_F), KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            KC_ENT,
        KC_LSFT,           XXXXXXX, C(KC_X), XXXXXXX, KC_V,    C(KC_LEFT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_RSFT,
        XXXXXXX, KC_LCTL,  KC_LALT,                            KC_SPC,                             KC_LWIN,  KC_RALT,  KC_RCTL,  XXXXXXX),

    [VISUAL] = LAYOUT_60_ansi(
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, S(C(KC_RGHT)), KC_F2,   XXXXXXX, C(KC_C), C(KC_Z), KC_I,    XXXXXXX, C(KC_V),  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_ESC,  XXXXXXX,  XXXXXXX, KC_DEL,  C(KC_F), KC_HOME, S(KC_LEFT), S(KC_DOWN), S(KC_UP),   S(KC_RGHT), XXXXXXX,  XXXXXXX,            KC_ENT,
        XXXXXXX,           XXXXXXX, C(KC_X), XXXXXXX, XXXXXXX, S(C(KC_LEFT)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX, KC_LCTL,  XXXXXXX,                            XXXXXXX,                            UG_TOGG,  QK_BOOT,  XXXXXXX,  XXXXXXX),

    [REPLACE] = LAYOUT_60_ansi(
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX,                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX)
};


bool set_mode(bool key_down, void *layer) {
    if (key_down) {
        layer_move((uint8_t)(uintptr_t)layer);
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                rgb_matrix_set_color(i, 204, 0, 255);
                break;
            case 2:
                rgb_matrix_set_color(i, 0, 204, 187);
                break;
            case 3:
                rgb_matrix_set_color(i, 238, 119, 34);
                break;
            default:
                break;
        }
    }
    return false;
}

// Suppressed_mods that are still held down will be re-added to the keyboard report.
const key_override_t normal_override = {.trigger_mods      = MOD_BIT(KC_LCTL),                                 //
                                        .layers            = ~(1 << 2),                                        //
                                        .options           = ko_option_no_unregister_on_other_key_down,        //
                                        .negative_mod_mask = (uint8_t) ~(MOD_BIT(KC_LCTL)),                    //
                                        .custom_action     = set_mode,                                         //
                                        .context           = (void *)2,                                        //
                                        .trigger           = KC_ESC,                                           //
                                        .replacement       = KC_NO,                                            //
                                        .enabled           = NULL};

const key_override_t insert_override = {.layers            = (1 << 2) | (1 << 3),                              //
                                        .options           = ko_option_no_reregister_trigger,                  //
                                        .custom_action     = set_mode,                                         //
                                        .context           = (void *)1,                                        //
                                        .trigger           = KC_I,                                             //
                                        .replacement       = KC_NO,                                            //
                                        .enabled           = NULL};

const key_override_t visual_override = {.layers            = (1 << 2),                                         //
                                        .options           = ko_option_no_reregister_trigger,                  //
                                        .custom_action     = set_mode,                                         //
                                        .context           = (void *)3,                                        //
                                        .trigger           = KC_V,                                             //
                                        .replacement       = KC_NO,                                            //
                                        .enabled           = NULL};



const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t caps_lock_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_CAPS);

const key_override_t ctrl_h_override = ko_make_with_layers(MOD_MASK_CTRL, KC_H, KC_BSPC, (1 << 1));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &normal_override,
    &insert_override,
    &visual_override,
    &delete_key_override,
    &caps_lock_override,
    &ctrl_h_override
};