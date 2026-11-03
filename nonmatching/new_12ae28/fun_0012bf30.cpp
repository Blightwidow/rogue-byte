#include "sly2.h"
struct CBinaryInputStream {
    int pad;
    void ReadVector(VECTOR *pvec);
    int U16Read();
    int U8Read();
    float F32Read();
};
struct ALLOCREQ { int cb; int cbAlign; };
struct ACRAXIS {
    int vtbl;
    int ckey;
    float *at;
    float *apg[3];
    int unused18[2];
    float vecDefault[4];
};
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);

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
            apg[0] = pbis->F32Read();
            apg[1] = pbis->F32Read();
            apg[2] = pbis->F32Read();
            apg += 3;
        }
    }
}
