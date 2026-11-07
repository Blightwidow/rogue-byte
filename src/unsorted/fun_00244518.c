// SPDX-License-Identifier: GPL-3.0-or-later
extern int *B_004508A8, *B_004508AC, *B_004508B0;
extern int D_002C8358;
extern void iSignalSema(int);
void func_00244518(unsigned *source) {
    int *uncached = (int *)((unsigned)source | 0x20000000);
    if (B_004508A8 != 0) *B_004508A8 = uncached[0];
    if (B_004508AC != 0) *B_004508AC = uncached[1];
    if (B_004508B0 != 0) *B_004508B0 = uncached[0x90 / 4];
    iSignalSema(D_002C8358);
}
