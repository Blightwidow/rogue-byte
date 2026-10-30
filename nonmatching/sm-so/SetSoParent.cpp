typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSoParent {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ char pad90[0xA0];
};                                                  /* size = 0x130 */
#define sp50 (*(s128 *)(sp + 0x050))
#define sp60 (*(s128 *)(sp + 0x060))
#define sp70 (*(s128 *)(sp + 0x070))
void SetLoParent(s8 *, s8 *, s32, s32, s32);
void UpdateAloXfWorld(s8 *);
s32 __ml__FRC7MATRIX4T0(s128 *, s8 *, s8 *);
void func_001F2468(s8 *);
void func_001F26A8(s8 *);
void func_001F8668(s8 *, M2C_UNK);
s32 memset(s8 *, M2C_UNK, M2C_UNK);
void SetSoParent(s8 *arg0, s8 *arg1, s32 arg2, s32 arg3) {
    s32 unksp3C;
    f32 saved_reg_fp;
    s8 sp[0x70] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s128 sp80;
    M2C_UNK temp_a1;
    M2C_UNK var_fp;
    s32 temp_s6;
    s32 temp_v0_2;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_a4;
    s32 var_s7;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_a1;
    s8 *var_s0;
    var_fp = saved_reg_fp;
    if (arg3 & 3) {
        if ((int)((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
            sp30 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x60), s128 *, 0x70);
        } else {
            memset(sp, 0, 0x40);
            var_s0 = M2C_FIELD(arg0, s8 **, 0x60);
            unksp3C = 1.0f;
            if (var_s0 != NULL) {
                var_a1 = var_s0;
                do {
                    __ml__FRC7MATRIX4T0(&sp40, var_a1, sp);
                    sp30 = sp70;
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0xA0);
                    var_a1 = var_s0;
                } while (var_s0 != NULL);
            }
        }
    }
    temp_s6 = arg3 & 4;
    var_s7 = arg3 & 8;
    if (temp_s6 != 0) {
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108))));
        var_fp = vu_1;
        var_s7 = arg3 & 8;
    }
    if (var_s7 != 0) {
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        sp80 = M2C_FIELD(temp_v1_2, s128 (**)(s8 *), 0x114)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x110));
    }
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x10);
    var_a3 = 1;
    if (temp_v0 != NULL) {
        var_a4 = M2C_FIELD(temp_v0, s32 *, 0x54);
        var_a3 = M2C_FIELD(temp_v0, s32 *, 0x50);
    } else {
        var_a4 = 0;
    }
    var_a2 = arg2;
    if ((arg2 == 0) && (arg1 != NULL)) {
        var_a2 = M2C_FIELD(arg1, s32 *, 0x60);
    }
    var_a1_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
loop_18:
        temp_a0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x54) + (var_a1_2 << 8));
        temp_v0_2 = (s32) (M2C_FIELD(temp_a0, s32 *, 0xA0) - var_a4) >> 8;
        if ((temp_v0_2 >= 0) && (temp_v0_2 < var_a3)) {
            M2C_FIELD(temp_a0, s32 *, 0xA0) = var_a2;
        }
        var_a1_2 += 1;
        if (var_a1_2 < M2C_FIELD(arg0, s32 *, 0x50)) {
            goto loop_18;
        }
    }
    SetLoParent(arg0, arg1, arg2, arg3, var_a4);
    UpdateAloXfWorld(arg0);
    if (arg3 & 1) {
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0xE8), sp30);
    }
    if (arg3 & 2) {
        temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s8 *), 0xF4)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0xF0), sp);
    }
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(var_fp));
    temp_a1 = vu_2;
    if (temp_s6 != 0) {
        temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x118), temp_a1);
    }
    if (var_s7 != 0) {
        temp_v0_6 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x120), sp80);
    }
    func_001F2468(arg0);
    func_001F26A8(arg0);
    temp_v0_7 = M2C_FIELD(arg0, s8 **, 0x10);
    if ((temp_v0_7 != NULL) && !(M2C_FIELD(temp_v0_7, s64 *, 0x148) & (0x8000 << 0x14))) {
        func_001F8668(arg0, 0);
    }
}
}
