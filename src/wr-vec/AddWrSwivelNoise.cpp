#include "types.h"

extern "C" {
s32 AddOnzOnze__FP3ONZffff(s32, f32, f32, f32, f32);
s32 PwreGetWrBend__FP2WR4ENSK(s32, s32);

void AddWrSwivelNoise(s32 wr, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    AddOnzOnze__FP3ONZffff(PwreGetWrBend__FP2WR4ENSK(wr, 1) + 0x80, fparg0, fparg1, fparg2, fparg3);
}

}
