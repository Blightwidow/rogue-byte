typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetSeqnodeObjectPosRad {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x68];
};                                                  /* size = 0x80 */
#define sp14 (*(f32 *)(sp + 0x14))
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
void FindCrvClosestPointAll(s8 *, M2C_UNK, M2C_UNK, s8 *, f32 *, M2C_UNK, M2C_UNK);
s32 PosLoWorld(s8 *);
f32 atan2f(f32, f32);
void GetSeqnodeObjectPosRad(s8 *arg0, s8 *arg1, s128 *arg2, f32 *arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s128 sp0;
    f32 sp10;
    f32 *temp_s0;
    f32 *temp_s0_2;
    f32 var_f0;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *var_s1;
    var_s1 = M2C_FIELD(arg0, s8 **, 0x24);
    if (var_s1 == NULL) {
        var_s1 = M2C_FIELD(arg0, s8 **, 0x44);
    }
    if (arg1 != NULL) {
        if (FIsBasicDerivedFrom(arg1, 0xA) != 0) {
            s64 vu_1;
            asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(var_s1)));
            FindCrvClosestPointAll(arg1, vu_1, 0, sp, &sp10, 0, 0);
            var_f0 = atan2f(sp14, sp10);
        } else {
            sp0 = PosLoWorld(arg1);
            temp_v1 = M2C_FIELD(arg1, s8 **, 0xC);
            temp_v1_2 = M2C_FIELD(arg1, s8 **, 0xC);
            temp_s0 = M2C_FIELD(temp_v1, f32 *(**)(s8 *), 0xFC)(arg1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            var_f0 = atan2f(M2C_FIELD(temp_s0, f32 *, 4), *M2C_FIELD(temp_v1_2, f32 *(**)(s8 *), 0xFC)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0xF8)));
        }
    } else {
        sp0 = PosLoWorld(var_s1);
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        if (FIsBasicDerivedFrom(var_s1, 0x33) != 0) {
            asm volatile("lqc2 vf2, 0x240(%0)" : : "r"(var_s1));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            var_f0 = M2C_FIELD(var_s1, f32 *, 0x1A8);
        } else {
            temp_v1_3 = M2C_FIELD(var_s1, s8 **, 0xC);
            temp_v1_4 = M2C_FIELD(var_s1, s8 **, 0xC);
            temp_s0_2 = M2C_FIELD(temp_v1_3, f32 *(**)(s8 *), 0xFC)(var_s1 + M2C_FIELD(temp_v1_3, s16 *, 0xF8));
            var_f0 = atan2f(M2C_FIELD(temp_s0_2, f32 *, 4), *M2C_FIELD(temp_v1_4, f32 *(**)(s8 *), 0xFC)(var_s1 + M2C_FIELD(temp_v1_4, s16 *, 0xF8)));
        }
    }
    if (arg2 != NULL) {
        *arg2 = sp0;
    }
    if (arg3 != NULL) {
        *arg3 = var_f0;
    }
}
}
