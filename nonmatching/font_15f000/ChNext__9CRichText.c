#include "m2c_macros.h"

void *PfontFromCh(u8, u8 *);                        /* extern */
M2C_UNK PopScaling__5CFont(void *, u8 *);           /* extern */
M2C_UNK PushScaling__5CFontff(void *, u8 *, f32, f32); /* extern */

u8 ChNext__9CRichText(void *arg0) {
    M2C_UNK sp0;
    u8 sp3;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 var_a1;
    s32 var_s1;
    u32 var_a0;
    u8 *temp_v1;
    u8 *var_a2;
    u8 *var_v0_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v1_2;
    u8 var_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_v1_3;
    void *var_v0;
    void *var_v1;

    var_s1 = 0;
loop_1:
    temp_v1_2 = *M2C_FIELD(arg0, u8 **, 4);
    if (temp_v1_2 != 0x5E) {
        if ((s32) temp_v1_2 < 0x5F) {
            if (temp_v1_2 == 0x26) {
                temp_v0 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1);
                if (temp_v0 != temp_v1_2) {
                    if (temp_v0 == 0x2E) {
                        M2C_FIELD(arg0, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(M2C_FIELD(arg0, s8 *, 0x158));
                        M2C_FIELD(arg0, s32 *, 0x150) = 1;
                        goto block_45;
                    }
                    var_v0 = PfontFromCh(M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1), M2C_FIELD(arg0, u8 **, 4));
                    var_v1 = arg0 + 0x10;
                    if (var_v0 != NULL) {
                        temp_a1 = var_v0 + 0x140;
                        temp_a0 = var_v1;
                        do {
                            M2C_FIELD(var_v1, s128 *, 0) = (s128) M2C_FIELD(var_v0, s128 *, 0);
                            M2C_FIELD(var_v1, s128 *, 0x10) = (s128) M2C_FIELD(var_v0, s128 *, 0x10);
                            var_v0 += 0x20;
                            var_v1 += 0x20;
                        } while (var_v0 != temp_a1);
                        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(arg0, u8 **, 4) = (u8 *) (M2C_FIELD(arg0, u8 **, 4) + 2);
                        M2C_FIELD(arg0, void **, 8) = temp_a0;
                        temp_f0 = ((f32) M2C_FIELD(temp_v1_3, s32 *, 0xC) * M2C_FIELD(temp_v1_3, f32 *, 0x14)) / ((f32) M2C_FIELD(temp_a0, s32 *, 0xC) * M2C_FIELD(temp_a0, f32 *, 0x14));
                        M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) * temp_f0);
                        M2C_FIELD(arg0, f32 *, 0x20) = (f32) (M2C_FIELD(arg0, f32 *, 0x20) * temp_f0);
                        sp0 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x160));
                        sp3 = M2C_FIELD(arg0, u8 *, 0x157);
                        M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(sp0);
                        M2C_FIELD(arg0, s32 *, 0x150) = 1;
                    } else {
                        var_s1 = 1;
                        M2C_FIELD(arg0, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x15C));
                        M2C_FIELD(arg0, s32 *, 0x150) = 1;
                    }
                } else {
                    goto block_40;
                }
            } else {
                var_s1 = 1;
            }
        } else if (temp_v1_2 != 0x7E) {
            var_s1 = 1;
        } else {
            temp_v0_2 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1);
            if (temp_v0_2 != temp_v1_2) {
                var_a2 = M2C_FIELD(arg0, u8 **, 4) + 1;
                if (temp_v0_2 == 0x2E) {
                    M2C_FIELD(arg0, s8 *, 0x158) = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x15C));
                    M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(M2C_FIELD(arg0, s8 *, 0x158));
                    goto block_45;
                }
                var_a0 = 0;
                if (temp_v0_2 != 0) {
                    if ((var_a2 - M2C_FIELD(arg0, u8 **, 4)) < 7) {
                        var_v1_2 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1);
loop_16:
                        if ((u32) (var_v1_2 - 0x30) < 0xAU) {
                            var_a1 = (var_v1_2 & 0xFF) - 0x30;
                            goto block_22;
                        }
                        if ((u32) (var_v1_2 - 0x41) < 6U) {
                            var_a1 = *var_a2 - 0x37;
                            goto block_22;
                        }
                        if ((u32) (var_v1_2 - 0x61) < 6U) {
                            var_a1 = *var_a2 - 0x57;
block_22:
                            var_a2 += 1;
                            var_a0 = (var_a0 * 0x10) + var_a1;
                            if (*var_a2 != 0) {
                                if ((var_a2 - M2C_FIELD(arg0, u8 **, 4)) < 7) {
                                    var_v1_2 = *var_a2;
                                    goto loop_16;
                                }
                            }
                        }
                        goto block_26;
                    }
                    goto block_29;
                }
block_26:
                if ((var_a2 - M2C_FIELD(arg0, u8 **, 4)) < 7) {
                    M2C_FIELD(arg0, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x15C));
                    var_s1 = 1;
                } else {
block_29:
                    M2C_FIELD(arg0, s8 *, 0x158) = (s8) ((u32) (((var_a0 >> 0x10) & 0xFF) + 1) >> 1);
                    M2C_FIELD(arg0, s8 *, 0x159) = (s8) ((u32) (((u32) (var_a0 & 0xFF00) >> 8) + 1) >> 1);
                    M2C_FIELD(arg0, s8 *, 0x15A) = (s8) ((u32) ((var_a0 & 0xFF) + 1) >> 1);
                    M2C_FIELD(arg0, M2C_UNK *, 0x154) = M2C_UNALIGNED32(M2C_FIELD(arg0, s8 *, 0x158));
                    var_v0_2 = M2C_FIELD(arg0, u8 **, 4) + 7;
                    goto block_47;
                }
            } else {
                goto block_40;
            }
        }
    } else {
        temp_v0_3 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1);
        if (temp_v0_3 == temp_v1_2) {
block_40:
            var_v0_2 = M2C_FIELD(arg0, u8 **, 4) + 1;
            var_s1 = 1;
        } else if (temp_v0_3 != 0x2E) {
            temp_a0_2 = M2C_FIELD(arg0, void **, 8);
            temp_f0_2 = (f32) (M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 1) - 0x30) + ((f32) (M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 2) - 0x30) * 0.1f);
            PushScaling__5CFontff(temp_a0_2, M2C_FIELD(arg0, u8 **, 4), temp_f0_2 * M2C_FIELD(temp_a0_2, f32 *, 0x10), temp_f0_2 * M2C_FIELD(temp_a0_2, f32 *, 0x14));
            var_v0_2 = M2C_FIELD(arg0, u8 **, 4) + 3;
        } else {
            PopScaling__5CFont(M2C_FIELD(arg0, void **, 8), M2C_FIELD(arg0, u8 **, 4));
block_45:
            var_v0_2 = M2C_FIELD(arg0, u8 **, 4) + 2;
        }
block_47:
        M2C_FIELD(arg0, u8 **, 4) = var_v0_2;
    }
    if (var_s1 == 0) {
        goto loop_1;
    }
    temp_v1 = M2C_FIELD(arg0, u8 **, 4);
    M2C_FIELD(arg0, u8 **, 4) = (u8 *) (temp_v1 + 1);
    return *temp_v1;
}
