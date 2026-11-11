#include "types.h"
extern "C" {
struct RefCell { s32 tag; s32 value; };
struct RefLmArgs { s32 tag; s32 lm; RefCell coerce; };
void CRef_Destruct(s8 *);
s32 CRef_RefCoerceF32(s8 *, RefCell *);
s32 FCheckLm__FP2LMf(s32, f32);
RefCell *RefOpLmCheck(RefCell *arg0, s32 arg1, RefLmArgs *arg2) {
    union { s8 bytes[0x10]; struct { s32 tag; f32 value; } cell; } local __attribute__((aligned(16)));
    s32 lm;
    s32 result;
    lm = arg2->lm;
    CRef_RefCoerceF32(local.bytes, &arg2->coerce);
    result = FCheckLm__FP2LMf(lm, local.cell.value) != 0;
    arg0->tag = 0x17;
    arg0->value = result;
    CRef_Destruct(local.bytes);
    return arg0;
}
}
