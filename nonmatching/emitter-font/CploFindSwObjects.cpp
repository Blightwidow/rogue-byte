typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CploFindSwObjects {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s8 *sp1C;                          /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xAC];
};                                                  /* size = 0xD0 */
M2C_UNK MatchSwObject(s32, s8 *, s32, s32, s8 *, s32, s32, s32 *, s32 *, s32 *); /* extern */
s8 **PdlFromSwOid(s32, s32);                      /* extern */
s8 **func_0015E3C0(s32, s32);                     /* extern */
extern s32 B_003E139C;
s32 CploFindSwObjects(s32 arg0, s32 arg1, s32 arg2, s8 *arg3, s32 arg4, s32 arg5, s32 *arg6) {
    s32 sp14;
    s32 sp18;
    s8 *sp1C;
    s32 sp20;
    s32 *var_v1;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s8 var_v0_2;
    s8 *temp_v1_2;
    s8 *var_s0;
    s8 *var_s0_2;
    s8 *var_s0_3;
    s8 *var_s0_4;
    var_s5 = arg4;
    if ((arg2 == -1) || ((temp_v1 = arg1 & 0xFF, (arg3 == NULL)) && (temp_v1 != 5))) {
        return 0;
    }
    if (var_s5 == 0) {
        if (arg3 != NULL) {
            var_s5 = M2C_FIELD(arg3, s32 *, 0x3C);
        } else {
            var_s5 = B_003E139C;
        }
    }
    sp14 = 0;
    if (temp_v1 != 1) {
        if ((temp_v1 != 0) && (temp_v1 < 5)) {
            var_v0 = arg1 & 0x200;
            if (temp_v1 >= 3) {
                goto block_13;
            }
            goto block_18;
        }
        var_v0 = arg1 & 0x200;
block_18:
        sp1C = NULL;
        sp20 = var_v0;
    } else {
block_13:
        var_s0 = arg3;
        sp1C = var_s0;
        sp20 = arg1 & 0x200;
        if (var_s0 != NULL) {
            var_v0_2 = 1;
            do {
                M2C_FIELD(var_s0, s8 *, 0x2C) = var_v0_2;
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                var_v0_2 += 1;
            } while (var_s0 != NULL);
        }
        sp18 = 0x7FFFFFFF;
    }
    PdlFromSwOid(arg0, arg2);
    var_s0_2 = *PdlFromSwOid(arg0, arg2);
    if (var_s0_2 != NULL) {
        do {
            if (M2C_FIELD(var_s0_2, s32 *, 0x18) == arg2) {
                MatchSwObject(arg0, var_s0_2, M2C_FIELD(var_s0_2, s32 *, 0x3C), arg1, arg3, var_s5, arg5, &sp14, arg6, &sp18);
            }
            var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x1C);
        } while (var_s0_2 != NULL);
    }
    func_0015E3C0(arg0, arg2);
    var_s0_3 = *func_0015E3C0(arg0, arg2);
    if (var_s0_3 != NULL) {
        var_v0_3 = M2C_FIELD(var_s0_3, s32 *, 8);
loop_27:
        if (var_v0_3 == arg2) {
            temp_v1_2 = M2C_FIELD(var_s0_3, s8 **, 0x10);
            if (temp_v1_2 != NULL) {
                if ((M2C_FIELD(temp_v1_2, s32 *, 0x18) == arg2) && (sp14 > 0)) {
                    var_v0_4 = sp14 > 0;
                    if (*arg6 != (s32)temp_v1_2) {
                        var_v1 = arg6;
                        var_a0 = 1;
loop_33:
                        var_v1 += 4;
                        if (var_a0 < sp14) {
                            if (*var_v1 != (s32)temp_v1_2) {
                                var_a0 += 1;
                                goto loop_33;
                            }
                            var_v0_4 = var_a0 < sp14;
                            goto block_38;
                        }
                        goto block_39;
                    }
block_38:
                    if (var_v0_4 == 0) {
                        goto block_39;
                    }
                } else {
block_39:
                    MatchSwObject(arg0, M2C_FIELD(var_s0_3, s8 **, 0x10), M2C_FIELD(var_s0_3, s32 *, 4), arg1, arg3, var_s5, arg5, &sp14, arg6, &sp18);
                }
            }
        }
        var_s0_3 = M2C_FIELD(var_s0_3, s8 **, 0xC);
        if (var_s0_3 != NULL) {
            var_v0_3 = M2C_FIELD(var_s0_3, s32 *, 8);
            goto loop_27;
        }
    }
    var_s0_4 = sp1C;
    if (var_s0_4 != NULL) {
        M2C_FIELD(var_s0_4, s8 *, 0x2C) = 0;
loop_45:
        var_s0_4 = M2C_FIELD(var_s0_4, s8 **, 0x10);
        if (var_s0_4 != NULL) {
            M2C_FIELD(var_s0_4, s8 *, 0x2C) = 0;
            goto loop_45;
        }
    }
    if (sp20 == 0) {
        if (arg5 < sp14) {
            sp14 = arg5;
        }
    }
    return sp14;
}
}
