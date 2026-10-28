#include "sly2.h"
struct STEP { char pad0[0x58]; int pxfLinear; int pxfAngular; char pad1[0x204]; int keyHull; int pgeomHull; char goals[0x28]; int pcrv; };
extern "C" void PostSoLoad(STEP *);
extern "C" int PcrvNew(int, int);
extern "C" void SetXfKind(STEP *, int, int);
extern "C" int PpartFindAlo(STEP *, int);
extern "C" void CloneStepHullGeom(STEP *, int);
extern "C" void func_001F2AD0(STEP *, int);
extern "C" void GoalStack_AllocGoals(void *);
extern "C" void PostStepLoad(STEP *pstep)
{
    PostSoLoad(pstep);
    pstep->pcrv = PcrvNew(0x2C9, 0x10);
    SetXfKind(pstep, pstep->pxfLinear, 1);
    SetXfKind(pstep, pstep->pxfAngular, 1);
    if (pstep->keyHull != -1) {
        int pgeom = PpartFindAlo(pstep, pstep->keyHull);
        pstep->pgeomHull = pgeom;
        if (pgeom != 0) {
            CloneStepHullGeom(pstep, pgeom);
            func_001F2AD0(pstep, pstep->pgeomHull);
        }
    }
    GoalStack_AllocGoals(pstep->goals);
}
