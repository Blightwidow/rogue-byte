typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetMeterState {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s32 spC;                             /* inferred */
    /* 0x10 */ char pad10[0x90];
};                                                  /* size = 0xA0 */
#define spC (*(s32 *)(sp + 0x0C))
s32 FGadgetAcquired(s32);                           /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK SeekBlotLabel(s8 *, M2C_UNK, f32);        /* extern */
M2C_UNK func_00213928(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_00213B00(s8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_002BCD00;
extern s32 D_002C2DE8;
extern s32 D_002C3028;
extern s32 D_002C3148;
void SetMeterState(s8 *arg0, u32 arg1) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK temp_a0;
    M2C_UNK temp_a1;
    M2C_UNK temp_a2_3;
    M2C_UNK temp_v1_2;
    s32 *var_s0;
    s32 *var_s2;
    s32 temp_s0;
    s32 var_a1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    u32 temp_v1;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_4;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x30);
    if ((temp_v1 != arg1) && (temp_a2 = M2C_FIELD(arg0, s8 **, 0x38), (temp_a2 != NULL))) {
        if ((temp_v1 == 2) || (var_v0 = arg1 < 8U, (temp_v1 == 6))) {
            temp_v0 = M2C_FIELD(temp_a2, s8 **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s32, s8 *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x3C), temp_a2);
            var_v0 = arg1 < 8U;
        }
        M2C_FIELD(arg0, u32 *, 0x30) = arg1;
        if (var_v0 != 0) {
            switch (arg1) {
            case 0:
            case 5:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x44);
block_26:
                temp_v0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x38), s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s32, s8 *), 0x18C)(M2C_FIELD(arg0, s8 **, 0x38) + M2C_FIELD(temp_v0_2, s16 *, 0x188), var_a1, M2C_FIELD(arg0, s8 **, 0x38));
                return;
            case 1:
                temp_a2_2 = M2C_FIELD(arg0, s8 **, 0x38);
                var_s5 = 0;
                var_s0 = NULL;
                temp_v0_3 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s32, s8 *), 0x18C)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x3C), temp_a2_2);
                func_00213B00(M2C_FIELD(arg0, s8 **, 0x38), 0x34F);
                SeekBlotLabel(M2C_FIELD(arg0, s8 **, 0x38), 0x34F, 1.0f - M2C_FIELD(arg0, f32 *, 0x20));
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x35) != 0) {
                    var_s5 = 0x12;
                    var_s0 = &D_002C2DE8;
                } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x37) != 0) {
                    var_s5 = 9;
                    var_s0 = &D_002C3028;
                } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x36) != 0) {
                    var_s5 = 8;
                    var_s0 = &D_002C3148;
                }
                var_s2 = var_s0;
                var_s4 = 0;
                var_s3 = 0;
loop_17:
                if (var_s3 < var_s5) {
                    temp_s0 = *var_s2;
                    if (FGadgetAcquired(temp_s0) != 0) {
                        temp_v0_4 = (s8 *)((temp_s0 << 5) + &D_002BCD00);
                        s32 vu_1;
                        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(temp_v0_4));
                        s32 vu_2;
                        asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(temp_v0_4), "0"(vu_1));
                        temp_v1_2 = vu_2;
                        s32 vu_3;
                        asm volatile("ldl %0, 0xf(%1)" : "=r"(vu_3) : "r"(temp_v0_4));
                        s32 vu_4;
                        asm volatile("ldr %0, 0x8(%1)" : "=r"(vu_4) : "r"(temp_v0_4), "0"(vu_3));
                        temp_a0 = vu_4;
                        s32 vu_5;
                        asm volatile("ldl %0, 0x17(%1)" : "=r"(vu_5) : "r"(temp_v0_4));
                        s32 vu_6;
                        asm volatile("ldr %0, 0x10(%1)" : "=r"(vu_6) : "r"(temp_v0_4), "0"(vu_5));
                        temp_a1 = vu_6;
                        s32 vu_7;
                        asm volatile("ldl %0, 0x1f(%1)" : "=r"(vu_7) : "r"(temp_v0_4));
                        s32 vu_8;
                        asm volatile("ldr %0, 0x18(%1)" : "=r"(vu_8) : "r"(temp_v0_4), "0"(vu_7));
                        temp_a2_3 = vu_8;
                        asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v1_2), "r"(sp));
                        asm volatile("sdr %0, (%1)" : : "r"(temp_v1_2), "r"(sp));
                        asm volatile("sdl %0, 0xf(%1)" : : "r"(temp_a0), "r"(sp));
                        asm volatile("sdr %0, 0x8(%1)" : : "r"(temp_a0), "r"(sp));
                        asm volatile("sdl %0, 0x17(%1)" : : "r"(temp_a1), "r"(sp));
                        asm volatile("sdr %0, 0x10(%1)" : : "r"(temp_a1), "r"(sp));
                        asm volatile("sdl %0, 0x1f(%1)" : : "r"(temp_a2_3), "r"(sp));
                        asm volatile("sdr %0, 0x18(%1)" : : "r"(temp_a2_3), "r"(sp));
                        var_s2 += 0x20;
                        if (spC > 0) {
                            var_s4 = 1;
                        } else {
                            goto block_16;
                        }
                    } else {
                        var_s2 += 0x20;
block_16:
                        var_s3 += 1;
                        goto loop_17;
                    }
                }
                temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x38);
                if (var_s4 != 0) {
                    func_00213B00(temp_a0_2, 0x350);
                    SeekBlotLabel(M2C_FIELD(arg0, s8 **, 0x38), 0x350, 1.0f - M2C_FIELD(arg0, f32 *, 0x28));
                    return;
                }
                func_00213928(temp_a0_2, 0x350);
                return;
            case 2:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x40);
                goto block_26;
            case 6:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x48);
                goto block_26;
            case 7:
                temp_a2_4 = M2C_FIELD(arg0, s8 **, 0x38);
                temp_v0_5 = M2C_FIELD(temp_a2_4, s8 **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, s32, s8 *), 0x18C)(temp_a2_4 + M2C_FIELD(temp_v0_5, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x4C), temp_a2_4);
                break;
            }
        }
    }
}
}
