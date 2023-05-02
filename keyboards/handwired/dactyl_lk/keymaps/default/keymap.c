// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "action_tapping.h"
#include "print.h"

#define _BASE    0
#define _SYMBOLS 1
#define _NAV     2
#define _NUMBERS 3
#define _FUNC    4
#define _MOUSE   5
#define _MEDIA   6
#define _CZECH   7

enum {
    TD_COEQ, // ':' on tap, ':=' on double tap
    TD_CZA,
    TD_CZE,
    TD_CZI,
    TD_CZO,
    TD_CZU,
    TD_CZY,
    TD_CZC,
    TD_CZD,
    TD_CZN,
    TD_CZR,
    TD_CZS,
    TD_CZT,
    TD_CZZ,
};


enum my_keycodes {
    XXX    = KC_NO,
    VVV    = KC_TRNS,
    MY_MOUS = TO(_MOUSE),
    MY_MEDI = TG(_MEDIA),
    MY_BASE = TO(_BASE),
    MY_SYMS = MO(_SYMBOLS),
    MY_NUMS = TT(_NUMBERS),
    MY_FUNC = TT(_FUNC),
    MY_V    = LSFT_T(KC_V),
    MY_C    = LGUI_T(KC_C),
    MY_X    = LALT_T(KC_X),
    MY_Z    = LCTL_T(KC_Z),
    MY_M    = RSFT_T(KC_M),
    MY_COMM = RGUI_T(KC_COMM),
    MY_DOT  = RALT_T(KC_DOT),
    MY_SLSH = RCTL_T(KC_SLSH),
    MY_SPCR = LT(_FUNC, KC_SPC),
    MY_ENT  = LT(_NUMBERS, KC_ENT),
    MY_RSFT = RSFT_T(KC_LCBR),
    MY_RGUI = RGUI_T(KC_RCBR),
    MY_COLN = TD(TD_COEQ),
    MY_TAB  = LT(_NAV, KC_TAB),
    MY_ESC  = LT(_CZECH, KC_ESC),

    MY_CA = TD(TD_CZA),
    MY_CE = TD(TD_CZE),
    MY_CI = TD(TD_CZI),
    MY_CO = TD(TD_CZO),
    MY_CU = TD(TD_CZU),
    MY_CY = TD(TD_CZY),
    MY_CC = TD(TD_CZC),
    MY_CD = TD(TD_CZD),
    MY_CN = TD(TD_CZN),
    MY_CR = TD(TD_CZR),
    MY_CS = TD(TD_CZS),
    MY_CT = TD(TD_CZT),
    MY_CZ = TD(TD_CZZ),
};


void dance_colon_equals(tap_dance_state_t *state, void *user_data);
void dance_czech(tap_dance_state_t *state, void *user_data);

typedef struct {
    uint8_t base_key;
    uint8_t single_pre;
    uint8_t single_pre_shift;
    uint8_t double_pre;
    uint8_t double_pre_shift;
} tap_dance_czech_t;

