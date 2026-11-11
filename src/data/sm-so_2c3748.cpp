// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Read by func_001F1748 (sm-so): records of 0x3C bytes picked by episode (index * 0x3C): a count range (NRandInRange),
// a chance compared with GRandInRange, then six {weight, value} pairs whose weights a random roll walks. Which of the two
// tables depends on FIsBasicDerivedFrom(object, 0x3A). The words after the nine records stay assembly.
#include "types.h"

typedef struct WEIGHTEDENTRY {
    s32 weight;
    s32 value;
} WEIGHTEDENTRY;

typedef struct WEIGHTEDRECORD {
    s32 countMin;
    s32 countMax;
    f32 chance;
    WEIGHTEDENTRY entries[6];
} WEIGHTEDRECORD;

// data-ok: typed from func_001F1748
WEIGHTEDRECORD D_002C3748[9] = {
    {0, 0, 0.0f, {{0, -1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},
    {4, 8, 0.2f, {{30, 1114}, {30, 1115}, {15, 1120}, {15, 1121}, {5, 1117}, {5, 1118}}},
    {4, 8, 0.2f, {{30, 1117}, {30, 1118}, {15, 1123}, {15, 1124}, {5, 1126}, {5, 1127}}},
    {4, 8, 0.2f, {{30, 1117}, {30, 1118}, {15, 1123}, {15, 1124}, {5, 1126}, {5, 1127}}},
    {4, 8, 0.2f, {{30, 1126}, {30, 1127}, {15, 1129}, {15, 1130}, {5, 1135}, {5, 1136}}},
    {4, 8, 0.2f, {{30, 1126}, {30, 1127}, {15, 1129}, {15, 1130}, {5, 1135}, {5, 1136}}},
    {4, 8, 0.2f, {{30, 1135}, {30, 1136}, {15, 1132}, {15, 1133}, {5, 1141}, {5, 1142}}},
    {4, 8, 0.2f, {{30, 1135}, {30, 1136}, {15, 1132}, {15, 1133}, {5, 1141}, {5, 1142}}},
    {4, 8, 0.2f, {{30, 1132}, {30, 1133}, {15, 1141}, {15, 1142}, {5, 1138}, {5, 1139}}}
};
