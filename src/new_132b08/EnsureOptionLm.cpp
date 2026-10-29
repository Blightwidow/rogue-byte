extern "C" {
#include "m2c_macros.h"

void CRef_ConstructLm(s8 *, s32);
void CRef_Destruct(s8 *);
void RefEnsureOption__FP5BASICiP4CRef(s8 *, s32, s32, s8 *);

void EnsureOptionLm(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp_first[0x10];
    s8 sp_second[0x10];

    CRef_ConstructLm(sp_first, arg2);
    RefEnsureOption__FP5BASICiP4CRef(sp_second, arg0, arg1, sp_first);
    CRef_Destruct(sp_second);
    CRef_Destruct(sp_first);
}

}
