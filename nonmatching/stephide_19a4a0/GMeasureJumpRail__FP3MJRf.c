#include "m2c_macros.h"

M2C_UNK GetAttachRopeSlide(s32, s32, s128 *, s128 *); /* extern */
M2C_UNK MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(s32, s128, s32, s128, s32); /* extern */

f32 GMeasureJumpRail__FP3MJRf(void *arg0) {
    s128 sp10;
    s128 sp20;
    f32 sp30;

    GetAttachRopeSlide(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 8), &sp10, &sp20);
    MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s128 *, 0x10), M2C_FIELD(arg0, s32 *, 8), sp10, 0);
    return sp30;
}
