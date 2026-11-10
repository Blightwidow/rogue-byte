#include "types.h"
extern "C" {
void CRef_CopyConstruct(s32, s8 *);
void CRef_Destruct(s8 *);
s8 *CRef_SetBasic(s8 *, s32 *);
extern s32 B_003DA0C0;

s32 func_00125690(s32 arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));

    *(s32 *)sp = -1;
    CRef_SetBasic(sp, &B_003DA0C0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}

}
