#include "sly2.h"
struct CBinaryInputStream {
    int pad;
    void ReadVector(VECTOR *pvec);
    int U16Read();
    int U8Read();
    float F32Read();
};
#include "alloc.h"
struct ACRAXIS {
    int vtbl;
    int ckey;
    float *at;
    float *apg[3];
    int unused18[2];
    float vecDefault[4];
};
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);

// Retail keeps the axis buffer in its own register (a0) for the store to apg[iaxis] and starts the
// key pointer (s0) from it in the delay slot of a plain blez: the key pointer is a giv that loop.c
// strength-reduces from indexed stores apg[ikey * 3 + n]. A hand-advanced pointer (apg += 3) shares
// one register with the buffer and gives blezl instead (score 7).
void func_0012BF30(ACRAXIS *pacr, CBinaryInputStream *pbis)
{
    int ikey;
    pbis->ReadVector((VECTOR *)pacr->vecDefault);
    int ckey = pbis->U16Read();
    ALLOCREQ allocreq;
    allocreq.cb = ckey << 2;
    allocreq.cbAlign = 0x10;
    pacr->ckey = ckey;
    pacr->at = (float *)PvAllocSwImpl__Fi(&allocreq);
    for (ikey = 0; ikey < pacr->ckey; ikey++) {
        int frame = pbis->U16Read();
        pacr->at[ikey] = (float)frame * 0.016666668f;
    }
    int maskAxes = pbis->U8Read();
    int bit = 1;
    for (int iaxis = 0; iaxis < 3; iaxis++, bit <<= 1) {
        if ((bit & maskAxes) == 0)
            continue;
        allocreq.cb = pacr->ckey * 12;
        allocreq.cbAlign = 0x10;
        float *apg = (float *)PvAllocSwImpl__Fi(&allocreq);
        pacr->apg[iaxis] = apg;
        for (ikey = 0; ikey < pacr->ckey; ikey++) {
            apg[ikey * 3 + 0] = pbis->F32Read();
            apg[ikey * 3 + 1] = pbis->F32Read();
            apg[ikey * 3 + 2] = pbis->F32Read();
        }
    }
}
