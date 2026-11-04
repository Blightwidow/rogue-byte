#include "m2c_macros.h"

M2C_UNK InitRip__FP3RIPP6VECTORfP2SO();             /* extern */
extern M2C_UNK D_002C1F40;

M2C_UNK *InitBublet__FP6BUBLETP6VECTORfP2SO(void *arg0) {
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, f32 *, 0x20) = 0.33f;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($s0) */);
    M2C_FIELD(arg0, f32 *, 0xC4) = -8.0f;
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    return &D_002C1F40;
}
