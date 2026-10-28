/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SPRBUFENTRY { int cb; unsigned pvSpr; };
struct SPRBUF { unsigned pdmatag; unsigned pvSpr; SPRBUFENTRY aentry[8]; int centry; int sprbs; };
extern "C" {
extern SPRBUF B_003DD2C0[2];
extern int g_2c3c5c;
extern int *g_2de59c;
void func_002417F0(int *, int, int);
void func_002417A0(int *);
void SaveSprBuf__FPve(void *pvDest, ...)
{
    int apvDest[8];
    int ientry = 0;
    SPRBUF *psprbuf = &B_003DD2C0[g_2c3c5c];
    psprbuf->sprbs = 3;
    func_002417F0(g_2de59c, 0, 0);
    int *pdest = apvDest;
    int pv = (int)pvDest;
    if (pv != 0) {
        char *argp = (char *)__builtin_next_arg(pvDest) - 56;
        do {
            *pdest = pv;
            pdest++;
            argp += 8;
            pv = *(int *)(argp - 8);
            ientry++;
        } while (pv != 0);
    }
    char *ppv = (char *)psprbuf + 0xC;
    char *pcb = (char *)psprbuf + 8;
    ientry = psprbuf->centry - ientry;
    int ipvDest = 0;
    while (ientry < psprbuf->centry - 1) {
        int cb = *(int *)((char *)pcb + ientry * 8);
        unsigned pvSpr = *(unsigned *)((char *)ppv + ientry * 8);
        *(unsigned long *)(pvSpr - 0x10) = (unsigned long)(cb >> 4) | 0x10000000UL | ((unsigned long)apvDest[ipvDest] << 32);
        ientry++;
        ipvDest++;
    }
    int cbLast = *(int *)((char *)pcb + ientry * 8);
    unsigned pvSprLast = *(unsigned *)((char *)ppv + ientry * 8);
    *(unsigned long *)(pvSprLast - 0x10) = (unsigned long)(cbLast >> 4) | 0x70000000UL | ((unsigned long)apvDest[ipvDest] << 32);
    int *channel = g_2de59c;
    *channel = *channel & ~0x40;
    *(unsigned *)((char *)channel + 0x80) = (psprbuf->pdmatag & 0x0FFFFFFF) | 0x80000000;
    func_002417A0(g_2de59c);
    SPRBUF *other = &B_003DD2C0[1 - g_2c3c5c];
    if (other->sprbs == 3)
        other->sprbs = 0;
}
}
