typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ProbeReconTargetVisibility {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x40];                    /* maybe part of sp10[5]? */
    /* 0x60 */ s32 sp60;                            /* inferred */
    /* 0x64 */ s32 sp64;                            /* inferred */
    /* 0x68 */ char pad68[0x88];
};                                                  /* size = 0xF0 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32, s32, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, s128, M2C_UNK *, M2C_UNK, s32 *, s32 *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK func_00202350;
extern M2C_UNK g_2ddfa0;
void ProbeReconTargetVisibility(s8 *arg0, s8 *arg1) {
    s8 sp[0x60] __attribute__((aligned(16)));
    s128 sp10;
    s32 sp60;
    s32 sp64;
    f32 temp_f20;
    s128 *var_s0;
    s128 temp_a2;
    s32 var_s1;
    s32 var_v0;
    u32 var_s4;
    var_s1 = 0;
    var_s4 = 0;
    CStackFrame_Construct(sp);
    asm volatile("qmtc2.ni %0, vf6" : : "r"(PosLoWorld(arg1)));
    temp_f20 = M2C_FIELD(arg1, f32 *, 0xE4);
    asm volatile("sqc2 vf6, 0x70(%0)" : : "r"(sp));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_1));
    bevy_camera_follow_push_out(&B_003DD490, vu_1, M2C_FIELD(arg0, s128 *, 0x20), &func_00202350, 0, &sp60, &sp64);
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf6, 0x70(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf1, vf6");
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(&g_2ddfa0));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_f20));
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf1, Q");
    asm volatile("sqc2 vf5, 0x50(%0)" : : "r"(sp));
    asm volatile("vopmula.xyz ACC, vf4, vf2");
    asm volatile("vopmsub.xyz vf3, vf2, vf4");
    var_s0 = &sp10;
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf7, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf7, vf1z");
    asm volatile("vmulx.xyzw vf2, vf2, vf5x");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("vadd.xyzw vf6, vf6, vf2");
    asm volatile("vmulx.xyzw vf4, vf4, vf5x");
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf1, vf3, Q");
    asm volatile("vsub.xyzw vf2, vf6, vf4");
    asm volatile("vmulx.xyzw vf1, vf1, vf5x");
    asm volatile("vadd.xyzw vf1, vf6, vf1");
    asm volatile("vadd.xyzw vf4, vf6, vf4");
    asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf6, 0x10(%0)" : : "r"(sp));
    do {
        temp_a2 = *var_s0;
        var_s4 += 1;
        var_s0 += 0x10;
        var_s1 = (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, M2C_FIELD(arg0, s128 *, 0x20), temp_a2, sp60, sp64, 0) != 0) ? (var_s1 + 1) : var_s1;
    } while (var_s4 < 4U);
    if (var_s1 < 4) {
        var_v0 = 3;
        if (var_s1 <= 0) {
            if (var_s1 != 0) {
            } else {
                var_v0 = 1;
                goto block_10;
            }
        } else {
            goto block_10;
        }
    } else if (var_s1 != 4) {
    } else {
        var_v0 = 2;
block_10:
        M2C_FIELD(arg1, s32 *, 0x108) = var_v0;
    }
    CStackFrame_Destructor(sp, 2);
}
}
