// SPDX-License-Identifier: GPL-3.0-or-later
#include "m2c_macros.h"

void AddDancerMove(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 count;
    s32 entryOffset;
    char *entry;

    count = *(s32 *)((char *)arg0 + 0x2C4);
    if ((u32) count < 8U) {
        *(s32 *)((char *)arg0 + 0x2C4) = count + 1;
        entryOffset = (count * 0x28) + 0x2C8;
        entry = (char *)arg0 + entryOffset;
        *(s32 *)(entry + 0x0) = arg1;
        *(s32 *)(entry + 0x4) = arg2;
        *(s32 *)(entry + 0xC) = arg3;
        *(s32 *)(entry + 0x10) = arg4;
        *(s32 *)(entry + 0x1C) = arg5;
        *(s32 *)(entry + 0x18) = 0;
        *(s32 *)(entry + 0x24) = 0;
    }
}
