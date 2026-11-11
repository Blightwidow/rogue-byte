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
WEIGHTEDRECORD D_002C3968[9] = {
    {0, 0, 0.0f, {{0, -1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},
    {6, 12, 0.4f, {{30, 1116}, {30, 1115}, {15, 1122}, {15, 1121}, {5, 1119}, {5, 1118}}},
    {6, 12, 0.4f, {{30, 1119}, {30, 1118}, {15, 1125}, {15, 1124}, {5, 1128}, {5, 1127}}},
    {6, 12, 0.4f, {{30, 1119}, {30, 1118}, {15, 1125}, {15, 1124}, {5, 1128}, {5, 1127}}},
    {6, 12, 0.4f, {{30, 1128}, {30, 1127}, {15, 1131}, {15, 1130}, {5, 1137}, {5, 1136}}},
    {6, 12, 0.4f, {{30, 1128}, {30, 1127}, {15, 1131}, {15, 1130}, {5, 1137}, {5, 1136}}},
    {6, 12, 0.4f, {{30, 1137}, {30, 1136}, {15, 1134}, {15, 1133}, {5, 1143}, {5, 1142}}},
    {6, 12, 0.4f, {{30, 1137}, {30, 1136}, {15, 1134}, {15, 1133}, {5, 1143}, {5, 1142}}},
    {6, 12, 0.4f, {{30, 1134}, {30, 1133}, {15, 1143}, {15, 1142}, {5, 1140}, {5, 1139}}}
};
