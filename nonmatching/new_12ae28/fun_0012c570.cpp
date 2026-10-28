#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct Acr { int pad0; int ckey; float *at; float *apg[3]; float pad[2]; VECTOR def; };
extern "C" {
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *s, VECTOR *v);
unsigned U16Read__18CBinaryInputStream(Bis *s);
unsigned U8Read__18CBinaryInputStream(Bis *s);
float F32Read__18CBinaryInputStream(Bis *s);
}
void *PvAllocSwImpl(int);
void func_0012C570(Acr *acr, Bis *bis)
{
    int ikey;
    ReadVector__18CBinaryInputStreamP6VECTOR(bis, &acr->def);
    int ckey = U16Read__18CBinaryInputStream(bis);
    ALLOCREQ req;
    req.cb = ckey << 2;
    req.cbAlign = 0x10;
    acr->ckey = ckey;
    acr->at = (float *)PvAllocSwImpl((int)&req);
    for (ikey = 0; ikey < acr->ckey; ikey++) {
        int frame = U16Read__18CBinaryInputStream(bis);
        acr->at[ikey] = (float)frame * (1.0f / 60.0f);
    }
    unsigned grf = U8Read__18CBinaryInputStream(bis);
    int bit = 1;
    for (int iaxis = 0; iaxis < 3; iaxis++, bit <<= 1) {
        if ((bit & grf) == 0)
            continue;
        req.cbAlign = 0x10;
        req.cb = acr->ckey << 3;
        register float *base asm("$4");
        base = (float *)PvAllocSwImpl((int)&req);
        acr->apg[iaxis] = base;
        float *apg = base;
        for (ikey = 0; ikey < acr->ckey; ikey++) {
            apg[0] = F32Read__18CBinaryInputStream(bis);
            apg[1] = F32Read__18CBinaryInputStream(bis);
            apg += 2;
        }
    }
}
