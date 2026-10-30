typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSwAaox__FP2SW {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ f32 *sp8;                            /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ char pad14[0xBC];
};                                                  /* size = 0xD0 */
M2C_UNK UpdateSwPox(s8 *, s32, s32, M2C_UNK);     /* extern */
M2C_UNK memmove(s8 *, s8 *, s32);               /* extern */
void UpdateSwAaox__FP2SW(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 *sp8;
    s8 *sp10;
    M2C_UNK temp_v0;
    M2C_UNK temp_v0_2;
    f32 *temp_v1;
    f32 temp_f20;
    f32 var_f21;
    s32 var_a0;
    s32 var_s3;
    s32 var_v1;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *var_s0;
    s8 *var_s1;
    if (M2C_FIELD(arg0, s32 *, 0x3CCC) != 0) {
        M2C_FIELD(arg0, s32 *, 0x3CCC) = 0;
        if (M2C_FIELD(arg0, s32 *, 0x3CD0) != 0) {
            var_v1 = 0;
            sp10 = arg0 + 0x3CD4;
            do {
                temp_s1 = (s8 *)(*(sp10 + (var_v1 * 4)));
                var_a0 = M2C_FIELD(arg0, s32 *, 0x3CD0) - 1;
                var_s1 = temp_s1 + 0xC;
                var_f21 = *M2C_FIELD(temp_s1, f32 **, 8);
                if (var_a0 > 0) {
                    do {
                        temp_f20 = *M2C_FIELD(var_s1, f32 **, 8);
                        if (var_f21 <= temp_f20) {
                            var_f21 = temp_f20;
                            var_s3 = var_a0 - 1;
                        } else {
                            var_s0 = var_s1 - 0xC;
                            var_s3 = var_a0 - 1;
loop_12:
                            if ((u32) var_s0 >= (u32) temp_s1) {
                                if (!(*M2C_FIELD(var_s0, f32 **, 8) <= temp_f20)) {
                                    if (M2C_FIELD(var_s1, s32 *, 0) != M2C_FIELD(var_s0, s32 *, 0)) {
                                        UpdateSwPox(arg0, M2C_FIELD(var_s1, s32 *, 4), M2C_FIELD(var_s0, s32 *, 4), 0);
                                    }
                                    var_s0 -= 0xC;
                                    goto loop_12;
                                }
                            }
                            temp_s0 = var_s0 + 0xC;
                            s32 vu_1;
                            asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(var_s1));
                            s32 vu_2;
                            asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(var_s1), "0"(vu_1));
                            temp_v0 = vu_2;
                            temp_v1 = M2C_FIELD(var_s1, f32 **, 8);
                            asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v0), "r"(sp));
                            asm volatile("sdr %0, (%1)" : : "r"(temp_v0), "r"(sp));
                            sp8 = temp_v1;
                            memmove(temp_s0 + 0xC, temp_s0, ((s32) ((var_s1 - temp_s0) * 0xAAAAAAAB) >> 2) * 0xC);
                            s32 vu_3;
                            asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(sp));
                            s32 vu_4;
                            asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
                            temp_v0_2 = vu_4;
                            asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v0_2), "r"(temp_s0));
                            asm volatile("sdr %0, (%1)" : : "r"(temp_v0_2), "r"(temp_s0));
                            M2C_FIELD(temp_s0, f32 **, 8) = temp_v1;
                        }
                        var_a0 = var_s3;
                        var_s1 += 0xC;
                    } while (var_a0 > 0);
                }
                var_v1 += 1;
            } while (var_v1 < 3);
        }
    }
}
}
