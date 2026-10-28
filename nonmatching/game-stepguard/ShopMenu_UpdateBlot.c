#include "m2c_macros.h"

s32 ShopMenu_IrowEnd();             /* extern */
M2C_UNK SwitchBlotLabel();   /* extern */
M2C_UNK func_00213928();             /* extern */
M2C_UNK func_00213A08();            /* extern */
M2C_UNK func_00213B00();             /* extern */
M2C_UNK func_00213BD8();            /* extern */
M2C_UNK func_00213CD8(); /* extern */
M2C_UNK memset();           /* extern */
extern s32 B_003DA570;
extern M2C_UNK D_002BCD04;
extern M2C_UNK D_002C3588;
extern f32 D_FLT_002C35B0;

void ShopMenu_UpdateBlot(void *arg0) {
    char sp[0x400];
    f32 sp14;
    void *sp20;
    void *sp24;
    M2C_UNK temp_s0;
    M2C_UNK temp_s0_2;
    s32 temp_s2;
    s32 temp_s5;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s3;
    void *temp_a0;
    void *var_s0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x58) == 2) {
        memset(sp, 0, 0x20);
        temp_s5 = ShopMenu_IrowEnd(arg0, 1.0f, 1.0f);
        if (M2C_FIELD(arg0, s32 *, 0x250) > 0) {
            temp_s0 = (M2C_FIELD(arg0, s32 *, 0x40) == 0) ? 0x4DA : 0x4A1;
            if (B_003DA570 != 0) {
                func_00213CD8(M2C_FIELD(arg0, void **, 0x24), temp_s0, sp);
                sp14 += D_FLT_002C35B0;
            }
            SwitchBlotLabel(M2C_FIELD(arg0, void **, 0x24), temp_s0, arg0 + 0x260);
        } else {
            SwitchBlotLabel(M2C_FIELD(arg0, void **, 0x24), -1, arg0 + 0x260);
        }
        var_s3 = M2C_FIELD(arg0, s32 *, 0x250);
        sp24 = arg0 + 0x264;
        sp20 = arg0 + 0x25C;
        if (var_s3 < temp_s5) {
            var_s0 = (var_s3 * 8) + 0x4C + arg0;
            do {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
                temp_s2 = *(((var_s3 - M2C_FIELD(arg0, s32 *, 0x250)) * 4) + &D_002C3588);
                switch (temp_v1) {                  /* switch 1; irregular */
                case 1:                             /* switch 1 */
                    if (M2C_FIELD(var_s0, s32 *, 0) != -1) {
                        func_00213BD8(M2C_FIELD(arg0, void **, 0x24), 0x455, temp_s2);
                    } else {
                        func_00213A08(M2C_FIELD(arg0, void **, 0x24), 0x455, temp_s2);
                    }
                    break;
                case 0:                             /* switch 1 */
                    temp_v0 = M2C_FIELD(var_s0, s32 *, 0);
                    if (temp_v0 != -1) {
                        temp_v1_2 = *((temp_v0 << 5) + &D_002BCD04);
                        switch (temp_v1_2) {        /* switch 2; irregular */
                        case 7:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x456;
                            break;
                        case 9:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x458;
                            break;
                        case 8:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x457;
                            break;
                        }
                        func_00213BD8(M2C_FIELD(arg0, void **, 0x24), 0x455, temp_s2);
                        func_00213BD8(M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(var_s0, s32 *, 4), temp_s2);
                    } else {
                        func_00213A08(M2C_FIELD(arg0, void **, 0x24), 0x455, temp_s2);
                        func_00213A08(M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(var_s0, s32 *, 4), temp_s2);
                        M2C_FIELD(var_s0, s32 *, 4) = -1;
                    }
                    break;
                }
                var_s3 += 1;
                var_s0 += 8;
            } while (var_s3 < temp_s5);
        }
        temp_a0 = M2C_FIELD(arg0, void **, 0x24);
        if (M2C_FIELD(arg0, s32 *, 0x24C) >= 0) {
            func_00213B00(temp_a0, 0x437);
            memset(sp, 0, 0x20);
            sp14 = D_FLT_002C35B0 * (f32) (M2C_FIELD(arg0, s32 *, 0x24C) - M2C_FIELD(arg0, s32 *, 0x250));
            func_00213CD8(M2C_FIELD(arg0, void **, 0x24), 0x437, sp, 1.0f, 1.0f);
        } else {
            func_00213928(temp_a0, 0x437);
        }
        if (temp_s5 < M2C_FIELD(arg0, s32 *, 0x48)) {
            temp_s0_2 = (M2C_FIELD(arg0, s32 *, 0x40) == 0) ? 0x4DD : 0x4A4;
            if (B_003DA570 != 0) {
                func_00213CD8(M2C_FIELD(arg0, void **, 0x24), temp_s0_2, sp);
                sp14 += D_FLT_002C35B0;
            }
            SwitchBlotLabel(M2C_FIELD(arg0, void **, 0x24), temp_s0_2, sp24);
        } else {
            SwitchBlotLabel(M2C_FIELD(arg0, void **, 0x24), -1, sp24);
        }
        SwitchBlotLabel(M2C_FIELD(arg0, void **, 0x24), (~M2C_FIELD(arg0, s32 *, 0x30) == 0) ? 0x439 : 0x43B, sp20);
    }
}
