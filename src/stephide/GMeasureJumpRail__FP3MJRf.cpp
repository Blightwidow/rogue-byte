extern "C" {
#include "m2c_macros.h"


void GetAttachRopeSlide(s32, s32, s128 *, s128 *);
void MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(s32, s128, s32, s128, s128, s32, f32 *, s32, s32);

f32 GMeasureJumpRail__FP3MJRf(void *arg0) {
    s128 sp10;
    s128 sp20;
    f32 sp30;

    GetAttachRopeSlide(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 8), &sp10, &sp20);
    MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s128 *, 0x10), M2C_FIELD(arg0, s32 *, 8), sp10, sp20, 0, &sp30, 0, 0);
    return sp30;
}

}
