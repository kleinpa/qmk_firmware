#pragma once
#include "config_common.h"
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS \
    { D3, B4, B5, E6 }
#define MATRIX_COL_PINS \
    { D0, D4, C6, D7, B6, B2, B3, B1, F7, F6, F5, F4 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCING_DELAY 5
