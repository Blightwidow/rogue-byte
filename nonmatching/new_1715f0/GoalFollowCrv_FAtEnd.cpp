typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalFollowCrv_FAtEnd {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 PosLoWorld(s32);                                /* extern */
s32 GoalFollowCrv_FAtEnd(s8 *arg0) {
    s32 var_v0;
    s32 var_v1;
    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10))));
        asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(arg0));
        var_v1 = 1;
        asm volatile("vsub.xyzw vf1, vf3, vf2");
        asm volatile("vmul.xy vf1, vf1, vf1");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        f32 distance;
        s32 scratch;
        asm volatile("qmfc2.ni %1, vf1\n\tmtc1 %1, %0" : "=f"(distance), "=r"(scratch));
        if (distance <= M2C_FIELD(arg0, f32 *, 0x64)) {
        } else {
            var_v1 = 0;
        }
        var_v0 = var_v1;
    }
    return var_v0;
}
}
