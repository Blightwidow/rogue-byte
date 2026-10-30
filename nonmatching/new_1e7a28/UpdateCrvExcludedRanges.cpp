typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateCrvExcludedRanges {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x600];
    /* 0x610 */ M2C_UNK sp610;                      /* inferred */
    /* 0x610 */ char pad610[0x600];
    /* 0xC10 */ f32 spC10;                          /* inferred */
    /* 0xC14 */ f32 spC14;                          /* inferred */
    /* 0xC18 */ s8 *spC18;                        /* inferred */
    /* 0xC1C */ s8 *spC1C;                        /* inferred */
    /* 0xC20 */ M2C_UNK *spC20;                     /* inferred */
    /* 0xC24 */ char padC24[0xCC];
};                                                  /* size = 0xCF0 */
#define sp0 (*(s128 *)(sp + 0x000))
s32 ClsgMergeAlsg(s32, M2C_UNK *, s32, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK GetPathPosFromS(s8 *, s8 *, M2C_UNK, f32); /* extern */
s32 PobstacleFindAtPos(s128);                       /* extern */
f32 SMaxCrv(s8 *);                                /* extern */
f32 SMinCrv(s8 *, s32, s32, s32, s32);            /* extern */
s32 func_001BD560(s32, s8 *, M2C_UNK, M2C_UNK, f32 *, f32); /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2c367c;
void UpdateCrvExcludedRanges(s8 *arg0, s32 arg3) {
    s8 sp[0xCF0] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK sp610;
    f32 spC10;
    f32 spC14;
    s8 *spC18;
    s8 *spC1C;
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
    s8 **var_a0;
    s8 **var_a2;
    s8 *temp_s4;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_6;
    s8 *temp_v1_2;
    s8 *var_a0_2;
    s8 *var_s1;
    s8 *var_s1_2;
    s8 *var_v0_3;
    var_a3 = arg3;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x90);
    var_a1 = 0;
    if (temp_v0 > 0) {
        var_a2 = M2C_FIELD(arg0, s8 ***, 0x94);
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x98);
        var_v0 = temp_v0 > 0;
        if (temp_a0 >= M2C_FIELD(*var_a2, s32 *, 0x114)) {
            var_a3 = temp_a0;
            var_a0 = var_a2;
            var_a2 = (s8 **) temp_v0;
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
                temp_f0 = SMinCrv(M2C_FIELD(arg0, s8 **, 0), var_a1, (s32) var_a2, var_a3, temp_v0);
                var_f20 = temp_f0;
                temp_f21 = SMaxCrv(M2C_FIELD(arg0, s8 **, 0));
                temp_cond = temp_f0 < temp_f21;
                spC18 = M2C_FIELD(arg0, s8 **, 8);
                temp_fp = M2C_FIELD(arg0, s32 *, 4);
                spC20 = &sp10;
                if (temp_cond) {
loop_9:
                    GetPathPosFromS(M2C_FIELD(arg0, s8 **, 0), sp, 0, var_f20);
                    temp_v0_2 = PobstacleFindAtPos(sp0);
                    if (temp_v0_2 != 0) {
                        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0);
                        temp_s2 = M2C_FIELD(temp_v0_3, s32 *, 0xE4);
                        M2C_FIELD(temp_v0_3, s32 *, 0xE4) = 0;
                        if (func_001BD560(temp_v0_2, M2C_FIELD(arg0, s8 **, 0), 0, 0, &spC10, var_f20) == 3) {
                            spC10 = temp_f0;
                        }
                        if (func_001BD560(temp_v0_2, M2C_FIELD(arg0, s8 **, 0), 1, 0, &spC14, var_f20) == 3) {
                            spC14 = temp_f21;
                        }
                        var_a0_2 = temp_s4 + (var_s5 * 8);
                        var_a1_2 = 1;
                        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0xE4) = temp_s2;
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
                temp_v0_5 = ClsgMergeAlsg(var_s5, &sp610, temp_fp, spC20, 0x10, &sp610, 0);
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
                if ((temp_v0_5 >= 2) && (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0xE4) != 0) && (M2C_FIELD(spC1C, f32 *, 0) == temp_f0)) {
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
}
