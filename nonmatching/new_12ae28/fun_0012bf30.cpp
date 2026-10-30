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
    pbis->ReadVector((VECTOR *)pacr->vecDefault);
    ALLOCREQ allocreq;
    pacr->ckey = pbis->U16Read();
    allocreq.cb = pacr->ckey << 2;
    allocreq.cbAlign = 0x10;
    pacr->at = (float *)PvAllocSwImpl__Fi(&allocreq);
    int ikey = 0;
    if (pacr->ckey > 0) {
        for (ikey = 0; ikey < pacr->ckey; ikey++)
            pacr->at[ikey] = (float)pbis->U16Read() * 0.016666668f;
    }
    unsigned int maskAxes = pbis->U8Read();
    for (int iaxis = 0; iaxis < 3; iaxis++) {
        if (maskAxes & (1 << iaxis)) {
            allocreq.cbAlign = 0x10;
            allocreq.cb = pacr->ckey * 12;
            float *apg = (float *)PvAllocSwImpl__Fi(&allocreq);
            pacr->apg[iaxis] = apg;
            if (pacr->ckey > 0) {
                for (int ikey = 0; ikey < pacr->ckey; ikey++) {
                    apg[0] = pbis->F32Read();
                    apg[1] = pbis->F32Read();
                    apg[2] = pbis->F32Read();
                    apg += 3;
                }
            }
        }
    }
}
