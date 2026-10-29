// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32; typedef unsigned short u16;
extern "C" {
void BASIC_Destruct(s8 *, s32);
void FreeStreamAmb(s8 *);

void StreamAmb_Release(s8 *arg0) {
    s32 count = *(u16 *)(arg0 + 0x4C) - 1;

    *(u16 *)(arg0 + 0x4C) = (u16)count;
    if ((count << 16) == 0 && arg0 != 0) {
        BASIC_Destruct(arg0, 0);
        FreeStreamAmb(arg0);
    }
}

}
