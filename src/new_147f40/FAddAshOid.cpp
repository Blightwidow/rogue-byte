// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32; typedef unsigned int u32;
extern "C" {
s32 FAddAshOid(u32 *arg0, s32 arg1, s32 arg2) {
    s8 *base = (s8 *)arg0;
    u32 index = *arg0;

    if (index >= 8) {
        return 0;
    }
    s8 *slot = base + index * 8;
    *(s32 *)(slot + 4) = arg1;
    s8 *slot2 = base + *arg0 * 8;
    *(s32 *)(slot2 + 8) = arg2;
    *arg0 += 1;
    return 1;
}

}
