// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"

extern "C" {
void snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void (*)(int, unsigned long), unsigned long);
void func_002330D0(int a0, int a1, int a2, int a3, int t0, int t1, int t2, void (*t3)(int, unsigned long), unsigned long stack0) {
    int buf[7];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = a3;
    buf[4] = t0;
    buf[5] = t1;
    buf[6] = t2;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x4C, 0x1C, (char *)buf, t3, stack0);
}
}
