typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BindGlobset {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0xF0];
};                                                  /* size = 0x130 */
#define sp0 (*(s128 *)(sp + 0x000))
#define sp10 (*(s128 *)(sp + 0x010))
#define sp20 (*(s128 *)(sp + 0x020))
#define sp30 (*(s128 *)(sp + 0x030))
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
s8 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(M2C_UNK *, M2C_UNK *, s8 *); /* extern */
M2C_UNK func_0022B7A0(s8 *, s8 *);              /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_003DD490;
extern s32 B_003E11EC;
void BindGlobset(s8 *arg0) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK sp40;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_a0;
    s32 var_a2;
    s32 var_s4;
    s32 var_s6;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *temp_s3;
    s8 *temp_s7;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *var_s0;
    if (M2C_FIELD(arg0, s32 *, 0x4C) != -1) {
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) B_003E11EC;
    }
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0) {
        do {
            var_s4 = 0;
            temp_s7 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3C) + (var_a0 * 0x14));
            temp_s3 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x40) + (var_a0 * 0x28));
            if (M2C_FIELD(temp_s7, s8 *, 1) > 0) {
                var_s6 = 0;
                do {
                    temp_s1 = (s8 *)(M2C_FIELD(temp_s3, s32 *, 0x18) + var_s6);
                    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(temp_s1, s32 *, 0), M2C_FIELD(arg0, s32 *, 0));
                    M2C_FIELD(temp_s1, s8 **, 4) = temp_v0;
                    if (temp_v0 != NULL) {
                        temp_v1 = M2C_FIELD(temp_v0, s8 **, 0xC);
                        M2C_FIELD(temp_s1, s32 *, 0xC) = M2C_FIELD(temp_v1, s32 (**)(s8 *, s32, s8 *), 0x19C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x198), M2C_FIELD(temp_s1, s32 *, 8), temp_v0);
                    }
                    temp_a1 = M2C_FIELD(temp_s1, s32 *, 0xC);
                    if (temp_a1 == 0) {
                        temp_a0 = M2C_FIELD(temp_s3, s8 **, 4);
                        temp_s0 = temp_s1 + 0x10;
                        if (temp_a0 != NULL) {
                            M2C_FIELD(temp_s1, s128 *, 0x10) = (s128) M2C_FIELD(temp_a0, s128 *, 0x40);
                            M2C_FIELD(temp_s1, s128 *, 0x20) = (s128) M2C_FIELD(temp_a0, s128 *, 0x50);
                            M2C_FIELD(temp_s1, s128 *, 0x30) = (s128) M2C_FIELD(temp_a0, s128 *, 0x60);
                            M2C_FIELD(temp_s1, s128 *, 0x40) = (s128) M2C_FIELD(temp_a0, s128 *, 0x70);
                        } else {
                            memset(temp_s0, 0, 0x40);
                            M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
                            M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
                            M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
                            M2C_FIELD(temp_s1, s128 *, 0x10) = 1.0f;
                        }
                    } else {
                        temp_a1_2 = temp_a1 + 0x40;
                        if (M2C_FIELD(temp_s3, s8 **, 4) != NULL) {
                            InvertMatrix4Affine(&sp40, temp_a1_2);
                            __ml__FRC7MATRIX4T0((M2C_UNK *)(sp), &sp40, M2C_FIELD(temp_s3, s8 **, 4) + 0x40);
                        } else {
                            InvertMatrix4Affine((M2C_UNK *)(sp), temp_a1_2);
                        }
                        M2C_FIELD(temp_s1, s128 *, 0x10) = sp0;
                        M2C_FIELD(temp_s1, s128 *, 0x20) = sp10;
                        M2C_FIELD(temp_s1, s128 *, 0x30) = sp20;
                        M2C_FIELD(temp_s1, s128 *, 0x40) = sp30;
                    }
                    var_s4 += 1;
                    var_s6 += 0x50;
                } while (var_s4 < M2C_FIELD(temp_s7, s8 *, 1));
            }
            var_a0 += 1;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x38));
    }
    var_s0 = M2C_FIELD(arg0, s8 **, 0x58);
    if (var_s0 != NULL) {
        var_a2 = M2C_FIELD(var_s0, s32 *, 8);
loop_22:
        temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, var_a2, M2C_FIELD(arg0, s32 *, 0));
        if (temp_v0_2 != NULL) {
            func_0022B7A0(temp_v0_2, var_s0);
        }
        var_s0 = M2C_FIELD(var_s0, s8 **, 0x9C);
        if (var_s0 != NULL) {
            var_a2 = M2C_FIELD(var_s0, s32 *, 8);
            goto loop_22;
        }
    }
}
}
