#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
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
    float g = ref.g;
    CRef_Destruct(&ref);
    return g;
}
extern "C" float GetSuck(DIFF *pdiff)
{
    float result;
    if (B_003E0F9C != 0) {
        result = *B_003E0F9C->psuck;
    } else if (pdiff->p0 != 0 && pdiff->p1 != 0 && pdiff->p2 != 0) {
        float a = Load(pdiff->p0);
        float b = Load(pdiff->p1);
        float c = Load(pdiff->p2);
        result = (a + b + c) * 0.33333334f;
    } else {
        result = 0.0f;
    }
    return result;
}
