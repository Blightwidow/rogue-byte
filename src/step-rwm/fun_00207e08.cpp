#include "sly2.h"
struct STEPGUARD;
struct CRef;
extern "C" int GrfsgsFromRef(CRef *);
extern "C" int PguardanimEnsure(STEPGUARD *, int);
extern "C" void func_00207D98(STEPGUARD *, CRef *, int, float, float, float, float);
extern "C" void BindAnimref(int, STEPGUARD *);

void func_00207E08(STEPGUARD *pstepguard, CRef *pref, int oid, float f0, float f1, float f2, float f3)
{
    int panim = PguardanimEnsure(pstepguard, GrfsgsFromRef(pref));
    func_00207D98(pstepguard, pref, oid, f0, f1, f2, f3);
    BindAnimref(panim, pstepguard);
}
