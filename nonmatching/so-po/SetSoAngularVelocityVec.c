#include "m2c_macros.h"

s128 ConvertXfVec(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 FXfKindHasVelocity(s16);                        /* extern */
M2C_UNK InvertMatrix3(M2C_UNK *, void *);           /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(void *, s128, s128, s128); /* extern */
M2C_UNK SetXfKind(void *, void *, M2C_UNK);         /* extern */
M2C_UNK WakeXf(void *, void *);                     /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */
M2C_UNK func_001F5078(void *);                      /* extern */
M2C_UNK func_001F8668(void *, M2C_UNK);             /* extern */

void SetSoAngularVelocityVec(void *arg0, s128 arg1) {
    char sp[0x400];
    M2C_UNK sp60;
    s128 spC0;
    s128 spD0;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1;
    void *var_v0;

    spD0 = arg1;
    temp_s1 = M2C_FIELD(arg0, void **, 0x5C);
    if (temp_s1 != NULL) {
        if (M2C_FIELD(temp_s1, s32 *, 0x94) == 6) {
            var_v0 = temp_s1 + 0xB0;
            if (FXfKindHasVelocity(M2C_FIELD(temp_s1, s16 *, 0x98)) == 0) {
                SetXfKind(arg0, temp_s1, 1);
                var_v0 = temp_s1 + 0xB0;
            }
            temp_s0 = temp_s1 + 0x40;
            M2C_FIELD(var_v0, s32 *, 4) = 0;
            M2C_FIELD(var_v0, s32 *, 8) = 0;
            M2C_FIELD(temp_s1, s32 *, 0xB0) = 0;
            temp_v1 = M2C_FIELD(arg0, void **, 0xC);
            spC0 = M2C_FIELD(temp_v1, s128 (**)(void *), 0x114)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x110));
            NormalizeRotateMatrix3__FP7MATRIX3(sp, M2C_FIELD(temp_s1, s128 *, 0x40), M2C_FIELD(temp_s0, s128 *, 0x10), M2C_FIELD(temp_s0, s128 *, 0x20));
            InvertMatrix3(&sp60, sp);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xd0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf6, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf6, $vf4z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf6, $vf5z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf7x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf7y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf7z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
            M2C_FIELD(temp_s1, s32 *, 0xB0) = ConvertXfVec(0, M2C_FIELD(temp_s1, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
            WakeXf(arg0, temp_s1);
            func_001F4BF8(arg0);
            func_001F5078(arg0);
            func_001F8668(arg0, 0);
        }
    }
}
