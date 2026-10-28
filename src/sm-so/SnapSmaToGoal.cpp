#include "sly2.h"
struct SM;
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2();
};
struct SMA : BASIC {
    char pad1[0x14];
    SM *psm; char pad2[0x14]; int ism;
};
struct Hold {
    SMA *p;
    Hold(SMA *s) { p = s; s->v0(); }
    ~Hold() { p->v1(); }
};
extern "C" int FSmaRetracted(SMA *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(SM *, int);
extern "C" void SnapSmaTransition(SMA *);
extern "C" void ChooseSmaTransition(SMA *, int);

void SnapSmaToGoal(SMA *sma, int oid)
{
    if (FSmaRetracted(sma) == 0) {
        Hold hold(sma);
        sma->ism = IsmsFindSmRequired__FP2SM3OID(sma->psm, oid);
        SnapSmaTransition(sma);
        ChooseSmaTransition(sma, 1);
    }
}
