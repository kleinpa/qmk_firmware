#pragma once

#include "quantum.h"

#define LAYOUT_split_3x6_3(k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k40, k41)                                 \
    {                                                                                                                                                                                                                                                              \
        {k11, k10, k9, k8, k7, k6, k5, k4, k3, k2, k1, k0}, {k35, k34, k33, k32, k31, k30, k29, k28, k27, k26, k25, k24}, {KC_NO, KC_NO, KC_NO, k41, k40, k39, k38, k37, k36, KC_NO, KC_NO, KC_NO}, { k23, k22, k21, k20, k19, k18, k17, k16, k15, k14, k13, k12 } \
    }
