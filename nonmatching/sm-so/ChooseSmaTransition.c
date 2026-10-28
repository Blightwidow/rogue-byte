#include "m2c_macros.h"

M2C_UNK ApplyAseg(); /* extern */
s32 FSmaRetracted();                          /* extern */
M2C_UNK NotifySmaSpliceOnEnterState(); /* extern */
void *PsmtChooseSmAny();   /* extern */
void *PsmtChooseSmTowards();   /* extern */
M2C_UNK RetractAsega();                          /* extern */
M2C_UNK SubscribeLoObject();             /* extern */

void ChooseSmaTransition(void *arg0, s32 arg1) {
    f32 var_f12;
    f32 var_f13;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    void *temp_a0;
    void *var_s0;

    var_s3 = arg1;
    if (FSmaRetracted() == 0) {
loop_32:
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x34);
        temp_a3 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_a2 != temp_a3) {
            var_s0 = PsmtChooseSmTowards(M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(arg0, s32 *, 0x48), temp_a2, temp_a3);
            goto block_9;
        }
        temp_a0 = M2C_FIELD(arg0, void **, 0x24);
        temp_v0 = M2C_FIELD((M2C_FIELD(temp_a0, s32 *, 0x54) + (temp_a2 * 8)), s32 *, 4);
        if (temp_v0 == -1) {

        } else {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x48);
            if (temp_v0 == -2) {
                var_s0 = PsmtChooseSmAny(temp_a0, temp_a1, temp_a2, 0);
                var_s3 = 0;
                if (var_s0 != NULL) {
                    temp_v0_2 = M2C_FIELD(var_s0, s32 *, 4);
                    var_a0 = temp_v0_2;
                    if (temp_v0_2 == M2C_FIELD(arg0, s32 *, 0x34)) {
                        var_a0 = M2C_FIELD(var_s0, s32 *, 8);
                    }
                    M2C_FIELD(arg0, s32 *, 0x3C) = var_a0;
                    goto block_8;
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0x3C) = temp_v0;
                var_s0 = PsmtChooseSmTowards(temp_a0, temp_a1, temp_a2, temp_v0);
block_8:
                var_s3 = 0;
            }
block_9:
            M2C_FIELD(arg0, void **, 0x40) = var_s0;
            if (var_s0 != NULL) {
                var_s1 = 0;
                if (M2C_FIELD(var_s0, void **, 0) != NULL) {
                    temp_v1 = M2C_FIELD(var_s0, s32 *, 4);
                    if (temp_v1 != M2C_FIELD(arg0, s32 *, 0x34)) {
                        M2C_FIELD(arg0, s32 *, 0x38) = temp_v1;
                        var_f13 = -M2C_FIELD(arg0, f32 *, 0x44);
                        var_f12 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0), f32 *, 0x74);
                    } else {
                        var_f12 = 0.0f;
                        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(var_s0, s32 *, 8);
                        var_f13 = M2C_FIELD(arg0, f32 *, 0x44);
                    }
                    var_a2 = M2C_FIELD(arg0, s32 *, 0x2C);
                    if (var_s3 == 1) {
                        var_a2 = (var_a2 | 2) & ~1;
                        var_s1 = 1;
                        var_f12 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0), f32 *, 0x74) - var_f12;
                    } else if (M2C_FIELD(M2C_FIELD(var_s0, void **, 0), f32 *, 0x74) == 0.0f) {
                        var_s1 = 1;
                    }
                    ApplyAseg(M2C_FIELD(var_s0, void **, 0), M2C_FIELD(arg0, s32 *, 0x28), var_a2, arg0 + 0x30, var_f12, var_f13);
                }
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x30);
                if (temp_a0_2 == 0) {
                    var_a1 = M2C_FIELD(arg0, s32 *, 0x34);
                    var_v0 = M2C_FIELD(var_s0, s32 *, 4);
                    if (var_v0 == var_a1) {
                        var_v0 = M2C_FIELD(var_s0, s32 *, 8);
                    }
                    var_a2_2 = var_v0;
                    M2C_FIELD(arg0, s32 *, 0x34) = var_v0;
                    goto block_30;
                }
                if (var_s1 != 0) {
                    temp_s1 = M2C_FIELD(arg0, s32 *, 0x38);
                    temp_s0 = M2C_FIELD(arg0, s32 *, 0x34);
                    M2C_FIELD(arg0, s32 *, 0x34) = temp_s1;
                    M2C_FIELD(arg0, s32 *, 0x38) = -1;
                    RetractAsega(temp_a0_2);
                    M2C_FIELD(arg0, s32 *, 0x30) = 0;
                    var_a1 = temp_s0;
                    var_a2_2 = temp_s1;
block_30:
                    NotifySmaSpliceOnEnterState(arg0, var_a1, var_a2_2);
                    if (FSmaRetracted(arg0) == 0) {
                        if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
                            goto loop_32;
                        }
                    }
                } else {
                    SubscribeLoObject(temp_a0_2, arg0);
                }
            }
        }
    }
}
