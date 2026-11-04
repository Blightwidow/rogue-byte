typedef signed char s8; typedef short s16; typedef int s32;
typedef float f32;

extern "C" {
s8 *PwreGetWrCircle__FP2WR4ENSK(s8 *, s32);

void SetWrWavelength__FP2WRf(s8 *arg0, f32 fparg0) {
    s8 *temp_v0;

    temp_v0 = PwreGetWrCircle__FP2WR4ENSK(arg0, 1);
    if (fparg0 == 0.0f) {
        *(f32 *)(temp_v0 + 0x64) = 0.0f;
    } else {
        *(f32 *)(temp_v0 + 0x64) = 1.0f / fparg0;
    }
}

}
