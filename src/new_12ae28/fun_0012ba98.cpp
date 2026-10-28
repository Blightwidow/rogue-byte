// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct KEYBL { float pos[3]; float t; float tan[4]; };
struct ACRBL { int pad0; int ckey; KEYBL *akey; };
extern "C" {
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, VECTOR *);
unsigned U16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
}
extern "C" void func_0012BA98(ACRBL *pacrbl, Bis *pbis)
{
    int ckey = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = ckey << 5;
    req.cbAlign = 0x10;
    pacrbl->ckey = ckey;
    pacrbl->akey = (KEYBL *)PvAllocSwClearImpl__Fi(&req);
    for (int ikey = 0; ikey < pacrbl->ckey; ikey++) {
        KEYBL *pkey = pacrbl->akey + ikey;
        int frame = U16Read__18CBinaryInputStream(pbis);
        float value;
        asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (value) : "r" (frame));
        float scale = 1.0f / 60.0f;
        register Bis *argStream asm("$4") = pbis;
        register VECTOR *argVector asm("$5") = (VECTOR *)pkey->pos;
        asm("mul.s %0, %0, %1" : "+f" (value) : "f" (scale), "r" (argStream), "r" (argVector));
        pkey->t = value;
        ReadVector__18CBinaryInputStreamP6VECTOR(argStream, argVector);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->tan);
    }
}
