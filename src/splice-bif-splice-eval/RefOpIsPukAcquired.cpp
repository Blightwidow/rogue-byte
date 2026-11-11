#include "types.h"
extern "C" {

struct RefCell { s32 tag; s32 value; };
void CRef_CopyConstruct(s32, void *);
void CRef_Destruct(void *);
void *CRef_SetBool(void *, s32);
s32 FGadgetAcquired(s32, s32);

s32 RefOpIsPukAcquired(s32 arg0, s32 arg1, RefCell *arg2) {
    char sp[0x10];

    *(s32 *)sp = -1;
    CRef_SetBool(sp, FGadgetAcquired(arg2->value, arg1) != 0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
