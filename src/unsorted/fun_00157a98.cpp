// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"

struct SortEntry {
    char pad0[4];
    f32 key;
};

extern "C" s32 func_00157A98(SortEntry **left, SortEntry **right)
{
    SortEntry *leftEntry = *left;
    SortEntry *rightEntry = *right;
    f32 leftKey = leftEntry->key;
    f32 rightKey = rightEntry->key;
    if (rightKey < leftKey) {
        return 1;
    }
    if (leftKey < rightKey) {
        return -1;
    }
    return (s32)((char *)rightEntry - (char *)leftEntry) >> 4;
}
