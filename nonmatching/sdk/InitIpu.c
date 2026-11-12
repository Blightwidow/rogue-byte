// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
void func_00254C28(int);
extern QW D_002C8550[];
extern QW D_002C85A0[];

void InitIpu(void)
{
    func_00254C28(1);
    *(volatile s32 *)0x10002010 = 0x40000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002000 = 0;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile QW *)0x10007010 = D_002C8550[0];
    *(volatile QW *)0x10007010 = D_002C8550[1];
    *(volatile QW *)0x10007010 = D_002C8550[2];
    *(volatile QW *)0x10007010 = D_002C8550[3];
    *(volatile QW *)0x10007010 = D_002C8550[4];
    *(volatile QW *)0x10007010 = D_002C8550[4];
    *(volatile QW *)0x10007010 = D_002C8550[4];
    *(volatile QW *)0x10007010 = D_002C8550[4];
    *(volatile s32 *)0x10002000 = 0x50000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002000 = 0x58000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile QW *)0x10007010 = D_002C85A0[0];
    *(volatile QW *)0x10007010 = D_002C85A0[1];
    *(volatile s32 *)0x10002000 = 0x60000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002000 = 0x90000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002010 = 0x40000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002000 = 0;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
}
