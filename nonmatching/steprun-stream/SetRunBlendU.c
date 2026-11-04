#include "m2c_macros.h"

M2C_UNK CalculateBlrunV(void *);                    /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
M2C_UNK func_0020BB48(void *);                      /* extern */

s32 SetRunBlendU(void *arg0, f32 fparg0) {
    f32 var_f0;

    if (M2C_FIELD(arg0, s32 *, 0x54) != 0) {
        M2C_FIELD(arg0, f32 *, 0x50) = fparg0;
        var_f0 = 1.0f - fparg0;
    } else {
        var_f0 = 1.0f;
        M2C_FIELD(arg0, f32 *, 0x50) = 0.0f;
    }
    M2C_FIELD(arg0, f32 *, 0x10) = var_f0;
    ReblendAsegbl(M2C_FIELD(arg0, s32 *, 4));
    func_0020BB48(arg0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    CalculateBlrunV(arg0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
}
