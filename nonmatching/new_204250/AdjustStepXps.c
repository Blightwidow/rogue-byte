#include "m2c_macros.h"

M2C_UNK FreeSwMqList__FP2SWP2MQ(M2C_UNK *, void *, void **, void **); /* extern */
M2C_UNK func_001F4F10();                            /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void AdjustStepXps(void *arg0) {
    f32 temp_f0;
    f32 var_f1;
    s32 var_v0;
    s32 var_v0_2;
    void **var_a2;
    void **var_a2_2;
    void **var_a3;
    void *var_a0;
    void *var_a1;
    void *var_t1;
    void *var_v1;

    func_001F4F10();
    var_f1 = 3.4028235e38f;
    var_t1 = NULL;
    var_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
loop_1:
    if (var_a2 == NULL) {
        var_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x68);
    } else {
        var_v1 = M2C_FIELD(var_a2, void **, 0);
    }
    if (var_v1 != NULL) {
        var_v0 = M2C_FIELD(var_v1, s32 *, 0x9C);
loop_8:
        if (var_v0 == 0xE) {
            temp_f0 = M2C_FIELD(var_v1, f32 *, 0x90);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
                var_t1 = var_v1;
            }
        }
        var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
        if (var_v1 != NULL) {
            var_v0 = M2C_FIELD(var_v1, s32 *, 0x9C);
            goto loop_8;
        }
    }
    if (var_a2 != NULL) {
        var_a2 = M2C_FIELD(var_a2, void ***, 4);
        goto loop_1;
    }
    M2C_FIELD(arg0, void **, 0x208) = var_t1;
    if (var_t1 != NULL) {
        M2C_FIELD(arg0, f32 *, 0x20C) = (f32) g_2dded0;
        M2C_FIELD(arg0, s128 *, 0x230) = (s128) M2C_FIELD(var_t1, s128 *, 0x50);
    }
    var_a1 = NULL;
    var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
loop_19:
    var_a3 = var_a2_2;
    if (var_a2_2 == NULL) {
        var_a3 = M2C_FIELD(arg0, void **, 0xEC) + 0x68;
    }
    var_a0 = *var_a3;
    if (var_a0 != NULL) {
        var_v0_2 = M2C_FIELD(var_a0, s32 *, 8);
loop_23:
        if (M2C_FIELD((var_a0 + (((s32) arg0 != var_v0_2) << 6)), s32 *, 0xC) != arg0) {
            var_a3 = var_a0 + 0xAC;
        } else if (M2C_FIELD(var_a0, s32 *, 0x9C) != 0xE) {
            var_a3 = var_a0 + 0xAC;
        } else if (var_a0 == var_t1) {
            var_a3 = var_a0 + 0xAC;
        } else {
            *var_a3 = M2C_FIELD(var_a0, void **, 0xAC);
            M2C_FIELD(var_a0, void **, 0xAC) = var_a1;
            var_a1 = var_a0;
        }
        var_a0 = *var_a3;
        if (var_a0 != NULL) {
            var_v0_2 = M2C_FIELD(var_a0, s32 *, 8);
            goto loop_23;
        }
    }
    if (var_a2_2 != NULL) {
        *M2C_FIELD(var_a2_2, s32 **, 8) = M2C_FIELD(var_a2_2, void **, 0);
        var_a2_2 = M2C_FIELD(var_a2_2, void ***, 4);
        goto loop_19;
    }
    FreeSwMqList__FP2SWP2MQ(&B_003DD490, var_a1, var_a2_2, var_a3);
}
