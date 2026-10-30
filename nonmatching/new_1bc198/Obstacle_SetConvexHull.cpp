typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Obstacle_SetConvexHull {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x6C];
};                                                  /* size = 0x80 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK CopyAb__FPvT0Ui(s32, s32, s32);             /* extern */
s32 PvAllocStackImpl__Fi(s32 *, s32 *);             /* extern */
M2C_UNK qsort(s32, M2C_UNK, M2C_UNK *);             /* extern */
extern M2C_UNK func_001BDBC8;
void Obstacle_SetConvexHull(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s32 sp10;
    s128 *temp_a0;
    s128 *temp_a0_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    var_s0 = 2;
    qsort(arg2, 0x10, &func_001BDBC8);
    CStackFrame_Construct(sp);
    sp10 = 0x800;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp10, &sp10);
    CopyAb__FPvT0Ui(temp_v0, arg2, 0x20);
    var_a1 = 2;
    if (arg1 > 2) {
        var_v0 = 2 * 0x10;
        do {
            temp_a0 = (s128 *)((var_s0 * 0x10) + temp_v0);
            var_s0 += 1;
            var_a1 += 1;
            *temp_a0 = *(s32 *)(var_v0 + arg2);
            if (var_s0 >= 3) {
                var_v1 = (var_s0 * 0x10) - 0x20 + temp_v0;
loop_4:
                asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
                asm volatile("lqc2 vf2, -0x10(%0)" : : "r"(var_v1));
                asm volatile("vsub.xyzw vf2, vf1, vf2");
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(var_v1));
                asm volatile("vsub.xyzw vf1, vf3, vf1");
                asm volatile("vopmula.xyz ACC, vf2, vf1");
                asm volatile("vopmsub.xyz vf2, vf1, vf2");
                var_v0_2 = var_a1 < arg1;
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                s64 vu_2;
                asm volatile("pextuw %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(vu_1));
                if (vu_2 < 0.0f) {
                    asm volatile("sqc2 vf3, (%0)" : : "r"(var_v1));
                    var_s0 -= 1;
                    var_v1 -= 0x10;
                    if (var_s0 < 3) {
                        goto block_6;
                    }
                    goto loop_4;
                }
            } else {
block_6:
                var_v0_2 = var_a1 < arg1;
            }
            var_v0 = var_a1 * 0x10;
        } while (var_v0_2 != 0);
    }
    var_a1_2 = arg1 - 3;
    var_s0_2 = var_s0 + 1;
    *(s32 *)((var_s0 * 0x10) + temp_v0) = M2C_FIELD(((arg1 * 0x10) + arg2), s128 *, -0x20);
    if (var_a1_2 >= 0) {
        var_v0_3 = var_a1_2 * 0x10;
        do {
            temp_a0_2 = (s128 *)((var_s0_2 * 0x10) + temp_v0);
            var_s0_2 += 1;
            var_a1_2 -= 1;
            *temp_a0_2 = *(s32 *)(var_v0_3 + arg2);
            if (var_s0 < var_s0_2) {
                var_v1_2 = (var_s0_2 * 0x10) - 0x20 + temp_v0;
loop_12:
                asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1_2));
                asm volatile("lqc2 vf2, -0x10(%0)" : : "r"(var_v1_2));
                asm volatile("vsub.xyzw vf2, vf1, vf2");
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(var_v1_2));
                asm volatile("vsub.xyzw vf1, vf3, vf1");
                asm volatile("vopmula.xyz ACC, vf2, vf1");
                asm volatile("vopmsub.xyz vf2, vf1, vf2");
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                s64 vu_4;
                asm volatile("pextuw %0, %1, %0" : "=r"(vu_4) : "r"(0), "r"(vu_3));
                if (vu_4 < 0.0f) {
                    asm volatile("sqc2 vf3, (%0)" : : "r"(var_v1_2));
                    var_s0_2 -= 1;
                    var_v1_2 -= 0x10;
                    if (var_s0 < var_s0_2) {
                        goto loop_12;
                    }
                }
            }
            var_v0_3 = var_a1_2 * 0x10;
        } while (var_a1_2 >= 0);
    }
    temp_v1 = (var_s0_2 <= 0x1F) ? var_s0_2 : 0x20;
    M2C_FIELD(arg0, s32 *, 0xE8) = temp_v1;
    CopyAb__FPvT0Ui(M2C_FIELD(arg0, s32 *, 0xF4), temp_v0, temp_v1 * 0x10);
    CStackFrame_Destructor(sp, 2);
}
}
