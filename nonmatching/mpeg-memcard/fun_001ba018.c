#include "m2c_macros.h"

f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK PostGuardLoad();                            /* extern */
M2C_UNK PredictAsegEffect(s32, void *, s32, s32, f32, M2C_UNK); /* extern */
M2C_UNK SetSoMass__FP2SOf(void *, M2C_UNK);         /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK D_002C0A50;

void func_001BA018(void *arg0) {
    PostGuardLoad();
    SetSoProperties(arg0, 3, &D_002C0A50);
    PredictAsegEffect(M2C_FIELD(arg0, s32 *, 0x1020), arg0, M2C_FIELD(arg0, s32 *, 0x1030), M2C_FIELD(M2C_FIELD(arg0, void **, 0x1034), s32 *, 0xA0), *PeaFindAsegLabel(M2C_FIELD(arg0, s32 *, 0x1020), 0x5DB), 0x3F800000);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    M2C_FIELD(arg0, s32 *, 0x1060) = 0;
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1040($s0) */);
    M2C_FIELD(arg0, s32 *, 0x106C) = 1;
    SetSoMass__FP2SOf(arg0, 0x3E800000);
}
