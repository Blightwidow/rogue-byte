typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ChooseJtCaneSwing {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 FCheckJtCaneSide(s8 *);                       /* extern */
s32 FCheckLm__FP2LMf(M2C_UNK *, M2C_UNK);           /* extern */
s8 *GoalStack_PgoalFind(s8 *, M2C_UNK);         /* extern */
s128 PosLoWorld(...);                      /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK SetJtState(s8 *, M2C_UNK, M2C_UNK);       /* extern */
f32 atan2f(f32, f32);                               /* extern */
extern M2C_UNK D_002BF4B0;
extern f32 D_FLT_002BF4AC;
s32 ChooseJtCaneSwing(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    f32 *temp_s0;
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x10DC);
    if (temp_a0 != NULL) {
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0, arg0, PosLoWorld(arg0, temp_a0))));
        asm volatile("vsub.xyzw vf2, vf1, vf3");
        asm volatile("vmul.xy vf1, vf2, vf2");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        var_v0 = 0;
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        if (vu_1 < D_FLT_002BF4AC) {
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            s64 vu_3;
            asm volatile("pextuw %0, %1, %0" : "=r"(vu_3) : "r"(0), "r"(vu_2));
            var_v0 = FCheckLm__FP2LMf(&D_002BF4B0, vu_3) != 0;
        }
        if (var_v0 != 0) {
            temp_v0 = GoalStack_PgoalFind(M2C_FIELD(arg0, s8 **, 0x10DC) + 0x26C, 0xB1);
            if (((s32)temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x5C) == (s32)arg0)) {
                temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x50);
                if ((temp_v1 < 2) && (temp_v1 >= 0)) {
                    SetJtState(arg0, 0x10, -1);
                    return -1;
                }
            }
        }
        goto block_9;
    }
block_9:
    if (M2C_FIELD(arg0, s32 *, 0x18D0) != 5) {
        var_s0 = (M2C_FIELD(arg0, s32 *, 0x18C8) == 0) ? 0xC : 0xE;
    } else {
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_s0 = M2C_FIELD(temp_v1_2, f32 *(**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0xF8));
        temp_f0 = RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18) - atan2f(M2C_FIELD(temp_s0, f32 *, 4), *M2C_FIELD(temp_v1_3, f32 *(**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0xF8))));
        temp_f1 = fabsf(temp_f0);
        var_s0 = 0xE;
        if (!(temp_f1 < 0.7853982f)) {
            var_s0 = 0x10;
            if (!(temp_f1 > 2.3561945f)) {
                var_s0 = 0x14;
                if (temp_f0 > 0.0f) {
                    var_s0 = 0x12;
                }
            }
        }
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x18D8);
    switch (temp_v0_2) {
    case 12:
    case 14:
    case 16:
    case 18:
    case 20:
        var_s0 += 1;
        break;
    default:
        var_s0 = (FCheckJtCaneSide(arg0) != 0) ? (var_s0 + 1) : var_s0;
        break;
    }
    return var_s0;
}
}
