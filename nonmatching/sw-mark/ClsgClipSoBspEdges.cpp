typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ClsgClipSoBspEdges {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s32 spC;                             /* inferred */
    /* 0x10 */ char pad10[0xA0];
};                                                  /* size = 0xB0 */
s32 ClsgClipEdgeToBsp(s32, M2C_UNK, s128, s128, s32, s32); /* extern */
s32 ClsgClipSoBspEdges(s8 *arg1, s8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s8 *sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 temp_s4;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    u16 var_v0;
    s8 **var_a1;
    s8 **var_a4;
    s8 **var_v0_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_v1;
    s8 *var_s0;
    var_s1 = 0;
    var_s2 = 0;
    sp4 = arg3;
    var_a0 = arg3 - 1;
    sp0 = arg1;
    spC = M2C_FIELD(arg2, s32 *, 0x9C);
    temp_s4 = M2C_FIELD(arg2, s32 *, 0x94);
    sp8 = arg5;
    if (var_a0 >= 0) {
        var_a1 = (s8 **)((var_a0 * 0xC) + 8 + arg4);
        do {
            temp_v1 = *var_a1;
            var_a0 -= 1;
            var_a1 -= 0xC;
            M2C_FIELD(temp_v1, s32 *, 0x18) = (s32) (M2C_FIELD(temp_v1, s32 *, 0x18) | 1);
        } while (var_a0 >= 0);
    }
    var_a0_2 = sp4 - 1;
    if (var_a0_2 >= 0) {
        do {
            temp_a1 = M2C_FIELD(((var_a0_2 * 0xC) + arg4), s8 **, 8);
            temp_v1_2 = M2C_FIELD(temp_a1, s32 *, 0x18);
            if ((temp_v1_2 & 1) && !(temp_v1_2 & 2)) {
                var_s0 = M2C_FIELD(temp_a1, s8 **, 0x10);
                M2C_FIELD(temp_a1, s32 *, 0x18) = (s32) (temp_v1_2 | 2);
                if (var_s0 != NULL) {
                    var_v0 = M2C_FIELD(var_s0, u16 *, 6);
loop_9:
                    if (!((M2C_FIELD((spC + (var_v0 << 5)), s32 *, 0x18) ^ 1) & 1)) {
                        var_s2 += ClsgClipEdgeToBsp(M2C_FIELD(sp0, s32 *, 0x74), 0x7FFFFFFF, *(s32 *)((M2C_FIELD(var_s0, u16 *, 0) * 0x10) + temp_s4), *(s32 *)((M2C_FIELD(var_s0, u16 *, 2) * 0x10) + temp_s4), sp8 - var_s2, (var_s2 * 0x60) + arg6);
                        if (var_s1 < var_s2) {
                            var_s1_2 = var_s2 - var_s1;
                            var_v0_2 = (s8 **)((var_s1 * 0x60) + 0x54 + arg6);
                            do {
                                *var_v0_2 = var_s0;
                                var_s1_2 -= 1;
                                var_v0_2 += 0x60;
                            } while (var_s1_2 != 0);
                            var_s1 = var_s2;
                        }
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 8);
                    if (var_s0 != NULL) {
                        var_v0 = M2C_FIELD(var_s0, u16 *, 6);
                        goto loop_9;
                    }
                }
            }
            var_a0_2 -= 1;
        } while (var_a0_2 >= 0);
        var_a0_2 = sp4 - 1;
    }
    if (var_a0_2 >= 0) {
        var_a4 = (s8 **)((var_a0_2 * 0xC) + 8 + arg4);
        do {
            temp_a1_2 = *var_a4;
            var_a0_2 -= 1;
            var_a4 -= 0xC;
            M2C_FIELD(temp_a1_2, s32 *, 0x18) = (s32) (M2C_FIELD(temp_a1_2, s32 *, 0x18) & ~3);
        } while (var_a0_2 >= 0);
    }
    return var_s2;
}
}
