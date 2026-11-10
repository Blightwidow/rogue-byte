/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "types.h"
extern "C" {
struct RefCell { s32 tag; f32 value; };
struct ClqCoefficients { f32 field_0x0; f32 field_0x4; f32 field_0x8; };
struct RefClqArgs { s32 tag; ClqCoefficients *clq; RefCell coerce; };
void CRef_Destruct(s8 *);
void CRef_RefCoerceF32(s8 *, RefCell *);
RefCell *RefOpClqEvaluate(RefCell *arg0, s8 *arg1, RefClqArgs *arg2) {
    union { s8 bytes[0x10]; struct { s32 tag; f32 value; } cell; } local __attribute__((aligned(16)));
    ClqCoefficients *clq;
    clq = arg2->clq;
    CRef_RefCoerceF32(local.bytes, &arg2->coerce);
    arg0->value = (f32) (clq->field_0x0 + (local.cell.value * (clq->field_0x4 + (local.cell.value * clq->field_0x8))));
    arg0->tag = 0x16;
    CRef_Destruct(local.bytes);
    return arg0;
}
}
