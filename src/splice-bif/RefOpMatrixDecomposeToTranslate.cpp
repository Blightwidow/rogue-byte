#include "types.h"
extern "C" {

struct RefCell { s32 tag; s32 value; s32 field_0x8; s32 field_0xC; };
void CRef_ConstructVector(void *, s32);
void CRef_CopyConstruct(s32, void *);
void CRef_Destruct(void *);

s32 RefOpMatrixDecomposeToTranslate(s32 arg0, s32 arg1, RefCell *arg2) {
    char sp[0x10];
    CRef_ConstructVector(sp, arg2->value + 0x30);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
