typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateDysh {
    /* 0x00 */ char pad0[0xE0];
};                                                  /* size = 0xE0 */
M2C_UNK CpdprizeAttractSwDprizes(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *); /* extern */
s8 *PmatLoWorld(s8 *);                          /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK UpdateGadgetObj();                          /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *); /* extern */
M2C_UNK func_0012D108(s32, M2C_UNK);                /* extern */
M2C_UNK func_0017A8C8(s8 *, M2C_UNK);             /* extern */
s32 func_0017A9C0(s8 *);                          /* extern */
s8 *func_00205458(s8 *, M2C_UNK);               /* extern */
M2C_UNK func_00209840(s8 *, s8 *, s128, s128, s128); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002C43B0;
extern M2C_UNK D_FLT_002C43C0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;
void UpdateDysh(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK temp_v0_3;
    M2C_UNK var_a1;
    f32 temp_f0;
    f32 var_f4;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1;
    s8 *var_a0;
    s8 *var_a0_2;
    UpdateGadgetObj();
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x150) == 5) {
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x1B4);
        var_a1 = 3;
        if (temp_a0 == NULL) {
            goto block_9;
        }
        temp_v0 = func_00205458(temp_a0, 0xB0);
        if (temp_v0 != NULL) {
            if (func_0017A9C0(temp_v0) == 0) {
                var_a0 = M2C_FIELD(arg0, s8 **, 0x1B0);
                if (var_a0 == NULL) {
                    var_a0 = arg0;
                }
                temp_v0_2 = PmatLoWorld(var_a0);
                func_00209840(M2C_FIELD(arg0, s8 **, 0x1B4) + 0xFD0, sp, M2C_FIELD(temp_v0_2, s128 *, 0), M2C_FIELD(temp_v0_2, s128 *, 0x10), M2C_FIELD(temp_v0_2, s128 *, 0x20));
                if (M2C_FIELD(temp_v0, s32 *, 0x30) != 4) {
                    var_a0_2 = M2C_FIELD(arg0, s8 **, 0x1B0);
                    if (var_a0_2 == NULL) {
                        var_a0_2 = arg0;
                    }
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(var_a0_2)));
                    asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1B4))));
                    asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                    if (vu_1 < 100.0f) {
                        func_0017A8C8(temp_v0, 4);
                    }
                }
                temp_v1 = M2C_FIELD(arg0, s8 **, 0x1B4);
                if (M2C_FIELD(temp_v1, s32 *, 0xFC4) != 0) {
                    temp_f0 = (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154)) / D_FLT_002C43B0;
                    var_f4 = M2C_FIELD(&D_FLT_002C43C0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C43C0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C43C0, f32 *, 8))));
                    if (var_f4 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                        var_f4 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                    } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < var_f4) {
                        var_f4 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                    }
                    s64 vu_2;
                    asm volatile("pextlw %0, %0, %0" : "=r"(vu_2) : "r"(var_f4), "r"(var_f4));
                    temp_v0_3 = vu_2;
                    s64 vu_3;
                    asm volatile("pextlw %0, %1, %1" : "=r"(vu_3) : "r"(temp_v0_3), "r"(temp_v0_3));
                    func_0012D108(M2C_FIELD(temp_v1, s32 *, 0xFC4), vu_3);
                }
                if (D_FLT_002C43B0 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154))) {
                    s64 vu_4;
                    asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1B0))));
                    CpdprizeAttractSwDprizes(&B_003DD490, 0x5D, vu_4, arg0);
                    temp_a1 = M2C_FIELD(arg0, s8 **, 0x1B4);
                    temp_v0_4 = M2C_FIELD(temp_a1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_4, s16 *, 0x48), temp_a1);
                    bevy_camera_follow_activity(&B_002DEB30, 0x18, M2C_FIELD(arg0, s8 **, 0x1B4));
                    temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x260), 3);
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            var_a1 = 2;
block_9:
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), M2C_UNK (**)(s8 *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), s16 *, 0x260), var_a1);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x150) != M2C_FIELD(arg0, s32 *, 0x150)) {
        goto loop_1;
    }
}
}
