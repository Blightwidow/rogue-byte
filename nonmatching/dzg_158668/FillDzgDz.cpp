typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FillDzgDz {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ s8 *sp30;                          /* inferred */
    /* 0x34 */ char pad34[0xAC];
};                                                  /* size = 0xE0 */
s32 *PvAllocStackImpl__Fi(s8 *, s32, s32);        /* extern */
void FillDzgDz(s8 *arg0, s32 arg1, s8 *arg2, s8 *arg3) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s8 *sp30;
    M2C_UNK *var_s0_2;
    s32 *var_a2;
    s32 *var_s3;
    s32 var_a0;
    s32 var_a3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_t0;
    s8 **var_s0;
    s8 *temp_a0;
    s8 *temp_s6;
    s8 *temp_t0;
    s8 *temp_t1;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_a1;
    s8 *var_s1;
    var_s2 = 0;
    temp_s6 = M2C_FIELD(arg3, s8 **, 0x50);
    sp30 = arg2;
    var_s0 = (s8 **)(temp_s6 + 8);
    do {
        temp_t1 = *var_s0;
        if (temp_t1 != NULL) {
            temp_v1 = M2C_FIELD(temp_t1, s8 **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, s8 *, s8 *, s32), 0x224)(temp_t1 + M2C_FIELD(temp_v1, s16 *, 0x220), sp30, arg3, arg1);
        }
        var_s2 += 1;
        var_s0 += 0x40;
    } while (var_s2 < 2);
    var_s3 = PvAllocStackImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x50) * 0x10, 0x10);
    M2C_FIELD(arg3, s32 **, 0x54) = var_s3;
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
        do {
            var_s0_2 = &sp10;
            var_s1 = (s8 *)(*(s32 *)((var_a0 * 4) + M2C_FIELD(arg0, s32 *, 0x54)));
            var_s2_2 = 1;
loop_7:
            temp_t0 = M2C_FIELD(var_s1, s8 **, 8);
            if (temp_t0 == NULL) {
                M2C_FIELD(var_s0_2, s32 *, 8) = 0;
                goto block_19;
            }
            if ((s32)temp_t0 != M2C_FIELD(temp_s6, s32 *, 8)) {
                if ((s32)temp_t0 != M2C_FIELD(temp_s6, s32 *, 0x48)) {
                    M2C_FIELD(var_s0_2, s32 *, 8) = 0;
block_19:
                    M2C_FIELD(var_s0_2, s32 *, 4) = 0;
                    M2C_FIELD(var_s0_2, s32 *, 0) = 0;
                } else {
                    var_a1 = arg3 + 0x20;
                    goto block_18;
                }
            } else {
                var_a1 = arg3;
block_18:
                M2C_FIELD(M2C_FIELD(temp_t0, s8 **, 0xC), M2C_UNK (**)(s8 *, s8 *, s128, M2C_UNK *), 0x22C)(temp_t0 + M2C_FIELD(M2C_FIELD(temp_t0, s8 **, 0xC), s16 *, 0x228), var_a1, M2C_FIELD(var_s1, s128 *, 0x10), var_s0_2);
            }
            var_s0_2 += 0x10;
            var_s2_2 -= 1;
            var_s1 += 0x40;
            if (var_s2_2 >= 0) {
                goto loop_7;
            }
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
            var_a0 += 1;
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, (%0)" : : "r"(var_s3));
            var_s3 += 0x10;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x50));
    }
    var_a2 = PvAllocStackImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 4) * 4, 0x10);
    M2C_FIELD(sp30, s32 **, 0x18) = var_a2;
    var_a3 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) > 0) {
        var_t0 = 0;
        do {
            var_a3 += 1;
            temp_v1_2 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x60) + var_t0);
            temp_a0 = M2C_FIELD(temp_v1_2, s8 **, 0x50);
            var_t0 += 0x60;
            asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(temp_v1_2));
            asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 0xA8) * 0x10) + M2C_FIELD(arg3, s32 **, 0x54)));
            asm volatile("vmul.xyz vf2, vf2, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            *var_a2 = vu_1;
            var_a2 += 4;
        } while (var_a3 < M2C_FIELD(arg0, s32 *, 4));
    }
}
}
