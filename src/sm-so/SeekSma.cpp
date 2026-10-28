#include "sly2.h"
struct SM;
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2();
};
struct SMA : BASIC {
    char pad1[0x14];
    SM *psm; char pad2[8]; void *pasega; int ismCur; int ismNext; int ismGoal;
};
struct Hold {
    SMA *p;
    Hold(SMA *s) { p = s; s->v0(); }
    ~Hold() { p->v1(); }
};
extern "C" int FSmaRetracted(SMA *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(SM *, int);
extern "C" void RetractAsega(void *);
extern "C" void NotifySmaSpliceOnEnterState(SMA *, int, int);
extern "C" void ChooseSmaTransition(SMA *, int);

void SeekSma(SMA *sma, int oid)
{
    if (FSmaRetracted(sma) == 0) {
        Hold hold(sma);
        int target = IsmsFindSmRequired__FP2SM3OID(sma->psm, oid);
        if (sma->ismCur == target && (sma->ismGoal == target || sma->ismGoal == -1))
            return;
        if (sma->pasega != 0) {
            void *pasega = sma->pasega;
            sma->pasega = 0;
            RetractAsega(pasega);
        }
        int previous = sma->ismCur;
        sma->ismGoal = target;
        sma->ismCur = target;
        sma->ismNext = -1;
        NotifySmaSpliceOnEnterState(sma, previous, target);
        ChooseSmaTransition(sma, 0);
    }
}
