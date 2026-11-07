// SPDX-License-Identifier: GPL-3.0-or-later
extern unsigned int sceSifGetReg(int);
extern void func_0023A9C8(void);
extern void func_0023A920(int, int);
int sceSifSyncIop(void) {
    if (sceSifGetReg(4) & 0x40000) {
        func_0023A9C8();
        func_0023A920(1, 1);
        func_0023A920(0, 1);
        return 1;
    }
    return 0;
}
