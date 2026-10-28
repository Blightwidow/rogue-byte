// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct KEYB { float pos[3]; float t; float vecIn[4]; float vecOut[4]; };
struct ACRB { int pad0; int ckey; KEYB *akey; };
extern "C" {
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, VECTOR *);
unsigned U16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
}
extern "C" void LoadAcrbFromBrx(ACRB *pacrb, Bis *pbis)
{
    int ckey = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = ckey * 0x30;
    req.cbAlign = 0x10;
    pacrb->ckey = ckey;
    pacrb->akey = (KEYB *)PvAllocSwClearImpl__Fi(&req);
    for (int ikey = 0; ikey < pacrb->ckey; ikey++) {
        KEYB *pkey = pacrb->akey + ikey;
        int frame = U16Read__18CBinaryInputStream(pbis);
        float value;
        asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (value) : "r" (frame));
        float scale = 1.0f / 60.0f;
        register Bis *argStream asm("$4") = pbis;
        register VECTOR *argVector asm("$5") = (VECTOR *)pkey->pos;
        asm("mul.s %0, %0, %1" : "+f" (value) : "f" (scale), "r" (argStream), "r" (argVector));
        pkey->t = value;
        ReadVector__18CBinaryInputStreamP6VECTOR(argStream, argVector);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->vecIn);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->vecOut);
    }
}
