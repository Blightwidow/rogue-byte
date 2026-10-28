#include "sly2.h"
struct RSMG { int oidRoot; int oidSM; int oidTrigger; int oidUntrigger; };
struct VT { char pad[8]; short delta; short index; void (*fn)(void *); };
struct OBJ { int a, b, c; VT *vt; };
extern "C" int CploFindSwObjects_thunk(void *, int, int, int, int, void **);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" OBJ *PsmaFindAlo(void *, int);
extern "C" void SubscribeLoObject(void *, void *);
extern "C" void SnapSmaToGoal(void *, int);
extern "C" void SetSmaGoal__FP3SMA3OID(void *, int);
void TriggerRsmgEntry(void *sw, RSMG *record, int context, int flags, void *subscriber, void **out)
{
    void *roots[4];
    if (out)
        *out = 0;
    if (CploFindSwObjects_thunk(sw, 0x204, record->oidRoot, context, 1, roots) != 1)
        return;
    if (!FIsBasicDerivedFrom(roots[0], 0x30))
        return;
    OBJ *sma = PsmaFindAlo(roots[0], record->oidSM);
    if (!sma)
        return;
    int goal = (flags & 1) ? record->oidTrigger : record->oidUntrigger;
    if (goal == -1)
        return;
    if (subscriber) {
        *out = sma;
        sma->vt->fn((char *)sma + sma->vt->delta);
        SubscribeLoObject(sma, subscriber);
    }
    if (flags & 2)
        SnapSmaToGoal(sma, goal);
    else
        SetSmaGoal__FP3SMA3OID(sma, goal);
}
