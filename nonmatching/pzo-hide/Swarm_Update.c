#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
f32 GRandInRange(M2C_UNK, M2C_UNK);                 /* extern */
f32 GSmoothA__FffffP4SMPAPf(M2C_UNK *, void *, f32, f32, f32, f32); /* extern */
M2C_UNK GetPathPosFromS(s32, void *, void *, f32);  /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SMaxCrv(s32);                               /* extern */
M2C_UNK SwarmGroup_UpdateTargets(void *, void *);   /* extern */
M2C_UNK Swarm_UpdateRiderState(void *, void *);     /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK D_002BE888;
extern f32 D_FLT_002BE898;
extern f32 D_FLT_002BE89C;
extern f32 D_FLT_002BE8A0;
extern f32 D_FLT_002BE8A4;
extern M2C_UNK g_2dded0;
extern s32 g_2dfb80;

void Swarm_Update(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f3;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 var_f13;
    s32 temp_s3;
    s32 var_s1;
    void *temp_s0;
    void *var_s0;

    UpdateSo();
    if (M2C_FIELD(arg0, s32 *, 0x1C0) != 0) {
        var_s1 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
            do {
                temp_s0 = arg0 + ((var_s1 * 0x30) + 0x1CC);
                temp_s3 = M2C_FIELD(temp_s0, s32 *, 0x24);
                SMaxCrv(temp_s3);
                if (M2C_FIELD(temp_s0, f32 *, 0x2C) < M2C_FIELD(&g_2dded0, f32 *, 0)) {
                    PosLoWorld(g_2dfb80);
                    FindCrvClosestPointAll(temp_s3, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, 0);
                    temp_f20 = M2C_FIELD(&g_2dded0, f32 *, 0);
                    M2C_FIELD(temp_s0, f32 *, 0x2C) = (f32) (temp_f20 + GRandInRange(0x3F000000, 0x3F400000));
                } else {
                    PosLoWorld(g_2dfb80);
                    FindCrvClosestPointFromS(temp_s3, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, 0, M2C_FIELD(temp_s0, f32 *, 0x28));
                }
                SwarmGroup_UpdateTargets(arg0, temp_s0);
                var_s0 = M2C_FIELD(temp_s0, void **, 0x10);
                if (var_s0 != NULL) {
                    var_f13 = M2C_FIELD(var_s0, f32 *, 0x40);
loop_8:
                    temp_f0 = GSmoothA__FffffP4SMPAPf(&D_002BE888, var_s0 + 0x40, M2C_FIELD(var_s0, f32 *, 0x3C), var_f13, M2C_FIELD(var_s0, f32 *, 0x44), M2C_FIELD(&g_2dded0, f32 *, 4));
                    M2C_FIELD(var_s0, f32 *, 0x3C) = temp_f0;
                    GetPathPosFromS(temp_s3, var_s0, var_s0 + 0x10, temp_f0);
                    temp_f7 = M2C_FIELD(var_s0, f32 *, 0x50);
                    temp_f3 = M2C_FIELD(var_s0, f32 *, 0x58);
                    temp_f5 = M2C_FIELD(var_s0, f32 *, 0x5C);
                    temp_f0_2 = temp_f3 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((D_FLT_002BE898 * temp_f7) + (D_FLT_002BE89C * temp_f3)));
                    M2C_FIELD(var_s0, f32 *, 0x58) = temp_f0_2;
                    temp_f7_2 = temp_f7 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((temp_f3 + temp_f0_2) * 0.5f));
                    M2C_FIELD(var_s0, f32 *, 0x50) = temp_f7_2;
                    temp_f1 = temp_f5 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((D_FLT_002BE8A0 * M2C_FIELD(var_s0, f32 *, 0x54)) + (D_FLT_002BE8A4 * temp_f5)));
                    M2C_FIELD(var_s0, f32 *, 0x5C) = temp_f1;
                    M2C_FIELD(var_s0, f32 *, 0x50) = (f32) (temp_f7_2 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((temp_f5 + temp_f1) * 0.5f)));
                    Swarm_UpdateRiderState(arg0, var_s0);
                    var_s0 = M2C_FIELD(var_s0, void **, 0x60);
                    if (var_s0 != NULL) {
                        var_f13 = M2C_FIELD(var_s0, f32 *, 0x40);
                        goto loop_8;
                    }
                }
                var_s1 += 1;
            } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x1C8));
        }
    }
}
