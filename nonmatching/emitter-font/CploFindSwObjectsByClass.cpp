typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CploFindSwObjectsByClass {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s8 *sp1C;                          /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xAC];
};                                                  /* size = 0xD0 */
s32 FIsBasicDerivedFrom(s8 *, s32);               /* extern */
s32 FIsCidDerivedFrom(s32, s32);                    /* extern */
M2C_UNK MatchSwObject(s32, s8 *, M2C_UNK, s32, s8 *, M2C_UNK, s32, s32 *, s32, s32 *); /* extern */
s8 **PdlFromSwCid(s32, s32);                      /* extern */
s32 CploFindSwObjectsByClass(s32 arg0, s32 arg1, s32 arg2, s8 *arg3, s32 arg4, s32 arg5) {
    s32 sp14;
    s32 sp18;
    s8 *sp1C;
    s32 sp20;
    s32 temp_v1;
    s32 var_s0_3;
    s32 var_s0_6;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s8 var_v0_3;
    s8 *var_a0;
    s8 *var_a0_2;
    s8 *var_a1;
    s8 *var_s0;
    s8 *var_s0_2;
    s8 *var_s0_4;
    s8 *var_s0_5;
    s8 *var_s0_7;
    s8 *var_s0_8;
    if (arg2 != -1) {
        temp_v1 = arg1 & 0xFF;
        if (arg3 == NULL) {
            if (temp_v1 != 5) {
                goto block_3;
            }
            goto block_5;
        }
block_5:
        sp14 = 0;
        switch (temp_v1) {                          /* irregular */
        case 3:
            var_s0 = M2C_FIELD(arg3, s8 **, 0x10);
            sp20 = arg1 & 0x200;
            if (var_s0 != NULL) {
                var_a0 = var_s0;
                do {
                    if ((FIsBasicDerivedFrom(var_a0, arg2) != 0) && (!(arg1 & 0x100) || ((int)((u64) M2C_FIELD(var_s0, u64 *, 0x28) >> 0x3C) & 1))) {
                        if (sp14 < arg4) {
                            *(s32 *)((sp14 * 4) + arg5) = (int)(var_s0);
                        }
                        sp14 += 1;
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                    var_a0 = var_s0;
                } while (var_s0 != NULL);
            }
            break;
        case 2:
            var_s1 = 0;
            if (arg1 & 0x100) {
                var_s1 = M2C_FIELD(arg3, s32 *, 0x70);
            }
            var_s0_2 = M2C_FIELD(arg3, s8 **, 0x64);
            sp20 = arg1 & 0x200;
            if ((s32)var_s0_2 != var_s1) {
                var_a0_2 = var_s0_2;
                do {
                    if (FIsBasicDerivedFrom(var_a0_2, arg2) != 0) {
                        if (sp14 < arg4) {
                            *(s32 *)((sp14 * 4) + arg5) = (int)(var_s0_2);
                        }
                        sp14 += 1;
                    }
                    var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x24);
                    var_a0_2 = var_s0_2;
                } while ((s32)var_s0_2 != var_s1);
            }
            break;
        case 5:
            var_s0_3 = arg2;
            sp20 = arg1 & 0x200;
loop_43:
            if (var_s0_3 < 0xC7) {
                if (FIsCidDerivedFrom(var_s0_3, arg2) != 0) {
                    PdlFromSwCid(arg0, var_s0_3);
                    var_s0_4 = *PdlFromSwCid(arg0, var_s0_3);
                    var_v1 = sp14;
                    if (var_s0_4 != NULL) {
                        do {
                            var_v0 = var_v1 < arg4;
                            if (!(arg1 & 0x100) || (var_v0 = var_v1 < arg4, (((int)((u64) M2C_FIELD(var_s0_4, u64 *, 0x28) >> 0x3C) & 1) != 0))) {
                                if (var_v0 != 0) {
                                    *(s32 *)((var_v1 * 4) + arg5) = (int)(var_s0_4);
                                }
                                var_v1 += 1;
                            }
                            var_s0_4 = M2C_FIELD(var_s0_4, s8 **, 0x20);
                        } while (var_s0_4 != NULL);
                        sp14 = var_v1;
                    }
                    var_s0_3 += 1;
                    goto loop_43;
                }
            }
            break;
        default:
            var_s0_5 = arg3;
            if (temp_v1 != 1) {
                if ((temp_v1 != 0) && (temp_v1 < 6)) {
                    var_v0_2 = arg1 & 0x200;
                    if (temp_v1 >= 3) {
                        var_s0_5 = arg3;
                        goto block_53;
                    }
                    goto block_58;
                }
                var_v0_2 = arg1 & 0x200;
block_58:
                sp1C = NULL;
                sp20 = var_v0_2;
            } else {
block_53:
                sp1C = var_s0_5;
                sp20 = arg1 & 0x200;
                if (var_s0_5 != NULL) {
                    var_v0_3 = 1;
                    do {
                        M2C_FIELD(var_s0_5, s8 *, 0x2C) = var_v0_3;
                        var_s0_5 = M2C_FIELD(var_s0_5, s8 **, 0x10);
                        var_v0_3 += 1;
                    } while (var_s0_5 != NULL);
                }
                sp18 = 0x7FFFFFFF;
            }
            var_s0_6 = arg2;
loop_65:
            if (var_s0_6 < 0xC7) {
                if (FIsCidDerivedFrom(var_s0_6, arg2) != 0) {
                    PdlFromSwCid(arg0, var_s0_6);
                    var_s0_7 = *PdlFromSwCid(arg0, var_s0_6);
                    if (var_s0_7 != NULL) {
                        var_a1 = var_s0_7;
                        do {
                            MatchSwObject(arg0, var_a1, 0, arg1 | 0x400, arg3, 0, arg4, &sp14, arg5, &sp18);
                            var_s0_7 = M2C_FIELD(var_s0_7, s8 **, 0x20);
                            var_a1 = var_s0_7;
                        } while (var_s0_7 != NULL);
                    }
                    var_s0_6 += 1;
                    goto loop_65;
                }
            }
            var_s0_8 = sp1C;
            if (var_s0_8 != NULL) {
                M2C_FIELD(var_s0_8, s8 *, 0x2C) = 0;
loop_71:
                var_s0_8 = M2C_FIELD(var_s0_8, s8 **, 0x10);
                if (var_s0_8 != NULL) {
                    M2C_FIELD(var_s0_8, s8 *, 0x2C) = 0;
                    goto loop_71;
                }
            }
            break;
        }
        if (sp20 == 0) {
            if (arg4 < sp14) {
                sp14 = arg4;
            }
        }
        return sp14;
    }
block_3:
    return 0;
}
}
