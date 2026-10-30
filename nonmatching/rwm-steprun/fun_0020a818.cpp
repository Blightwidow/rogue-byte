typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0020A818 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0x20];
};                                                  /* size = 0x60 */
M2C_UNK DecomposeCylind(M2C_UNK, f32 *, M2C_UNK, M2C_UNK); /* extern */
s32 FInsideCmFrustrum(M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
f32 GetAlertPan(s8 *);                            /* extern */
s128 PosLoWorld(...);         /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
extern M2C_UNK B_002DDF40;
s32 func_0020A818(s8 *arg0, s8 *arg1, s8 **arg2, s32 arg3, s32 arg4) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 sp10;
    f32 sp14;
    s128 sp20;
    s128 sp30;
    s32 temp_v1;
    s32 var_a3;
    s32 var_a4;
    s32 var_v0;
    s8 **var_a2;
    var_a2 = arg2;
    var_a3 = arg3;
    var_a4 = arg4;
    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (M2C_FIELD(arg1, s32 *, 0xF30) == 0) {
            var_a4 = M2C_FIELD(arg0, s32 *, 0x28);
            var_a3 = 0;
            if (var_a4 > 0) {
                var_a2 = (s8 **)(arg0 + 0x2C);
loop_4:
                var_a3 += 1;
                if (M2C_FIELD(*var_a2, s32 *, 0xF3C) == 0) {
                    var_a2 += 4;
                    if (var_a3 >= var_a4) {
                        goto block_6;
                    }
                    goto loop_4;
                }
                goto block_15;
            }
        }
block_6:
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
        if (temp_v1 == 0) {
            var_v0 = 1;
            if (M2C_FIELD(arg1, s32 *, 0xF34) == 0) {
                sp20 = PosLoWorld(arg0, arg1, var_a2, var_a3, var_a4);
                asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                var_v0 = 0;
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(0));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                if (FInsideCmFrustrum(&B_002DDF40, vu_2, vu_1, 0) != 0) {
                    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0, M2C_FIELD(arg0, s8 **, 0xC))));
                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    DecomposeCylind(vu_3, &sp10, 0, 0);
                    var_v0 = 1;
                    if (M2C_FIELD(arg0, f32 *, 0x18) < fabsf(RadNormalize__Ff(sp10 - GetAlertPan(arg0)))) {
                        goto block_15;
                    }
                }
            }
            /* Duplicate return node #18. Try simplifying control flow for better match */
            return var_v0;
        }
        if (temp_v1 > 0) {
            if (temp_v1 != 1) {
                return 1;
            }
            sp30 = PosLoWorld(arg0, arg1, var_a2, var_a3, var_a4);
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0, M2C_FIELD(arg0, s8 **, 0xC))));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
            DecomposeCylind(vu_4, &sp14, 0, 0);
            var_v0 = 0;
            if (!(M2C_FIELD(arg0, f32 *, 0x18) < fabsf(RadNormalize__Ff(sp14 - GetAlertPan(arg0))))) {
                goto block_17;
            }
            /* Duplicate return node #18. Try simplifying control flow for better match */
            return var_v0;
        }
block_17:
        var_v0 = 1;
        return var_v0;
    }
block_15:
    return 0;
}
}
