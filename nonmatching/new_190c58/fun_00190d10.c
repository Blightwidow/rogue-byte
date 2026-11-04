#include "m2c_macros.h"

M2C_UNK ConvertXfVec(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK PosJtHangGrip();                            /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SolveIkLimb(void *, s32);                   /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(void *, M2C_UNK);  /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(void *, s32, void *);   /* extern */
extern M2C_UNK B_003DD490;

void func_00190D10(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_v0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0_2;

    PosJtHangGrip();
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1960($s1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x19A4));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x19C4), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */));
    temp_s0 = M2C_FIELD(arg0, void **, 0x19C4);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($s0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf2 */);
    __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x19C4), s32 *, 0xA4) = temp_v0;
    temp_s0_2 = M2C_FIELD(arg0, void **, 0x19C4);
    __ml__FRC7MATRIX4T0(sp, M2C_FIELD(temp_s0_2, s32 *, 0xA0) + 0x40, temp_s0_2);
    M2C_FIELD(temp_s0_2, s128 *, 0x40) = sp0;
    M2C_FIELD(temp_s0_2, s128 *, 0x50) = sp10;
    M2C_FIELD(temp_s0_2, s128 *, 0x60) = sp20;
    M2C_FIELD(temp_s0_2, s128 *, 0x70) = sp30;
    SolveIkLimb(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x19CC), s32 *, 0xA8));
    temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x94)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x90));
}
