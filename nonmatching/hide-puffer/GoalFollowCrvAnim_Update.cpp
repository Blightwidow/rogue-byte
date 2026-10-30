typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalFollowCrvAnim_Update {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x50];
};                                                  /* size = 0x70 */
void GoalFollowCrv_Update();
s32 PmatLoWorld(s32, f32);
s32 PosLoWorld(s32);
f32 SetAsegaSpeed(s8 *, f32);
void SetDirAnimDirection(s8 *, M2C_UNK);
f32 atan2f(M2C_UNK, M2C_UNK);
void func_00209818(s32, f32);
extern M2C_UNK D_FLT_002BE6A0;
extern f32 D_FLT_002BE6B0;
extern M2C_UNK g_2a2dc0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;
extern f32 g_2be694;
extern f32 g_2dded4;
void GoalFollowCrvAnim_Update(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s128 sp10;
    M2C_UNK temp_v1_2;
    f32 temp_f12;
    f32 temp_v0;
    f32 var_f0;
    f32 var_f20;
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s8 *temp_s0;
    GoalFollowCrv_Update();
    if ((u32) M2C_FIELD(arg0, u32 *, 0x4C) < 2U) {
        sp10 = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(arg0));
        asm volatile("vsub.xyzw vf3, vf3, vf1");
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vmul.xyz vf2, vf3, vf1");
        asm volatile("vaddw.x vf4, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf4, vf2z");
        asm volatile("vmulx.xyzw vf2, vf1, vf2x");
        asm volatile("vsub.xyzw vf4, vf3, vf2");
        asm volatile("vmul.xy vf1, vf4, vf4");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_v0 = vu_1;
        temp_f12 = M2C_FIELD(&D_FLT_002BE6A0, f32 *, 0) + (temp_v0 * (M2C_FIELD(&D_FLT_002BE6A0, f32 *, 4) + (temp_v0 * M2C_FIELD(&D_FLT_002BE6A0, f32 *, 8))));
        if (temp_f12 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f20 = temp_f12;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f12) {
                var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_s0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x18), s8 **, 0x40);
        temp_v1 = M2C_FIELD(temp_s0, s32 *, 0);
        switch (temp_v1) {                          /* irregular */
        case 3:
            asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
            temp_v0_2 = PmatLoWorld(M2C_FIELD(arg0, s32 *, 0x10), temp_f12);
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf2, (%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            asm volatile("vmul.xyzw vf6, vf2, vf4");
            asm volatile("vmaxw.xyzw vf7, vf0, vf0w");
            asm volatile("vmul.xyzw vf5, vf1, vf4");
            asm volatile("vmul.xyzw vf9, vf3, vf4");
            asm volatile("vadday.x ACC, vf6, vf6y");
            asm volatile("vmaddz.x vf8, vf7, vf6z");
            asm volatile("vaddax.y ACC, vf5, vf5x");
            asm volatile("vmaddz.y vf8, vf7, vf5z");
            asm volatile("vaddax.z ACC, vf9, vf9x");
            asm volatile("vmaddy.z vf8, vf7, vf9y");
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(M2C_FIELD(temp_s0, s32 *, 4)));
            asm volatile("vmul.xyz vf2, vf8, vf8");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("vsqrt Q, vf2x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf3, vf0, Q");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(arg0, f32 *, 0xC4) * var_f20 * vu_2));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
            if (vu_3 < 0.0001f) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dd0));
            } else {
                asm volatile("vdiv Q, vf0w, vf3x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf8, Q");
            }
            asm volatile("vmulx.xyzw vf3, vf1, vf2x");
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
            SetDirAnimDirection(M2C_FIELD(temp_s0, s8 **, 8), vu_4);
            SetAsegaSpeed(M2C_FIELD(M2C_FIELD(temp_s0, s8 **, 8), s8 **, 0x24), var_f20);
            break;
        case 0:
            asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
            SetAsegaSpeed(M2C_FIELD(temp_s0, s8 **, 8), M2C_FIELD(arg0, f32 *, 0xC4) * var_f20);
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            s32 vu_5;
            asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_5));
            temp_v1_2 = vu_5;
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0;
            s64 vu_6;
            asm volatile("prot3w %0, %0" : "=r"(vu_6) : "r"(temp_v1_2));
            func_00209818(temp_s0_2, atan2f(vu_6, temp_v1_2));
            break;
        }
        asm volatile("lqc2 vf1, 0xd0(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf9, 0x10(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf9, vf1");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        var_v0 = 1;
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_7;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_7));
        if (!(D_FLT_002BE6B0 < vu_7)) {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            var_f0 = g_2be694;
            M2C_FIELD(arg0, s128 *, 0xD0) = sp10;
        } else {
            var_f0 = M2C_FIELD(arg0, f32 *, 0xE0) - g_2dded4;
        }
        M2C_FIELD(arg0, f32 *, 0xE0) = var_f0;
    }
}
}
