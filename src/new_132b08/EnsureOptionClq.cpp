#include "types.h"
extern "C" {
void CRef_ConstructClq(s8 *, s32);
void CRef_Destruct(s8 *);
void RefEnsureOption__FP5BASICiP4CRef(s8 *, s32, s32, s8 *);

void EnsureOptionClq(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 sp10[0x10] __attribute__((aligned(16)));

    CRef_ConstructClq(sp, arg2);
    RefEnsureOption__FP5BASICiP4CRef(sp10, arg0, arg1, sp);
    CRef_Destruct(sp10);
    CRef_Destruct(sp);
}

}
