#include "types.h"
extern "C" {
struct CRefLocal { s32 pad0; s32 field4; s32 pad8; s32 padC; };
struct RefCell { s32 tag; s32 value; s32 field_0x8; s32 field_0xC; };
void CRef_CopyConstruct(s32, CRefLocal *);
void CRef_Destruct(CRefLocal *);
void CalculateDmat4(s32, s32, s32);
void SetTag__4CRef4TAGK(CRefLocal *, s32);
s32 RefOpMatrixCalculateDmat(s32 arg0, s32 arg1, RefCell *arg2) {
    CRefLocal local __attribute__((aligned(16)));
    SetTag__4CRef4TAGK(&local, 0x1B);
    CalculateDmat4(arg2->value, arg2->field_0xC, local.field4);
    CRef_CopyConstruct(arg0, &local);
    CRef_Destruct(&local);
    return arg0;
}
}
