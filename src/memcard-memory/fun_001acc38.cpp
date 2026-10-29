// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32; typedef unsigned int u32; typedef float f32;
extern "C" {
extern s8 B_002E65E0[];
extern f32 g_2ddf0c;

void func_001ACC38(s8 *arg0, s32 arg1) {
    if (arg1 != *(s32 *)(arg0 + 0x44)) {
        if (arg1 < 4) {
            if (arg1 >= 2) {
                u32 tableOffset = 0x8000;
                s8 *table = B_002E65E0 + tableOffset;
                *(s32 *)(table + 0x7D50) = 0;
            }
        }
        *(s32 *)(arg0 + 0x44) = arg1;
        *(f32 *)(arg0 + 0x48) = g_2ddf0c;
    }
}

}
