#include "sly2.h"
struct CRef;
struct Mat125168 { QW row0; QW row1; QW row2; QW row3; };
struct Near125168 { char pad[0x4C]; float nearClip; char pad2[0x10]; Mat125168 mat; };
extern "C" Near125168 B_002DDF40;
extern "C" CRef *CRef_ConstructVectorValue(CRef *, QW);
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" CRef *RefOpNearClipCenter(CRef *result)
{
    QW vec = __builtin_pcpyld(Word(0.0f), __builtin_pextlw(Word(0.0f), Word(B_002DDF40.nearClip)));
    QW shifted;
    asm("lqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tqmtc2.ni %1, vf5\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddaz.xyz ACC, vf1, vf5z\n\tvmaddw.xyz vf5, vf3, vf0w\n\tqmfc2.ni %0, vf5"
        : "=r" (shifted) : "r" (vec), "m" (B_002DDF40.mat.row0), "m" (B_002DDF40.mat.row3), "m" (B_002DDF40.mat.row1), "m" (B_002DDF40.mat.row2));
    CRef_ConstructVectorValue(result, shifted);
    return result;
}
