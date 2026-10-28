#include "m2c_macros.h"

s128 DecomposeRotateMatrixEuler(M2C_UNK *);         /* extern */
s32 FActiveCplcy(M2C_UNK *);                        /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(void *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DE440;
extern s128 g_2a2dd0;
extern f32 g_2dded0;
extern M2C_UNK g_2ddfa0;

void StartSeqnodeCameraMove(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    void **sp0;
    f32 *var_s0;
    f32 *var_s1;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s3_2;
    u32 var_s6;
    void **var_s5;
    void *temp_s2;

    if (M2C_FIELD(arg1, f32 *, 0x40) == 0.0f) {
        var_f0 = 3.4028235e38f;
    } else {
        M2C_FIELD(arg2, s32 *, 4) = 0;
        var_f0 = g_2dded0 + fparg0;
    }
    M2C_FIELD(arg0, f32 *, 0x80) = var_f0;
    M2C_FIELD(arg0, void **, 0x84) = (void *) (arg1 + 0x10);
    M2C_FIELD(arg0, void **, 0x88) = (void *) (arg2 + 0x10);
    M2C_FIELD(arg0, f32 *, 0x8C) = fparg0;
    var_s1 = arg1 + 0x20;
    M2C_FIELD(arg0, s32 *, 0x90) = 1;
    var_s0 = arg2 + 0x20;
    sp0 = arg0 + 0x84;
    var_s2 = 2;
    M2C_FIELD(arg0, s32 *, 0x9C) = 1;
    M2C_FIELD(arg0, s32 *, 0x94) = (s32) M2C_FIELD(arg1, s32 *, 0x44);
    M2C_FIELD(arg0, void **, 0x98) = arg0;
    do {
        var_s2 -= 1;
        temp_f0 = RadNormalize__Ff(*var_s0 - *var_s1);
        temp_f1 = *var_s1;
        var_s1 += 4;
        *var_s0 = temp_f1 + temp_f0;
        var_s0 += 4;
    } while (var_s2 >= 0);
    var_s5 = sp0;
    var_s6 = 0;
    do {
        temp_s2 = *var_s5;
        var_s3 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(temp_s2, s128 *, 0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v1, $s1 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), 0x38D1B717) != 0)) {
            var_s3 = (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $s1 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), 0x38D1B717) != 0) ? 1 : 0;
        }
        if (var_s3 != 0) {
            M2C_FIELD(temp_s2, s128 *, 0) = (s128) M2C_FIELD(&g_2ddfa0, s128 *, 0x30);
        }
        var_s3_2 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(temp_s2, s128 *, 0x10), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v1, $s1 */), 0x38D1B717) != 0)) {
            var_s3_2 = (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $s1 */), 0x38D1B717) != 0) ? 1 : 0;
        }
        if (var_s3_2 != 0) {
            M2C_FIELD(temp_s2, s128 *, 0x10) = DecomposeRotateMatrixEuler(&g_2ddfa0);
        }
        if (M2C_FIELD(temp_s2, f32 *, 0x20) == 0.0f) {
            M2C_FIELD(temp_s2, f32 *, 0x20) = (f32) M2C_FIELD(&B_002DDF40, f32 *, 0x20);
        }
        var_s6 += 1;
        var_s5 += 4;
    } while (var_s6 < 2U);
    if (M2C_FIELD(arg0, f32 *, 0x8C) == 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x8C) = 3.4028235e38f;
    }
    if (FActiveCplcy(&B_002DE440) != 0) {
        RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DE440 - 0x500, 2, 0xA, &B_002DE440);
    }
    SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DE440 - 0x500, 0xA, &B_002DE440, 0);
}
