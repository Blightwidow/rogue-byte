typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BC2F8 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ char pad50[0xA0];
};                                                  /* size = 0xF0 */
#define sp40 (*(s128 *)(sp + 0x40))
s32 CmpPosXy(M2C_UNK, M2C_UNK);                     /* extern */
s32 Obstacle_IposWrap(s8 *, s32);                 /* extern */
s32 OrientXy(s128, M2C_UNK, M2C_UNK);               /* extern */
s32 func_001BC2F8(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_v0;
    s8 *temp_v1;
    var_v0 = 2;
    if (M2C_FIELD(arg0, s32 *, 0xE8) >= 2) {
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        var_s6 = 0;
        var_s5 = 0;
        var_s3 = 0;
        temp_v0 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
        asm volatile("lqc2 vf6, (%0)" : : "r"(temp_v0));
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xF4);
        asm volatile("sqc2 vf6, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(temp_v0));
        asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0));
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_v0));
        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_v1_2));
        asm volatile("lqc2 vf4, (%0)" : : "r"(temp_v1_2));
        asm volatile("vmulax.xyz ACC, vf6, vf3x");
        asm volatile("vmadday.xyz ACC, vf5, vf3y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
        asm volatile("vmaddw.xyz vf7, vf1, vf0w");
        asm volatile("vmulax.xyz ACC, vf6, vf4x");
        asm volatile("vmadday.xyz ACC, vf5, vf4y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
        asm volatile("vmaddw.xyz vf8, vf1, vf0w");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_1));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf8" : "=r"(vu_2));
        var_s4 = CmpPosXy(vu_2, vu_1);
        if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 0) {
loop_3:
            temp_v0_2 = Obstacle_IposWrap(arg0, var_s5);
            temp_v0_3 = Obstacle_IposWrap(arg0, temp_v0_2 + 1);
            temp_v1_3 = M2C_FIELD(arg0, s32 *, 0xF4);
            asm volatile("lqc2 vf5, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, (%0)" : : "r"((Obstacle_IposWrap(arg0, temp_v0_3 + 1) * 0x10) + temp_v1_3));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf5, vf3x");
            asm volatile("vmadday.xyz ACC, vf4, vf3y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
            asm volatile("vmaddw.xyz vf7, vf1, vf0w");
            asm volatile("lqc2 vf6, (%0)" : : "r"((temp_v0_3 * 0x10) + temp_v1_3));
            asm volatile("lqc2 vf3, (%0)" : : "r"((temp_v0_2 * 0x10) + temp_v1_3));
            asm volatile("vmulax.xyz ACC, vf5, vf6x");
            asm volatile("vmadday.xyz ACC, vf4, vf6y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf6z");
            asm volatile("vmaddw.xyz vf6, vf1, vf0w");
            asm volatile("vmulax.xyz ACC, vf5, vf3x");
            asm volatile("vmadday.xyz ACC, vf4, vf3y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
            asm volatile("vmaddw.xyz vf8, vf1, vf0w");
            asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
            asm volatile("sqc2 vf7, 0x60(%0)" : : "r"(sp));
            asm volatile("sqc2 vf8, 0x40(%0)" : : "r"(sp));
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_3));
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_4));
            temp_v0_4 = CmpPosXy(vu_4, vu_3);
            asm volatile("lqc2 vf6, 0x50(%0)" : : "r"(sp));
            asm volatile("lqc2 vf7, 0x60(%0)" : : "r"(sp));
            if (temp_v0_4 != 0) {
                var_s6 = ((temp_v0_4 ^ -var_s4) == 0) ? (var_s6 + 1) : var_s6;
            }
            var_s4 = temp_v0_4;
            s32 vu_5;
            asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_5));
            s32 vu_6;
            asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_6));
            temp_v0_5 = OrientXy(sp40, vu_6, vu_5);
            if ((temp_v0_5 == 0) || (var_s3 = temp_v0_5, (temp_v0_5 != -var_s3))) {
                var_s5 += 1;
                if (var_s5 >= (M2C_FIELD(arg0, s32 *, 0xE8) - 1)) {
                    goto block_8;
                }
                goto loop_3;
            }
            var_v0 = 0;
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return var_v0;
        }
block_8:
        if (var_s6 >= 3) {
            return var_s3 == 0;
        }
        switch (var_s3) {                           /* irregular */
        case -1:
            return 4;
        case 1:
            return 3;
        default:
            return 2;
        }
    } else {
        return var_v0;
    }
}
}
