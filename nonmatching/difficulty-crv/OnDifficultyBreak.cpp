typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OnDifficultyBreak {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK CpdprizeAttractSwDprizes(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
f32 GetSuck(...);                  /* extern */
s32 NRandInRange(...);                    /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
void OnDifficultyBreak(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK temp_s4;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    var_s2 = arg2;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    temp_s4 = vu_1;
    if (M2C_FIELD(arg0, s32 *, 0) <= 0) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x14);
        temp_f4 = GetSuck(&B_002DE578);
        temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x30);
        temp_a0 = M2C_FIELD(temp_v0, s32 *, 0x28);
        if (temp_a0 == temp_v1) {
            var_s0 = temp_v1;
        } else if (temp_a0 < temp_v1) {
            var_s0 = temp_a0 + (s32) (temp_f4 * (((f32) temp_v1 + 0.999f) - (f32) temp_a0));
        } else {
            var_s0 = temp_v1 + (s32) ((1.0f - temp_f4) * (((f32) temp_a0 + 0.999f) - (f32) temp_v1));
        }
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0x14);
        temp_v1_2 = M2C_FIELD(temp_v0_2, s32 *, 0x34);
        temp_a1 = M2C_FIELD(temp_v0_2, s32 *, 0x2C);
        temp_f4_2 = GetSuck(&B_002DE578, &B_002DE578);
        if (temp_a1 == temp_v1_2) {
            var_a1 = temp_v1_2;
        } else if (temp_a1 < temp_v1_2) {
            var_a1 = temp_a1 + (s32) (temp_f4_2 * (((f32) temp_v1_2 + 0.999f) - (f32) temp_a1));
        } else {
            var_a1 = temp_v1_2 + (s32) ((1.0f - temp_f4_2) * (((f32) temp_a1 + 0.999f) - (f32) temp_v1_2));
        }
        M2C_FIELD(arg0, s32 *, 0) = NRandInRange(var_s0, var_a1);
    }
    if (M2C_FIELD(arg0, s32 *, 4) <= 0) {
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0x14);
        temp_f4_3 = GetSuck(&B_002DE578);
        temp_v1_3 = M2C_FIELD(temp_v0_3, s32 *, 0x40);
        temp_a0_2 = M2C_FIELD(temp_v0_3, s32 *, 0x38);
        if (temp_a0_2 == temp_v1_3) {
            var_s0_2 = temp_v1_3;
        } else if (temp_a0_2 < temp_v1_3) {
            var_s0_2 = temp_a0_2 + (s32) (temp_f4_3 * (((f32) temp_v1_3 + 0.999f) - (f32) temp_a0_2));
        } else {
            var_s0_2 = temp_v1_3 + (s32) ((1.0f - temp_f4_3) * (((f32) temp_a0_2 + 0.999f) - (f32) temp_v1_3));
        }
        temp_v0_4 = M2C_FIELD(arg0, s8 **, 0x14);
        temp_v1_4 = M2C_FIELD(temp_v0_4, s32 *, 0x44);
        temp_a1_2 = M2C_FIELD(temp_v0_4, s32 *, 0x3C);
        temp_f4_4 = GetSuck(&B_002DE578, &B_002DE578);
        if (temp_a1_2 == temp_v1_4) {
            var_a1_2 = temp_v1_4;
        } else if (temp_a1_2 < temp_v1_4) {
            var_a1_2 = temp_a1_2 + (s32) (temp_f4_4 * (((f32) temp_v1_4 + 0.999f) - (f32) temp_a1_2));
        } else {
            var_a1_2 = temp_v1_4 + (s32) ((1.0f - temp_f4_4) * (((f32) temp_a1_2 + 0.999f) - (f32) temp_v1_4));
        }
        M2C_FIELD(arg0, s32 *, 4) = NRandInRange(var_s0_2, var_a1_2);
    }
    temp_a2 = M2C_FIELD(arg0, s32 *, 0) + ((FIsBasicDerivedFrom(arg4, 0x38) != 0) ? -2 : -1);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + arg3);
    M2C_FIELD(arg0, s32 *, 0) = temp_a2;
    if (var_s2 < 0) {
        temp_v0_5 = M2C_FIELD(arg0, s8 **, 0x14);
        if (temp_a2 <= 0) {
            var_a1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x14);
            var_a0 = M2C_FIELD(temp_v0_5, s32 *, 0x10);
        } else {
            var_a1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x1C);
            var_a0 = M2C_FIELD(temp_v0_5, s32 *, 0x18);
        }
        var_s2 = NRandInRange(var_a0, var_a1_3, temp_a2);
    }
    if (var_s2 > 0) {
        s64 vu_2;
        asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s4));
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5B, vu_2, arg4, var_s2);
    }
    if (M2C_FIELD(arg0, s32 *, 4) <= 0) {
        s64 vu_3;
        asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s4));
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5D, vu_3, arg4, 1);
    }
}
}
