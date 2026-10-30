typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ f32 sp40;                           /* inferred */
    /* 0x044 */ char pad44[0x12C];
};                                                  /* size = 0x170 */
#define sp40 (*(f32 *)(sp + 0x040))
s32 ClsgClipEdgeToObject(s32, M2C_UNK, M2C_UNK, M2C_UNK, s8 *); /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s8 *arg5) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    M2C_UNK temp_s5;
    M2C_UNK temp_s6;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_a0;
    s8 *var_v0_2;
    s8 *var_v1_2;
    var_s1 = 0;
    var_s3 = 0;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg2));
    temp_s5 = vu_1;
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(arg1));
    temp_s6 = vu_2;
    var_f20 = 3.4028235e38f;
    if (arg3 > 0) {
        var_v0 = 0 * 4;
        do {
            temp_s0 = *(s32 *)(var_v0 + arg4);
            s64 vu_3;
            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s5));
            s64 vu_4;
            asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s6));
            temp_v0 = ClsgClipEdgeToObject(temp_s0, vu_4, vu_3, 2, sp);
            var_v1 = 0;
            if ((temp_v0 > 0) && (sp40 == 0.0f)) {
                var_v1 = !(arg0 & 1) ? 0 : 1;
            }
            if (var_v1 < temp_v0) {
                var_v0_2 = (var_v1 * 0x60) + sp;
                temp_f0 = M2C_FIELD(var_v0_2, f32 *, 0x40);
                if (temp_f0 < var_f20) {
                    var_f20 = temp_f0;
                    var_s3 = temp_s0;
                    if (arg5 != NULL) {
                        var_v1_2 = arg5;
                        temp_a0 = var_v0_2 + 0x60;
                        do {
                            M2C_FIELD(var_v1_2, s128 *, 0) = (s128) M2C_FIELD(var_v0_2, s128 *, 0);
                            M2C_FIELD(var_v1_2, s128 *, 0x10) = (s128) M2C_FIELD(var_v0_2, s128 *, 0x10);
                            var_v0_2 += 0x20;
                            var_v1_2 += 0x20;
                        } while (var_v0_2 != temp_a0);
                    }
                }
            }
            var_s1 += 1;
            var_v0 = var_s1 * 4;
        } while (var_s1 < arg3);
    }
    return var_s3;
}
}
