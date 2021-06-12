#pragma once

#include "quantum.h"

#define LAYOUT_numpad_5x4( \
    k0,  k1,  k2,  k3,  \
    k4,  k5,  k6,       \
    k7,  k8,  k9,  k10, \
    k11, k12, k13,      \
    k14,      k15, k16  \
) \
{ \
    {k0,  k1,  k2,    k3    }, \
    {k4,  k5,  k6,    k10   }, \
    {k7,  k8,  k9,    KC_NO }, \
    {k11, k12, k13,   k16   }, \
    {k14, k15, KC_NO, KC_NO } \
}
