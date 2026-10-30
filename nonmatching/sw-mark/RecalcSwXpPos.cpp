typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RecalcSwXpPos {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s32 ConvertXfPos(s32, M2C_UNK, s128);
void RecalcSwXpPos(s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 var_v0_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_s1;
    s8 *var_s0;
    var_v1 = 0;
    if (arg1 > 0) {
        var_v0 = 0 * 4;
        do {
            var_s2 = 0;
            temp_s1 = (s8 *)(*(s32 *)(var_v0 + arg2));
            var_s0 = temp_s1;
loop_3:
            temp_a0 = M2C_FIELD(var_s0, s32 *, 4);
            if (temp_a0 != 0) {
                if (var_s2 != 0) {
                    temp_v0 = M2C_FIELD(temp_s1, s32 *, 0x9C);
                    if ((temp_v0 == 7) || (temp_v0 == 9)) {
                        asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(temp_a0));
                        var_v0_2 = M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0), f32 *, 8);
                        goto block_13;
                    }
                    goto block_14;
                }
                temp_v1 = M2C_FIELD(temp_s1, s32 *, 0x9C);
                if ((temp_v1 < 7) && (temp_v1 >= 4)) {
                    var_v0_2 = -M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0), f32 *, 8);
                    asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(temp_a0));
block_13:
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(var_v0_2));
                    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(temp_s1));
                    asm volatile("vadda.xyzw ACC, vf0, vf3");
                    asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
                    asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(var_s0));
                } else {
block_14:
                    M2C_FIELD(var_s0, s128 *, 0x10) = ConvertXfPos(temp_a0, 0, M2C_FIELD(var_s0, s128 *, 0x20));
                }
            }
            var_s2 += 1;
            var_s0 += 0x40;
            if (var_s2 < 2) {
                goto loop_3;
            }
            asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(temp_s1));
            var_v1 += 1;
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_s1));
            asm volatile("vsub.xyzw vf2, vf2, vf3");
            asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(temp_s1));
            asm volatile("vmul.xyz vf1, vf1, vf2");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf3, vf1z");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            M2C_FIELD(temp_s1, s32 *, 0x90) = vu_1;
            var_v0 = var_v1 * 4;
        } while (var_v1 < arg1);
    }
}
}
