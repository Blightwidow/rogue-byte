// SPDX-License-Identifier: GPL-3.0-or-later
extern int B_002DFB50;
extern int B_002DFB54;
extern "C" void iSignalSema(int);
extern "C" int ResetGs__Fv(void)
{
    if (B_002DFB54 != 0 && (*(volatile unsigned long *)0x12001000 & 2)) {
        B_002DFB54 = 0;
        iSignalSema(B_002DFB50);
    }
    asm volatile("sync");
    asm volatile("ei");
    return -1;
}
