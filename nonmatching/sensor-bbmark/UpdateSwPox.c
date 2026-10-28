#include "m2c_macros.h"

void *AllocSwOx(s32, void *, void *);               /* extern */
s32 FPoxaPairInteracts(s32, void *, void *);        /* extern */
M2C_UNK FreeSlotheapPv(s32, void *);                /* extern */
M2C_UNK FreeSwMqList__FP2SWP2MQ(s32, s32);          /* extern */
void *PoxExtractFromPoxa(s32, void *, void *);      /* extern */
M2C_UNK func_001F5078(void *);                      /* extern */

void UpdateSwPox(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    M2C_UNK saved_reg_s5;
    s32 temp_a1;
    s32 var_s0_2;
    s32 var_s5;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s0;
    void *var_s1;

    var_s5 = saved_reg_s5;
    var_s0 = M2C_FIELD(arg1, void **, 0x64);
    if (var_s0 != NULL) {
        temp_v1 = M2C_FIELD(arg2, void **, 0x60);
        if (M2C_FIELD(var_s0, s32 *, 0xC) != temp_v1) {
loop_2:
            var_s0 = M2C_FIELD(var_s0, void **, 4);
            if (var_s0 != NULL) {
                if (M2C_FIELD(var_s0, s32 *, 0xC) == temp_v1) {

                } else {
                    goto loop_2;
                }
            }
        }
    }
    if (arg3 != 1) {
        if (arg3 >= 2) {
            var_s1 = var_s0;
            if (arg3 != 2) {

            } else {
                var_s5 = 0;
                goto block_17;
            }
        } else {
            var_s1 = var_s0;
            if (arg3 != 0) {

            } else {
                var_s5 = 0;
                if (var_s0 != NULL) {
                    var_s5 = M2C_FIELD(var_s0, s32 *, 0x10);
                }
                goto block_17;
            }
        }
    } else {
        var_s5 = 1;
block_17:
        var_s1 = var_s0;
    }
    if ((var_s5 != 0) || (FPoxaPairInteracts(arg0, arg1, arg2) != 0)) {
        if (var_s1 == NULL) {
            temp_s0 = AllocSwOx(arg0, arg1, arg2);
            temp_v0 = AllocSwOx(arg0, arg2, arg1);
            var_s1 = temp_s0;
            M2C_FIELD(temp_s0, void **, 8) = temp_v0;
            M2C_FIELD(temp_v0, void **, 8) = temp_s0;
            goto block_30;
        }
        goto block_31;
    }
    if (var_s1 != NULL) {
        temp_a2 = M2C_FIELD(arg1, void **, 0x60);
        temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *, void *), 0x1B4)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0x1B0), M2C_FIELD(arg2, void **, 0x60), temp_a2);
        temp_a2_2 = M2C_FIELD(arg2, void **, 0x60);
        temp_v0_3 = M2C_FIELD(temp_a2_2, void **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *, void *), 0x1B4)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x1B0), M2C_FIELD(arg1, void **, 0x60), temp_a2_2);
        temp_s1 = PoxExtractFromPoxa(arg0, arg1, arg2);
        temp_a1 = M2C_FIELD(temp_s1, s32 *, 0);
        temp_s2 = PoxExtractFromPoxa(arg0, arg2, arg1);
        if (temp_a1 != 0) {
            FreeSwMqList__FP2SWP2MQ(arg0, temp_a1);
            temp_a1_2 = M2C_FIELD(temp_s1, void **, 0xC);
            temp_v1_2 = M2C_FIELD(temp_a1_2, void **, 0xC);
            if (M2C_FIELD(temp_v1_2, s32 (**)(void *, void *), 0x1F4)(temp_a1_2 + M2C_FIELD(temp_v1_2, s16 *, 0x1F0), temp_a1_2) == 0) {
                func_001F5078(M2C_FIELD(temp_s1, void **, 0xC));
            }
            temp_a1_3 = M2C_FIELD(temp_s2, void **, 0xC);
            temp_v1_3 = M2C_FIELD(temp_a1_3, void **, 0xC);
            var_s0_2 = arg0 + 0x3CF8;
            if (M2C_FIELD(temp_v1_3, s32 (**)(void *, void *), 0x1F4)(temp_a1_3 + M2C_FIELD(temp_v1_3, s16 *, 0x1F0), temp_a1_3) == 0) {
                func_001F5078(M2C_FIELD(temp_s2, void **, 0xC));
                goto block_28;
            }
        } else {
block_28:
            var_s0_2 = arg0 + 0x3CF8;
        }
        var_s1 = NULL;
        FreeSlotheapPv(var_s0_2, temp_s1);
        FreeSlotheapPv(var_s0_2, temp_s2);
block_30:
        if (var_s1 != NULL) {
block_31:
            M2C_FIELD(M2C_FIELD(var_s1, void **, 8), s32 *, 0x10) = var_s5;
            M2C_FIELD(var_s1, s32 *, 0x10) = var_s5;
        }
    }
}
