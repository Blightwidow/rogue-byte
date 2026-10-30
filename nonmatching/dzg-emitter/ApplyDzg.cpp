typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ApplyDzg {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x5C];
};                                                  /* size = 0x70 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s128 LimitVectorLength__FP6VECTORfT0(s128, f32);    /* extern */
M2C_UNK PvAllocStackImpl__Fi(s32 *, M2C_UNK);       /* extern */
void ApplyDzg(s8 *arg0, f32 fparg0, f32 fparg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a2;
    s32 var_s1;
    s32 var_v1;
    s8 *temp_a1;
    s8 *temp_a3;
    s8 *temp_s0_2;
    s8 *var_a0_2;
    CStackFrame_Construct(sp);
    sp10 = M2C_FIELD(arg0, s32 *, 0x58) << 5;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    PvAllocStackImpl__Fi(&sp10, 0x10);
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) > 0) {
        var_v1 = 0 * 0x28;
        do {
            temp_a1 = (s8 *)(M2C_FIELD(arg0, s32 *, 8) + var_v1);
            if (M2C_FIELD(temp_a1, f32 *, 0xC) != 0.0f) {
                var_a2 = 0;
                temp_a3 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x60) + (var_a0 * 0x60));
                var_a0_2 = temp_a3;
                do {
                    temp_s0 = M2C_FIELD((M2C_FIELD(temp_a3, s32 *, 0x50) + (var_a2 << 6)), s32 *, 8);
                    if (temp_s0 != 0) {
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_a1, f32 *, 0xC)));
                        asm volatile("lqc2 vf3, 0xf0(%0)" : : "r"(temp_s0));
                        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(var_a0_2));
                        asm volatile("vadda.xyzw ACC, vf0, vf3");
                        asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
                        asm volatile("lqc2 vf4, 0x100(%0)" : : "r"(temp_s0));
                        asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(temp_s0));
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_a1, f32 *, 0xC)));
                        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(var_a0_2));
                        asm volatile("vadda.xyzw ACC, vf0, vf4");
                        asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
                        asm volatile("sqc2 vf4, 0x100(%0)" : : "r"(temp_s0));
                    }
                    var_a2 += 1;
                    var_a0_2 += 0x20;
                } while (var_a2 < 2);
            }
            var_a0 += 1;
            var_v1 = var_a0 * 0x28;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 4));
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x58) > 0) {
loop_10:
        temp_v0 = var_s1 * 4;
        var_s1 += 1;
        temp_s0_2 = (s8 *)(*(s32 *)(temp_v0 + M2C_FIELD(arg0, s32 *, 0x5C)));
        M2C_FIELD(temp_s0_2, s128 *, 0xF0) = LimitVectorLength__FP6VECTORfT0(M2C_FIELD(temp_s0_2, s128 *, 0xF0), fparg0);
        M2C_FIELD(temp_s0_2, s128 *, 0x100) = LimitVectorLength__FP6VECTORfT0(M2C_FIELD(temp_s0_2, s128 *, 0x100), fparg1);
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0x58)) {
            goto loop_10;
        }
    }
    CStackFrame_Destructor(sp, 2);
}
}
