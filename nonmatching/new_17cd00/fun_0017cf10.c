#include "m2c_macros.h"

f32 GSmooth__FfffP3SMPPf(void *, M2C_UNK, f32, f32, f32, f32, s32, f32); /* extern */
M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(s32, s32, void *, f32); /* extern */
f32 SWrapCrv(s32, f32);                             /* extern */
M2C_UNK func_0017D058(void *, M2C_UNK);             /* extern */
s32 func_0017D188(void *);                          /* extern */
M2C_UNK func_001EEF98();                            /* extern */
extern M2C_UNK g_2dded0;
extern f32 g_2dfb7c;

void func_0017CF10(void *arg0) {
    char sp[0x400];
    f32 temp_f0;
    f32 var_f0;
    s32 temp_s1;
    s32 var_v1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    func_001EEF98();
    do {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x30);
        if (temp_s1 == 0) {
            if (func_0017D188(arg0) != 0) {
                func_0017D058(arg0, 1);
            } else {
                temp_v0 = M2C_FIELD(arg0, void **, 0x10);
                var_v1 = 1;
                if (!(M2C_FIELD(temp_v0, f32 *, 0xF88) < M2C_FIELD(arg0, f32 *, 0x38))) {
                    var_v1 = 0;
                }
                M2C_FIELD(temp_v0, s32 *, 0xF8C) = var_v1;
                temp_v1 = M2C_FIELD(arg0, void **, 0x10);
                if (M2C_FIELD(temp_v1, s32 *, 0xF8C) != 0) {
                    var_f0 = -M2C_FIELD(temp_v1, f32 *, 0x198);
                } else {
                    var_f0 = M2C_FIELD(temp_v1, f32 *, 0x198);
                }
                g_2dfb7c = var_f0;
                temp_f0 = GSmooth__FfffP3SMPPf(sp, 0, M2C_FIELD(arg0, f32 *, 0x3C), g_2dfb7c, M2C_FIELD(&g_2dded0, f32 *, 4), fabsf(g_2dfb7c), 0, 0.1f);
                M2C_FIELD(arg0, f32 *, 0x3C) = temp_f0;
                temp_v0_2 = M2C_FIELD(arg0, void **, 0x10);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xF88) = SWrapCrv(M2C_FIELD(temp_v0_2, s32 *, 0xF84), M2C_FIELD(temp_v0_2, f32 *, 0xF88) + (temp_f0 * M2C_FIELD(&g_2dded0, f32 *, 4)));
            }
        }
    } while (M2C_FIELD(arg0, s32 *, 0x30) != temp_s1);
    temp_v0_3 = M2C_FIELD(arg0, void **, 0x10);
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(M2C_FIELD(temp_v0_3, s32 *, 0xF84), M2C_FIELD(temp_v0_3, s32 *, 0xF8C), temp_v0_3 + 0x1B0, M2C_FIELD(temp_v0_3, f32 *, 0xF88));
}
