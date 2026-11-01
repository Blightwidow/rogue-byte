#include "m2c_macros.h"

M2C_UNK ActivateAct();                              /* extern */
extern s128 g_2a2da0;

void func_0012E120(void *arg0) {
    ActivateAct();
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xB0) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xC0) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0001f) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xC0) = (s128) g_2a2da0;
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc0($v1) */);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xD0) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xE0) = 0;
}
