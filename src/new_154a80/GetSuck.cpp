#include "sly2.h"
struct CRef { int tag; union { float g; int n; }; int field8; int fieldC; };
struct DIFF { char pad[8]; int p0, p1, p2; };
struct LS { char pad[0xA8]; float *psuck; };
extern LS *B_003E0F9C;
extern int B_003D4A60;
extern "C" void RefGetGameSaveValue(CRef *, int, int *);
extern "C" void CRef_Destruct(CRef *);
static inline float Load(int path)
{
    CRef ref;
    RefGetGameSaveValue(&ref, path, &B_003D4A60);
    float value = ref.g;
    CRef_Destruct(&ref);
    return value;
}
// The mean is two statements, `suck = first + second + third; suck *= 0.33333334f;`. With `suck` set before the 1/3 constant is loaded,
// both are live at once, so `suck` takes $f20 and the ending is retail's `mtc1 $zero,$f20; mov.s $f0,$f20`.
extern "C" float GetSuck(DIFF *pdiff)
{
    float suck;
    if (B_003E0F9C != 0) {
        suck = *B_003E0F9C->psuck;
    } else if (pdiff->p0 != 0 && pdiff->p1 != 0 && pdiff->p2 != 0) {
        float first = Load(pdiff->p0);
        float second = Load(pdiff->p1);
        float third = Load(pdiff->p2);
        suck = first + second + third;
        suck *= 0.33333334f;
    } else {
        suck = 0.0f;
    }
    return suck;
}
