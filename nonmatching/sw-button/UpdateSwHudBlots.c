#include "m2c_macros.h"

s32 FDrawBlotMovie(void *);                         /* extern */
f32 GSmoothA__FffffP4SMPAPf(M2C_UNK *, s32, f32, M2C_UNK32, f32, f32); /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
extern M2C_UNK D_002C3E88;
extern f32 D_FLT_002C3E80;
extern M2C_UNK g_2dded0;

void UpdateSwHudBlots(void *arg0) {
    f32 temp_s0_2;
    f32 var_f20;
    s32 var_s3;
    s32 var_s4;
    void *temp_s0;
    void *temp_v0;
    void *var_s1;

    var_f20 = 0.0f;
    var_s1 = arg0 + 0x3BA0;
    var_s3 = arg0 + 0x3BA4;
    var_s4 = 0;
    do {
        temp_s0 = M2C_FIELD(var_s1, void **, 0);
        if (temp_s0 != NULL) {
            if (FDrawBlotMovie(temp_s0) != 0) {
                temp_v0 = M2C_FIELD(temp_s0, void **, 0xF8);
                if (M2C_FIELD(var_s1, s32 *, 8) != 0) {
                    M2C_FIELD(temp_v0, f32 *, 0x14) = var_f20;
                    M2C_FIELD(var_s1, M2C_UNK32 *, 4) = 0;
                    M2C_FIELD(var_s1, s32 *, 8) = 0;
                } else {
                    M2C_FIELD(M2C_FIELD(temp_s0, void **, 0xF8), f32 *, 0x14) = GSmoothA__FffffP4SMPAPf(&D_002C3E88, var_s3, M2C_FIELD(temp_v0, f32 *, 0x14), M2C_FIELD(var_s1, M2C_UNK32 *, 4), var_f20, M2C_FIELD(&g_2dded0, f32 *, 4));
                }
                var_f20 += D_FLT_002C3E80;
                if (var_s4 == 3) {
                    M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f21 */);
                    temp_s0_2 = M2C_FIELD(&g_2dded0, f32 *, 0);
                    if (M2C_BITWISE(s32, temp_s0_2) != M2C_FIELD(arg0, s32 *, 0x4770)) {
                        SetEmitterUnpositioned(NewEmitter((M2C_BITWISE(s32, temp_s0_2) & 1) ? 0x30 : 0x31), 0);
                        M2C_FIELD(arg0, s32 *, 0x4770) = M2C_BITWISE(s32, temp_s0_2);
                    }
                }
            } else {
                goto block_6;
            }
        } else {
block_6:
            M2C_FIELD(var_s1, s32 *, 8) = 1;
        }
        var_s4 += 1;
        var_s3 += 0xC;
        var_s1 += 0xC;
    } while (var_s4 < 4);
}
