#include "m2c_macros.h"

M2C_UNK ConvertXfMat();          /* extern */
M2C_UNK ConvertXfMatrix4(); /* extern */
s128 ConvertXfPos();                  /* extern */
s128 DecomposeRotateMatrixEuler(); /* extern */
M2C_UNK InvertMatrix4Affine();        /* extern */
M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();     /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(); /* extern */
extern M2C_UNK RO_002A2D30;

void func_001B72B0(void *arg0, s32 arg1, s128 *arg2, s128 *arg3) {
    char sp[0x400];
    M2C_UNK sp130;
    M2C_UNK sp140;
    M2C_UNK sp1F0;
    M2C_UNK sp200;
    M2C_UNK sp210;
    M2C_UNK unksp12C;
    M2C_UNK unksp13C;
    M2C_UNK unksp14C;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 spA0;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 sp120;
    s128 sp150;
    s128 sp160;
    s128 sp170;
    s128 sp180;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    s128 sp1E0;
    s128 sp220;
    s128 sp260;
    void *sp2A0;
    s128 *sp2A4;
    s128 *sp2A8;
    s32 sp2AC;
    s32 sp2B0;
    s128 *sp2B4;
    s128 *sp2B8;
    s128 *sp2BC;
    s128 *sp2C0;
    s32 sp2C4;
    s128 **var_s0;
    s128 **var_s1_3;
    s128 *var_a1;
    s128 *var_a2;
    s128 *var_a2_2;
    s128 var_v0;
    s32 var_a0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_s2;
    void *temp_v1;

    sp2A0 = arg0;
    temp_v1 = M2C_FIELD(arg0, void **, 0x13F0);
    sp2A4 = arg3;
    sp2A8 = M2C_ERROR(/* Read from unset register $t0 */);
    if (M2C_FIELD(temp_v1, s32 *, 0x188) == 0) {
        ConvertXfMat(&sp30, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_v1, void **, 0x180), void **, 0x5C), s32 *, 0xA0), arg2);
        *sp2A4 = DecomposeRotateMatrixEuler(sp, sp30, sp30, sp40, sp50);
        var_v0 = ConvertXfPos(arg1, M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, void **, 0x13F0), void **, 0x180), void **, 0x58), s32 *, 0xA0), M2C_FIELD(arg2, s128 *, 0x30));
        goto block_25;
    }
    temp_s2 = M2C_FIELD(temp_v1, void **, 0x180);
    var_s1 = 0;
    InvertMatrix4Affine(&sp60, arg2);
    sp2AC = -1;
    sp2BC = &spE0;
    sp2C0 = &sp220;
    sp2B4 = &sp260;
    sp2B8 = &sp150;
    sp2B0 = -1;
    var_a0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, void **, 0x13F0), void **, 0x188), s32 *, 0x50);
    if (var_a0 != arg1) {
        var_a1 = sp;
        do {
            *var_a1 = var_a0;
            var_a1 += 4;
            sp2AC = ((var_a0 ^ M2C_FIELD(temp_s2, s32 *, 0x58)) == 0) ? var_s1 : sp2AC;
            sp2B0 = ((var_a0 ^ M2C_FIELD(temp_s2, s32 *, 0x5C)) == 0) ? var_s1 : sp2B0;
            var_a0 = M2C_FIELD(var_a0, s32 *, 0xA0);
            var_s1 += 1;
        } while (var_a0 != arg1);
    }
    var_s1_2 = var_s1 - 1;
    sp2C4 = sp2AC - 1;
    ConvertXfMatrix4(&spA0, M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, void **, 0x13F0), void **, 0x188), s32 *, 0x50), M2C_FIELD(temp_s2, s32 *, 0x5C), &RO_002A2D30);
    ConvertXfMatrix4(sp2BC, M2C_FIELD(M2C_FIELD(temp_s2, s32 *, 0x5C), s32 *, 0xA0), arg1, &RO_002A2D30);
    __ml__FRC7MATRIX4T0(&sp120, &spA0, M2C_FIELD(M2C_FIELD(sp2A0, void **, 0x13F0), s32 *, 0x188) + 0x60);
    spC0 = sp140;
    spA0 = sp120;
    spB0 = sp130;
    spD0 = sp150;
    __ml__FRC7MATRIX4T0(&sp1A0, &spA0, &sp60, sp130);
    __ml__FRC7MATRIX4T0(&sp160, &sp1A0, sp2BC);
    InvertMatrix4Affine(&sp120, &sp160);
    sp40 = DecomposeRotateMatrixEuler(&sp120);
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp160, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    __as__6VECTORG9VU_VECTOR(sp2B8, M2C_FIELD(*(sp + (sp2B0 * 4)), s128 *, 0x30));
    sp120 = sp160;
    M2C_FIELD(&sp120, s128 *, 0x10) = sp170;
    M2C_FIELD(&sp120, s128 *, 0x20) = sp180;
    unksp14C = 0;
    unksp13C = 0;
    unksp12C = 0;
    M2C_FIELD(&sp120, f32 *, 0x3C) = 1.0f;
    sp1A0 = M2C_FIELD(&RO_002A2D30, s128 *, 0);
    sp1B0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x10);
    sp1C0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x20);
    sp1D0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x30);
    sp160 = M2C_FIELD(&RO_002A2D30, s128 *, 0);
    sp170 = M2C_FIELD(&RO_002A2D30, s128 *, 0x10);
    sp180 = M2C_FIELD(&RO_002A2D30, s128 *, 0x20);
    sp190 = M2C_FIELD(&RO_002A2D30, s128 *, 0x30);
    if (sp2AC < var_s1_2) {
        var_s0 = (var_s1_2 * 4) + sp;
        do {
            if (var_s1_2 != sp2B0) {
                var_a2 = *var_s0;
            } else {
                var_a2 = &sp120;
            }
            var_s1_2 -= 1;
            __ml__FRC7MATRIX4T0(&sp1E0, &sp160, var_a2);
            sp160 = sp1E0;
            sp170 = sp1F0;
            sp180 = sp200;
            sp190 = sp210;
            var_s0 -= 4;
        } while (sp2AC < var_s1_2);
    }
    var_s0_2 = sp2C4;
    if (var_s0_2 >= 0) {
        var_s1_3 = (var_s0_2 * 4) + sp;
        do {
            if (var_s0_2 != sp2B0) {
                var_a2_2 = *var_s1_3;
            } else {
                var_a2_2 = &sp120;
            }
            var_s1_3 -= 4;
            __ml__FRC7MATRIX4T0(&sp1E0, &sp1A0, var_a2_2);
            sp1A0 = sp1E0;
            sp1B0 = sp1F0;
            sp1C0 = sp200;
            var_s0_2 -= 1;
            sp1D0 = sp210;
        } while (var_s0_2 >= 0);
    }
    __ml__FRC7MATRIX4T0(&sp1E0, &sp1A0, M2C_FIELD(M2C_FIELD(sp2A0, void **, 0x13F0), s32 *, 0x188) + 0x60);
    sp1D0 = sp210;
    sp1A0 = sp1E0;
    sp1B0 = sp1F0;
    sp1C0 = sp200;
    __ml__FRC7MATRIX4T0(sp2B4, &sp1A0, &sp60, sp1F0);
    __ml__FRC7MATRIX4T0(sp2C0, sp2B4, &sp160);
    InvertMatrix4Affine(&sp1E0, sp2C0);
    sp50 = sp210;
    if (sp2A4 != NULL) {
        *sp2A4 = sp40;
    }
    var_v0 = sp50;
    if (sp2A8 != NULL) {
block_25:
        *sp2A8 = var_v0;
    }
}
