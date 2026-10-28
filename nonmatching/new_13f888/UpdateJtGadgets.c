#include "m2c_macros.h"

s32 FButtonPressedWithin();     /* extern */
s32 GetJtPower();                             /* extern */
s32 NewEmitter();            /* extern */
M2C_UNK SetEmitterUnpositioned();       /* extern */
M2C_UNK SetJtGadgetSlotState();  /* extern */
extern M2C_UNK D_002BCD00;
extern s32 D_002C3258;
extern f32 g_2dded0;

void UpdateJtGadgets(void *arg0) {
    s32 *var_s4;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s1;
    s32 temp_v1;
    s32 var_s3;
    void *temp_s2;
    void *temp_v0;
    void *temp_v1_2;
    void *temp_v1_3;

    if (M2C_FIELD(arg0, void **, 0x150) != NULL) {
        var_s3 = 0;
        var_s4 = &D_002C3258;
        do {
            temp_a1 = *var_s4;
            temp_s2 = arg0 + ((var_s3 * 0xC) + 0x1180);
            temp_v1 = M2C_FIELD(temp_s2, s32 *, 4);
            temp_s1 = M2C_FIELD(temp_s2, s32 *, 0);
            switch (temp_v1) {                      /* irregular */
            case 1:
                if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & temp_a1) {
                    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                    if (M2C_FIELD(temp_v1_2, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x318), temp_s1) != 0) {
                        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x32C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x328), temp_s2);
                    } else {
                        goto block_17;
                    }
                } else {
block_17:
                    SetJtGadgetSlotState(arg0, temp_s2, 0);
                }
                break;
            case 0:
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), temp_a1, 0x3E19999A) != 0) {
                    temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                    if (M2C_FIELD(temp_v1_3, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), temp_s1) == 0) {
                        SetEmitterUnpositioned(NewEmitter(0x2E), 0);
                    } else {
                        temp_a1_2 = temp_s1 << 5;
                        if (GetJtPower(arg0) < M2C_FIELD((&D_002BCD00 + temp_a1_2), s32 *, 0xC)) {
                            SetEmitterUnpositioned(NewEmitter(0x2E, temp_a1_2, &D_002BCD00), 0);
                            M2C_FIELD(arg0, f32 *, 0x1304) = (f32) g_2dded0;
                        } else {
                            SetJtGadgetSlotState(arg0, temp_s2, *(temp_a1_2 + &D_002BCD00));
                        }
                    }
                }
                break;
            }
            var_s3 += 1;
            var_s4 += 4;
        } while (var_s3 < 3);
    }
}
