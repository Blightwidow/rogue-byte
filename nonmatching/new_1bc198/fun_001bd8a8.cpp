typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BD8A8 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0xB0];
};                                                  /* size = 0xF0 */
s32 ClsgClipEdgeToObstacle(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
s32 FObstacleContainsPos(s8 *, M2C_UNK);          /* extern */
s32 func_001BD8A8(s8 *arg0, s8 *arg1) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    M2C_UNK sp40;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s8 *temp_v1;
    s8 *temp_v1_2;
    var_s1 = 1;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0xF4)));
    asm volatile("vmulax.xyz ACC, vf5, vf1x");
    asm volatile("vmadday.xyz ACC, vf4, vf1y");
    asm volatile("vmaddaz.xyz ACC, vf3, vf1z");
    asm volatile("vmaddw.xyz vf1, vf2, vf0w");
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
loop_1:
        asm volatile("lqc2 vf5, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, (%0)" : : "r"((var_s1 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4)));
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf5, vf3x");
        asm volatile("vmadday.xyz ACC, vf4, vf3y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
        asm volatile("vmaddw.xyz vf1, vf1, vf0w");
        asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
        if (ClsgClipEdgeToObstacle(arg1, vu_2, vu_1, 1, &sp40) == 0) {
            var_s1 += 1;
            if (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8)) {
                goto loop_1;
            }
        }
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8)) {
            return 1;
        }
        goto block_6;
    }
block_6:
    temp_v1_2 = M2C_FIELD(arg1, s8 **, 0xC);
    temp_v0_2 = M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0xFC)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0xF8));
    asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf4, (%0)" : : "r"(M2C_FIELD(arg1, s32 *, 0xF4)));
    asm volatile("lqc2 vf3, (%0)" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0_2));
    asm volatile("vmulax.xyz ACC, vf3, vf4x");
    asm volatile("vmadday.xyz ACC, vf2, vf4y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf4z");
    asm volatile("vmaddw.xyz vf6, vf5, vf0w");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_3));
    return FObstacleContainsPos(arg0, vu_3) != 0;
}
}
