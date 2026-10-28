#include "sly2.h"
struct ANIMREC { int nState; int oid; int oidSel; int oidAnim; int fGated; int nLevelRow; };
struct SW { char pad[0x3AFC]; int count; };
struct SMA;
extern "C" SW B_003DD490;
extern "C" int IdCurrentLevel(void);
extern "C" int CploFindSwObjects_thunk(SW *, int, int, void *, int, void **);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" SMA *PsmaFindAlo(void *, int);
extern "C" void SnapSmaToGoal(SMA *, int);
extern "C" void SetSmaGoal__FP3SMA3OID(SMA *, int);
void func_00162250(void *owner, ANIMREC *anim, int state, int play)
{
    if (anim->nState != -1 && anim->nState != state)
        return;
    if (anim->fGated != 0 && play == 0)
        return;
    if (anim->nLevelRow != -1 && anim->nLevelRow != IdCurrentLevel())
        return;
    void *object;
    if (CploFindSwObjects_thunk(&B_003DD490, 0x205, anim->oid, 0, 1, &object) != 1)
        return;
    if (!FIsBasicDerivedFrom(object, 0x30))
        return;
    SMA *sma = PsmaFindAlo(object, anim->oidSel);
    if (sma == 0)
        return;
    int oidAnim = anim->oidAnim;
    if (anim->nState == -1) {
        switch (state) {
        case 0: oidAnim = 0x612; break;
        case 1: oidAnim = 0x613; break;
        case 2: oidAnim = 0x614; break;
        case 3: oidAnim = 0x615; break;
        }
    }
    if (oidAnim != -1) {
        if (play == 1 || play == 4)
            SnapSmaToGoal(sma, oidAnim);
        else
            SetSmaGoal__FP3SMA3OID(sma, oidAnim);
    }
}
