#include "m2c_macros.h"

extern s128 g_2a2dc0;

s128 SetEmitdvEmitb__FP6EMITDVP5EMITB(void *arg0, void *arg1) {
    s128 var_v0;

    M2C_FIELD(arg0, s128 *, 0) = (s128) M2C_FIELD(arg1, s128 *, 0x60);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($a1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    var_v0 = g_2a2dc0;
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a2) */);
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) M2C_FIELD(arg1, f32 *, 0x80);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(arg1, f32 *, 0x58);
    return var_v0;
}
