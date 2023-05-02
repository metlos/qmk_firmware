#include "dactyl_lk.h"

int lights_on;

void toggle_light(void) {
    if (!lights_on) {
        setPinInputHigh(LIGHT_PIN);
    } else {
        setPinInputLow(LIGHT_PIN);
    }
    lights_on = !lights_on;
}

void keyboard_post_init_kb(void) {
    debug_enable = true;
    // debug_matrix = true;
    debug_keyboard = true;
    // debug_mouse = true;
}

