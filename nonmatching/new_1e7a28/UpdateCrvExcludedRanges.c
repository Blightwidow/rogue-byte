#include "m2c_macros.h"

s32 ClsgMergeAlsg(s32, M2C_UNK *, s32, M2C_UNK *);  /* extern */
M2C_UNK GetPathPosFromS(void *, void *, M2C_UNK, f32); /* extern */
s32 PobstacleFindAtPos(s128);                       /* extern */
f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv(void *, s32, s32, s32);                 /* extern */
s32 func_001BD560(s32, void *, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2c367c;

void UpdateCrvExcludedRanges(void *arg0, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp610;
    f32 spC10;
    f32 spC14;
    void *spC18;
    void *spC1C;
    M2C_UNK *spC20;
    M2C_UNK *var_a1_3;
    M2C_UNK *var_s0;
    M2C_UNK *var_s0_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f21;
    f32 var_f20;
    s32 temp_a0;
    s32 temp_cond;
    s32 temp_fp;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_s5;
    void **var_a0;
    void **var_a2;
    void *temp_s4;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v1_2;
    void *var_a0_2;
    void *var_s1;
    void *var_s1_2;
    void *var_v0_3;

    var_a3 = arg3;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x90);
    var_a1 = 0;
    if (temp_v0 > 0) {
        var_a2 = M2C_FIELD(arg0, void ***, 0x94);
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x98);
        var_v0 = temp_v0 > 0;
        if (temp_a0 >= M2C_FIELD(*var_a2, s32 *, 0x114)) {
            var_a3 = temp_a0;
            var_a0 = var_a2;
            var_a2 = (void **) temp_v0;
loop_3:
            var_a1 += 1;
            var_a0 += 4;
            if (var_a1 < (s32) var_a2) {
                if (var_a3 < M2C_FIELD(*var_a0, s32 *, 0x114)) {
                    var_v0 = var_a1 < temp_v0;
                    goto block_6;
                }
                goto loop_3;
            }
        } else {
block_6:
            temp_s4 = arg0 + 0x10;
            if (var_v0 != 0) {
                spC1C = temp_s4;
                var_s5 = 0;
                temp_f0 = SMinCrv(M2C_FIELD(arg0, void **, 0), var_a1, (s32) var_a2, var_a3);
                var_f20 = temp_f0;
                temp_f21 = SMaxCrv(M2C_FIELD(arg0, void **, 0));
                temp_cond = temp_f0 < temp_f21;
                spC18 = M2C_FIELD(arg0, void **, 8);
                temp_fp = M2C_FIELD(arg0, s32 *, 4);
                spC20 = &sp10;
                if (temp_cond) {
loop_9:
                    GetPathPosFromS(M2C_FIELD(arg0, void **, 0), sp, 0, var_f20);
                    temp_v0_2 = PobstacleFindAtPos(sp0);
                    if (temp_v0_2 != 0) {
                        temp_v0_3 = M2C_FIELD(arg0, void **, 0);
                        temp_s2 = M2C_FIELD(temp_v0_3, s32 *, 0xE4);
                        M2C_FIELD(temp_v0_3, s32 *, 0xE4) = 0;
                        if (func_001BD560(temp_v0_2, M2C_FIELD(arg0, void **, 0), 0, 0, var_f20) == 3) {
                            spC10 = temp_f0;
                        }
                        if (func_001BD560(temp_v0_2, M2C_FIELD(arg0, void **, 0), 1, 0, var_f20) == 3) {
                            spC14 = temp_f21;
                        }
                        var_a0_2 = temp_s4 + (var_s5 * 8);
                        var_a1_2 = 1;
                        M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xE4) = temp_s2;
                        var_v0_2 = (u32) temp_s4 < (u32) var_a0_2;
loop_15:
                        temp_v0_4 = var_a0_2 - 8;
                        if (var_v0_2 != 0) {
                            var_v1 = var_a0_2 - temp_s4;
                            if (!(M2C_FIELD(temp_v0_4, f32 *, 4) < spC10)) {
                                var_a0_2 = temp_v0_4;
                                var_v0_2 = (u32) temp_s4 < (u32) var_a0_2;
                                if (M2C_FIELD(temp_v0_4, f32 *, 0) < spC10) {
                                    var_a1_2 = 0;
                                    goto block_19;
                                }
                                goto loop_15;
                            }
                        } else {
block_19:
                            var_v1 = var_a0_2 - temp_s4;
                        }
                        temp_v1 = var_v1 >> 3;
                        temp_s5 = temp_v1 + 1;
                        var_s5 = (temp_s5 >= 0x11U) ? temp_v1 : (s32) temp_s5;
                        if (var_a1_2 != 0) {
                            M2C_FIELD(var_a0_2, f32 *, 0) = spC10;
                        }
                        M2C_FIELD(var_a0_2, f32 *, 4) = spC14;
                        var_f20 = spC14;
                    }
                    var_f20 += g_2c367c;
                    if (var_f20 < temp_f21) {
                        goto loop_9;
                    }
                }
                if (temp_fp > 0) {
                    var_s1 = spC18;
                    var_s2 = temp_fp;
                    var_s0 = spC20;
                    do {
                        var_s2 -= 1;
                        memset(var_s0, 0, 0x60);
                        M2C_FIELD(var_s0, f32 *, 0x40) = (f32) M2C_FIELD(var_s1, f32 *, 0);
                        temp_f1 = M2C_FIELD(var_s1, f32 *, 4);
                        var_s1 += 8;
                        M2C_FIELD(var_s0, f32 *, 0x44) = temp_f1;
                        var_s0 += 0x60;
                    } while (var_s2 != 0);
                }
                if (var_s5 > 0) {
                    var_s1_2 = temp_s4;
                    var_s0_2 = &sp610;
                    var_s2_2 = var_s5;
                    do {
                        var_s2_2 -= 1;
                        memset(var_s0_2, 0, 0x60);
                        temp_f1_2 = M2C_FIELD(var_s1_2, f32 *, 4);
                        M2C_FIELD(var_s0_2, f32 *, 0x40) = (f32) M2C_FIELD(var_s1_2, f32 *, 0);
                        var_s1_2 += 8;
                        M2C_FIELD(var_s0_2, f32 *, 0x44) = temp_f1_2;
                        var_s0_2 += 0x60;
                    } while (var_s2_2 != 0);
                }
                temp_v0_5 = ClsgMergeAlsg(var_s5, &sp610, temp_fp, spC20);
                var_v0_3 = temp_s4;
                if (temp_v0_5 > 0) {
                    var_a1_3 = &sp610;
                    var_v1_2 = temp_v0_5;
                    do {
                        var_v1_2 -= 1;
                        temp_f1_3 = M2C_FIELD(var_a1_3, f32 *, 0x44);
                        M2C_FIELD(var_v0_3, f32 *, 0) = (f32) M2C_FIELD(var_a1_3, f32 *, 0x40);
                        var_a1_3 += 0x60;
                        M2C_FIELD(var_v0_3, f32 *, 4) = temp_f1_3;
                        var_v0_3 += 8;
                    } while (var_v1_2 != 0);
                }
                if ((temp_v0_5 >= 2) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xE4) != 0) && (M2C_FIELD(spC1C, f32 *, 0) == temp_f0)) {
                    temp_v0_6 = (temp_v0_5 * 8) + spC1C;
                    temp_v1_2 = temp_v0_6 - 8;
                    if (M2C_FIELD(temp_v1_2, f32 *, 4) == temp_f21) {
                        M2C_FIELD(spC1C, f32 *, 0) = (f32) (M2C_FIELD(temp_v0_6, f32 *, -8) - temp_f21);
                        M2C_FIELD(temp_v1_2, f32 *, 4) = (f32) (M2C_FIELD(spC1C, f32 *, 4) + temp_f21);
                    }
                }
                M2C_FIELD(arg0, s32 *, 0xC) = temp_v0_5;
                temp_v0_7 = M2C_FIELD(&B_003DD490, s32 *, 0x3D70) + 1;
                M2C_FIELD(&B_003DD490, s32 *, 0x3D70) = temp_v0_7;
                M2C_FIELD(arg0, s32 *, 0x98) = temp_v0_7;
            }
        }
    }
}
