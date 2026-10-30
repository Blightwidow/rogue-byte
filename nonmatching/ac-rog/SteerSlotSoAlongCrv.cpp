typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SteerSlotSoAlongCrv {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x80];
};                                                  /* size = 0x90 */
M2C_UNK EvaluateCrvFromU(s32, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK FindCrvClosestPointFromU(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, f32, s128); /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
M2C_UNK SetSlotSoState(s8 *, M2C_UNK);            /* extern */
f32 UMaxCrv(s32);                                   /* extern */
f32 UMinCrv(s32);                                   /* extern */
f32 UWrapCrv(s32, f32);                             /* extern */
extern s128 g_2a2da0;
void SteerSlotSoAlongCrv(s8 *arg0) {
    f32 saved_reg_f21;
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 temp_f20;
    f32 var_f21;
    s128 temp_v0;
    s32 temp_v1;
    s32 var_s0;
    s8 *temp_v1_2;
    var_f21 = saved_reg_f21;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x220);
    if (temp_v1 != 1) {
        var_s0 = 0;
        if (temp_v1 != 4) {
        } else {
            var_s0 = M2C_FIELD(arg0, s32 *, 0x170);
            var_f21 = M2C_FIELD(arg0, f32 *, 0x1D0);
        }
    } else {
        var_s0 = M2C_FIELD(arg0, s32 *, 0x16C);
        var_f21 = M2C_FIELD(arg0, f32 *, 0x1CC);
    }
    if (var_s0 != 0) {
        temp_v0 = PosLoWorld(arg0);
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
        FindCrvClosestPointFromU(var_s0, vu_1, 0, 0, 0, arg0 + 0x174, 0, M2C_FIELD(arg0, f32 *, 0x174), temp_v0);
        temp_f20 = UWrapCrv(var_s0, M2C_FIELD(arg0, f32 *, 0x174) + M2C_FIELD(arg0, f32 *, 0x178));
        if (!(temp_f20 < UMinCrv(var_s0))) {
            if (!(UMaxCrv(var_s0) < temp_f20)) {
                EvaluateCrvFromU(var_s0, &sp10, 0, temp_f20);
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf4, vf2, vf1");
                asm volatile("vmove.xyzw vf1, vf4");
                asm volatile("vmul.xyz vf2, vf1, vf1");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf2, vf2y");
                asm volatile("vmaddz.x vf2, vf3, vf2z");
                asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                asm volatile("vsqrt Q, vf2x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2a2da0));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                if (!(vu_2 < 0.0001f)) {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf2, vf4, Q");
                }
                asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f21));
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), vu_3);
            } else {
                goto block_10;
            }
        } else {
block_10:
            if (M2C_FIELD(arg0, s32 *, 0x220) == 1) {
                SetSlotSoState(arg0, 2);
            }
        }
    }
}
}
