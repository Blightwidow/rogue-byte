typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MoveMurrayAttack {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
s32 SetVectorCylind__FP6VECTORfff(M2C_UNK *, M2C_UNK *, M2C_UNK *, f32, f32, M2C_UNK); /* extern */
s32 bevy_camera_follow_track_heading_weight(M2C_UNK, s8 *, M2C_UNK); /* extern */
M2C_UNK func_002046F0(s8 *, s32);                 /* extern */
s32 func_00204E38(s8 *, f32);                     /* extern */
extern M2C_UNK D_FLT_002C0A20;
extern M2C_UNK g_2bbb60;
void MoveMurrayAttack(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 *temp_s0;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 var_f20;
    s32 temp_a1_2;
    s8 *temp_a1;
    s8 *temp_v0;
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x1030);
    if (temp_a1 != NULL) {
        asm volatile("qmtc2.ni %0, vf3" : : "r"(func_00204E38(temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C))));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
        asm volatile("vmulx.xyzw vf2, vf3, vf1x");
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
        if (M2C_FIELD(arg0, s32 *, 0x1818) != 0) {
            temp_s0 = PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), s32 *, 0x14), 0x240);
            temp_f4 = *temp_s0;
            temp_f0 = (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), f32 *, 0x1C) - temp_f4) / (*PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), s32 *, 0x14), 0x242) - temp_f4);
            temp_f4_2 = M2C_FIELD(&D_FLT_002C0A20, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C0A20, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C0A20, f32 *, 8))));
            if (temp_f4_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 0);
            } else {
                var_f20 = temp_f4_2;
                if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f4_2) {
                    var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                }
            }
            temp_v0 = M2C_FIELD(arg0, s8 **, 0x150);
            asm volatile("lqc2 vf1, 0x1700(%0)" : : "r"(arg0));
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(SetVectorCylind__FP6VECTORfff(&D_FLT_002C0A20, &g_2bbb60, &D_FLT_002C0A20, M2C_FIELD(temp_v0, f32 *, 0x18), M2C_FIELD(temp_v0, f32 *, 0x1C) * vu_1, 0)));
            asm volatile("qmtc2.ni %0, vf1" : : "r"(bevy_camera_follow_track_heading_weight(0, arg0, vu_2)));
            asm volatile("qmtc2.ni %0, vf5" : : "r"(var_f20));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("vmulx.xyzw vf4, vf1, vf2x");
            asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
            asm volatile("qmtc2.ni %0, vf3" : : "r"(1.0f - var_f20));
            asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("vmulax.xyzw ACC, vf1, vf3x");
            asm volatile("vmaddx.xyzw vf1, vf4, vf5x");
            asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
        }
    }
    temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x10DC);
    if (temp_a1_2 != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x10E4) == 4) {
            func_002046F0(arg0, temp_a1_2);
        }
    }
}
}
