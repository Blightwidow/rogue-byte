#include "m2c_macros.h"

M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, void *); /* extern */
M2C_UNK ConvertXfPos(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *, s128, s128, s128, s128); /* extern */
s32 PmatLoWorld(void *);                            /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(void *, M2C_UNK);          /* extern */
M2C_UNK SetXfKind(void *, void *, M2C_UNK);         /* extern */
M2C_UNK TiltMatUpright__FP7MATRIX3N20(s32, M2C_UNK, void *); /* extern */
M2C_UNK func_00147F40(M2C_UNK *);                   /* extern */
M2C_UNK func_001A58D0(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_001F68A8(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void SetHbskHbsks(void *arg0, s16 arg1) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp30;
    s32 temp_v1;
    s32 var_s2;
    void *temp_a1;
    void *temp_v0;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x17C);
    if (temp_v1 != arg1) {
        if (temp_v1 == 2) {
            if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
                func_001A58D0(0, 0xF);
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x58), 1);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x9A) = 0;
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x5C), 1);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x9A) = 0;
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), g_2a2dd0);
                SetSoCnstrForce(arg0, 0);
                SetSoCnstrTorque(arg0, 0);
                func_001F68A8(arg0, 0);
            }
            temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x18), 6, 0, 0);
            func_00147F40(&B_003DD490);
            M2C_FIELD(arg0, void **, 0x190) = NULL;
        }
        if (arg1 == 2) {
            if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
                SetSoCnstrForce(arg0, 1);
                SetSoCnstrTorque(arg0, 1);
                temp_a1 = M2C_FIELD(arg0, void **, 0x190);
                var_s2 = M2C_FIELD(temp_a1, s32 *, 0x10BC);
                if (var_s2 == 0) {
                    var_s2 = M2C_FIELD(temp_a1, s32 *, 0x60);
                }
                temp_v1_4 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, void *, s32, M2C_UNK), 0x54)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x50), temp_a1, var_s2, 3);
                TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(arg0), 0, sp);
                ConvertXfMat(&sp30, 0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0xA0), sp);
                DecomposeRotateMatrixEuler(sp, sp30, sp30, sp40, sp50);
                M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x5C), 7);
                temp_v1_5 = M2C_FIELD(arg0, void **, 0x5C);
                M2C_FIELD(temp_v1_5, s32 *, 0xC0) = 0;
                temp_v1_6 = temp_v1_5 + 0xC0;
                M2C_FIELD(temp_v1_6, f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
                M2C_FIELD(temp_v1_6, s32 *, 4) = 0;
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x9A) = arg1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($s2) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf2, $vf1 */);
                ConvertXfPos(0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */));
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x58), 7);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s128 *, 0xC0) = (s128) M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x9A) = arg1;
                func_001F68A8(arg0, 1);
            }
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x18), 5, 0, 0);
        }
        M2C_FIELD(arg0, s32 *, 0x17C) = (s32) arg1;
        M2C_FIELD(arg0, f32 *, 0x180) = (f32) g_2dded0;
    }
}
