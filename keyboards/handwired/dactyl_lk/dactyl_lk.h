#pragma once

#include "quantum.h"

void toggle_light(void);

#define LAYOUT( \
    l00, l01, l02, l03, l04, l05,                          r00, r01, r02, r03, r04, r05, \
    l10, l11, l12, l13, l14, l15,                          r10, r11, r12, r13, r14, r15, \
    l20, l21, l22, l23, l24, l25,                          r20, r21, r22, r23, r24, r25, \
              lt0, lt1, lt2, lt3,                          rt0, rt1, rt2, rt3            \
) { \
    { r00, r01, r02, r03, r04, r05 }, \
    { r10, r11, r12, r13, r14, r15 }, \
    { r20, r21, r22, r23, r24, r25 }, \
    { rt0, rt1, rt2, rt3, XXX, XXX }, \
\
    { l00, l01, l02, l03, l04, l05 }, \
    { l10, l11, l12, l13, l14, l15 }, \
    { l20, l21, l22, l23, l24, l25 }, \
    { XXX, XXX, lt0, lt1, lt2, lt3 }  \
}
/* #define LAYOUT( \
    l00, l01, l02, l03, l04, l05, \
    l10, l11, l12, l13, l14, l15, \
    l20, l21, l22, l23, l24, l25, \
              lt0, lt1, lt2, lt3  \
) { \
    { l00, l01, l02, l03, l04, l05 }, \
    { l10, l11, l12, l13, l14, l15 }, \
    { l20, l21, l22, l23, l24, l25 }, \
    { XXX, XXX, lt0, lt1, lt2, lt3 }  \
} */
/* #define LAYOUT( \
    r00, r01, r02, r03, r04, r05, \
    r10, r11, r12, r13, r14, r15, \
    r20, r21, r22, r23, r24, r25, \
              rt0, rt1, rt2, rt3  \
) { \
    { r00, r01, r02, r03, r04, r05 }, \
    { r10, r11, r12, r13, r14, r15 }, \
    { r20, r21, r22, r23, r24, r25 }, \
    { rt0, rt1, rt2, rt3, XXX, XXX }  \
} */