#define ACTION_TAP_DANCE_CZECH(base, single, single_sft, dbl, dbl_sft) \
    { .fn = {NULL, NULL, dance_czech}, .user_data = (void *)&((tap_dance_czech_t){base, single, single_sft, dbl, dbl_sft}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_COEQ] = ACTION_TAP_DANCE_FN(dance_colon_equals),
    [TD_CZA]  = ACTION_TAP_DANCE_CZECH(KC_A, KC_EQL, false, 0     , false),
    [TD_CZE]  = ACTION_TAP_DANCE_CZECH(KC_E, KC_EQL, false, KC_EQL, true ),
    [TD_CZI]  = ACTION_TAP_DANCE_CZECH(KC_I, KC_EQL, false, 0     , false),
    [TD_CZO]  = ACTION_TAP_DANCE_CZECH(KC_O, KC_EQL, false, 0     , false),
    [TD_CZU]  = ACTION_TAP_DANCE_CZECH(KC_U, KC_GRV, true , KC_EQL, false),
    [TD_CZY]  = ACTION_TAP_DANCE_CZECH(KC_Y, KC_EQL, false, 0     , false),
    [TD_CZC]  = ACTION_TAP_DANCE_CZECH(KC_C, KC_EQL, true , 0     , false),
    [TD_CZD]  = ACTION_TAP_DANCE_CZECH(KC_D, KC_EQL, true , 0     , false),
    [TD_CZN]  = ACTION_TAP_DANCE_CZECH(KC_N, KC_EQL, true , 0     , false),
    [TD_CZR]  = ACTION_TAP_DANCE_CZECH(KC_R, KC_EQL, true , 0     , false),
    [TD_CZS]  = ACTION_TAP_DANCE_CZECH(KC_S, KC_EQL, true , 0     , false),
    [TD_CZT]  = ACTION_TAP_DANCE_CZECH(KC_T, KC_EQL, true , 0     , false),
    [TD_CZZ]  = ACTION_TAP_DANCE_CZECH(KC_Z, KC_EQL, true , 0     , false),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        MY_MEDI, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_INS ,
        KC_GRV , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_QUOT, XXX    ,
        XXX    , MY_Z   , MY_X   , MY_C   , MY_V   , KC_B   ,     KC_N   , MY_M   , MY_COMM, MY_DOT , MY_SLSH, XXX    ,
                          MY_TAB , MY_ENT , MY_ESC , XXX    ,     XXX    , XXX     , MY_SPCR , MY_SYMS
    ),
    [_SYMBOLS] = LAYOUT(
        XXX    , XXX    , KC_DLR , KC_HASH, KC_AT  , KC_PERC,     XXX    , KC_LBRC, KC_RBRC, XXX    , XXX    , KC_INS ,
        KC_TILD, KC_PIPE, KC_BSLS, KC_EXLM, KC_ASTR, KC_AMPR,     MY_COLN, KC_LPRN, KC_RPRN, XXX    , XXX    , XXX    ,
        MY_BASE, KC_CIRC, KC_MINS, KC_PLUS, KC_EQL , KC_UNDS,     KC_SCLN, KC_LCBR, KC_RCBR, XXX    , XXX    , XXX    ,
                          XXX    , XXX    , XXX    , XXX    ,     XXX    , XXX    , XXX    , VVV
    ),
    [_NAV] = LAYOUT(
        XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,     KC_PGUP, KC_END , KC_HOME, KC_PGDN, KC_CUT , KC_INS ,
        XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COPY, XXX    ,
        MY_BASE, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXX    ,     XXX    , XXX    , XXX    , XXX    , KC_PSTE, KC_PSCR,
                          VVV    , XXX    , XXX    , XXX    ,     XXX    , KC_DEL , KC_BSPC, XXX
    ),
    [_NUMBERS] = LAYOUT(
        XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,     XXX    , KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_INS ,
        XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,     KC_P0  , KC_P4  , KC_P5  , KC_P6  , KC_PAST, XXX    ,
        MY_BASE, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXX    ,     XXX    , KC_P1  , KC_P2  , KC_P3  , XXX    , XXX    ,
                          XXX    , XXX    , XXX    , VVV    ,     KC_PMNS, KC_PPLS, KC_PDOT, KC_PEQL
    ),
    [_FUNC] = LAYOUT(
        XXX    , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     XXX    , XXX    , XXX    , XXX    , XXX    , KC_INS ,
        XXX    , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,     XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,
        MY_BASE, KC_F11 , KC_F12 , XXX    , XXX    , XXX    ,     XXX    , KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXX    ,
                          XXX    , XXX    , XXX    , XXX    ,     XXX    , XXX    , XXX    , VVV
    ),
    [_CZECH] = LAYOUT(
        XXX    , XXX    , XXX    , MY_CE  , MY_CR  , MY_CT  ,     MY_CY  , MY_CU   , MY_CI , MY_CO  , XXX    , KC_INS ,
        XXX    , MY_CA  , MY_CS  , MY_CD  , XXX    , XXX    ,     XXX    , XXX    , XXX    , XXX    , KC_EQL , XXX    ,
        MY_BASE, MY_CZ  , XXX    , MY_CC  , KC_LSFT, XXX    ,     MY_CN  , KC_RSFT, XXX    , XXX    , KC_GRV , XXX    ,
                          XXX    , XXX    , VVV    , XXX    ,     XXX    , XXX    , XXX    , XXX
    ),

    // TOY LAYERS
    [_MOUSE] = LAYOUT(
        MY_MEDI, XXX    , XXX    , XXX    , XXX    , XXX    ,     XXX    , KC_WH_U, XXX    , XXX    , XXX    , XXX    ,
        XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXX    , XXX    ,
        MY_BASE, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX    ,     XXX    , KC_WH_D, XXX    , XXX    , XXX    , XXX    ,
                          XXX    , XXX    , XXX    , XXX    ,     XXX    , KC_BTN1, KC_BTN2, KC_BTN3
    ),
    [_MEDIA] = LAYOUT(
        MY_MOUS, XXX    , XXX    , KC_MPRV, KC_VOLU, KC_MNXT,     KC_MSEL, KC_BRIU, XXX    , XXX    , XXX    , QK_BOOT,
        XXX    , XXX    , XXX    , XXX    , KC_VOLD, KC_MPLY,     XXX    , KC_BRID, XXX    , XXX    , XXX    , XXX    ,
        MY_BASE, XXX    , XXX    , XXX    , KC_MUTE, KC_MSTP,     XXX    , XXX    , XXX    , XXX    , XXX    , XXX    ,
                          XXX    , XXX    , XXX    , XXX    ,     XXX    , XXX    , XXX    , XXX
    )
};

// NOT USED, this is not working well due to lack of hardware :)
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (keycode == TOGGLE_LIGHT) {
//         if (record->event.pressed) {
//             toggle_light();
//         }
//         return false;
//     }
//     return true;
// }


void dance_colon_equals(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_COLON);
    } else if (state->count == 2) {
        tap_code16(KC_COLON);
        tap_code16(KC_EQL);
    }
}

void shifted(uint8_t key, uint8_t shift) {
    clear_mods();
    if (shift) {
        set_mods(MOD_BIT(KC_LSFT));
    }
    register_code(key);
    unregister_code(key);

    clear_mods();
}

void dance_czech(tap_dance_state_t *state, void *user_data) {
    tap_dance_czech_t *data = (tap_dance_czech_t *)user_data;

    // uint8_t mods = get_mods();

    if (state->count == 1) {
        shifted(data->single_pre, data->single_pre_shift);
    } else if (state->count > 1) {
        shifted(data->double_pre, data->double_pre_shift);
    }

    // set_mods(mods);

    register_code(data->base_key);
    unregister_code(data->base_key);
}
