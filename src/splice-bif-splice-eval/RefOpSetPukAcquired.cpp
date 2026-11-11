#include "types.h"
extern "C" {

struct RefCell { s32 tag; s32 value; s32 field_0x8; s32 field_0xC; };
void CRef_CopyConstruct(s32, void *);
void CRef_Destruct(void *);
void SetGadgetAcquired(s32, s32);
void SetTag__4CRef4TAGK(void *, s32);

s32 RefOpSetPukAcquired(s32 arg0, s32 arg1, RefCell *arg2) {
    char sp[0x10];
    SetTag__4CRef4TAGK(sp, 0x24);
    SetGadgetAcquired(arg2->value, arg2->field_0xC);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
