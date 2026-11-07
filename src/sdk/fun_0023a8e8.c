// SPDX-License-Identifier: GPL-3.0-or-later
extern void* memset(void*, int, unsigned);
extern int D_002C5A50;
extern int D_002C5A54;
extern char B_0044E708[];
void func_0023A8E8(void) {
    D_002C5A50 = 0;
    D_002C5A54 = 0;
    memset(B_0044E708, 0, 0x200);
}
