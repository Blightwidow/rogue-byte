typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
f32 F32Read__18CBinaryInputStream(s32);
s32 PvAllocSwClearImpl__Fi(s8 *, s32, s32);
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);
void ReadVector__18CBinaryInputStreamP6VECTOR(s32, s8 *);
s32 U16Read__18CBinaryInputStream(s32);
extern s128 g_2a2dc0;
void LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f0;
    s32 *temp_s2;
    s32 *var_a2;
    s32 *var_s0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    var_s1 = 0;
    temp_v0 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = PvAllocSwImpl__Fi(sp, temp_v0 * 0x10, 0x10);
    M2C_FIELD(arg0, s32 *, 0x10) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0) * 0x10, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
        do {
            temp_a1 = var_s1 * 0x10;
            var_s1 += 1;
            ReadVector__18CBinaryInputStreamP6VECTOR(arg1, (s8 *)(M2C_FIELD(arg0, s32 *, 4) + temp_a1));
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0));
    }
    temp_v0_2 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 8) = temp_v0_2;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = PvAllocSwImpl__Fi(sp, temp_v0_2 * 0x10, 0x10);
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
    if (M2C_FIELD(arg0, s32 *, 8) > 0) {
loop_4:
        var_s1_2 = 2;
        temp_s2 = (s32 *)(M2C_FIELD(arg0, s32 *, 0xC) + (var_a0 * 0x10));
        var_s0 = temp_s2;
        do {
            var_s1_2 -= 1;
            *var_s0 = U16Read__18CBinaryInputStream(arg1);
            var_s0 += 4;
        } while (var_s1_2 >= 0);
        var_s1_3 = 2;
        temp_f0 = F32Read__18CBinaryInputStream(arg1);
        M2C_FIELD(temp_s2, f32 *, 0xC) = temp_f0;
        var_a2 = temp_s2;
        temp_a1_2 = M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x14) + temp_f0);
        asm volatile("lqc2 vf3, (%0)" : : "r"((M2C_FIELD(temp_s2, s32 *, 0) * 0x10) + temp_a1_2));
        asm volatile("lqc2 vf2, (%0)" : : "r"((M2C_FIELD(temp_s2, s32 *, 4) * 0x10) + temp_a1_2));
        asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_s2, s32 *, 8) * 0x10) + temp_a1_2));
        asm volatile("vsub.xyzw vf2, vf2, vf3");
        asm volatile("vsub.xyzw vf1, vf1, vf3");
        asm volatile("vopmula.xyz ACC, vf2, vf1");
        asm volatile("vopmsub.xyz vf2, vf1, vf2");
        do {
            temp_v1 = *var_a2;
            var_s1_3 -= 1;
            var_a2 += 4;
            temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x10) + (temp_v1 * 0x10);
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_3));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_3));
        } while (var_s1_3 >= 0);
        var_a0 += 1;
        if (var_a0 < M2C_FIELD(arg0, s32 *, 8)) {
            goto loop_4;
        }
    }
    ReadVector__18CBinaryInputStreamP6VECTOR(arg1, arg0 + 0x20);
    var_s1_4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
loop_13:
        temp_v0_4 = (var_s1_4 * 0x10) + M2C_FIELD(arg0, s32 *, 0x10);
        asm volatile("lqc2 vf3, (%0)" : : "r"(temp_v0_4));
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        if (vu_1 < 0.0001f) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dc0));
        } else {
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf3, Q");
        }
        asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_4));
        var_s1_4 += 1;
        if (var_s1_4 < M2C_FIELD(arg0, s32 *, 0)) {
            goto loop_13;
        }
    }
}
}
