/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SPRBUFENTRY { int cb; unsigned pvSpr; };
struct SPRBUF { unsigned pdmatag; unsigned pvSpr; SPRBUFENTRY aentry[8]; int centry; int sprbs; };
extern "C" {
extern SPRBUF B_003DD2C0[2];
extern int g_2c3c5c;
extern int *g_2de59c;
extern int *g_2de5a0;
void func_002417F0(int *, int, int);
void func_00241728(int *, unsigned);
void LoadSprBuf__Fie(int cb, ...)
{
    unsigned ipvSpr;
    SPRBUF *psprbuf = &B_003DD2C0[1 - g_2c3c5c];
    int centry = 0;
    ipvSpr = psprbuf->pvSpr;
    if (psprbuf->sprbs == 3)
        func_002417F0(g_2de59c, 0, 0);
    psprbuf->sprbs = 1;
    char *argp = (char *)__builtin_next_arg(cb) - 56;
    unsigned pvSource = *(unsigned *)(argp - 8);
    if (cb != 0) {
        do {
            int cbRounded = (cb + 0xF) & ~0xF;
            int cbNext = *(int *)argp;
            argp += 8;
            unsigned pvSourceNext = *(unsigned *)argp;
            argp += 8;
            psprbuf->aentry[centry].pvSpr = ipvSpr + 0x10;
            psprbuf->aentry[centry].cb = cbRounded;
            ipvSpr = ipvSpr + 0x10 + cbRounded;
            if (pvSource != 0) {
                unsigned long tag = ((unsigned long)pvSource << 32) | (unsigned)(cbRounded >> 4);
                if (pvSourceNext != 0)
                    tag |= 0x30000000;
                *(unsigned long *)(centry + psprbuf->pdmatag * 0x10) = tag;
            }
            centry = centry + 1;
            pvSource = pvSourceNext;
            cb = cbNext;
        } while (cb != 0);
    }
    psprbuf->centry = centry;
    int *channel = g_2de5a0;
    *channel = *channel | 0x40;
    *(unsigned *)((char *)channel + 0x80) = (psprbuf->pvSpr & 0x0FFFFFFF) | 0x80000000;
    func_00241728(g_2de5a0, psprbuf->pdmatag & 0x0FFFFFFF);
}
}
