typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00155D90 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 FGoalAnimDone(s32);                             /* extern */
s32 FGoalReactDone(s32);                            /* extern */
s32 GoalFollowCrv_FAtEnd(s32);                      /* extern */
s32 PosLoWorld(s32);                                /* extern */
s32 PsenseFindNotice(s8 *, s32, M2C_UNK);         /* extern */
s32 func_00155A68(s8 *);                          /* extern */
M2C_UNK func_00155AE0(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
extern s128 g_2a2dd0;
extern f32 g_2dded0;
void func_00155D90(s8 *arg0) {
    M2C_UNK var_a1;
    s16 temp_a2;
    s32 temp_s2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s8 *temp_a0;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    func_001EEF98();
loop_22:
    if (func_001EF0A8(arg0) == 0) {
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x30);
        switch (temp_s2) {                          /* irregular */
        case 0:
            if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                temp_a0 = M2C_FIELD(arg0, s8 **, 0x10);
                asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg0, s32 *, 0x40))));
                temp_v1 = M2C_FIELD(temp_a0, s8 **, 0xC);
                asm volatile("lqc2 vf1, 0x240(%0)" : : "r"(temp_a0));
                temp_a2 = M2C_FIELD(temp_v1, s16 *, 0xE8);
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, s16), 0xEC)(temp_a0 + temp_a2, vu_1, temp_a2);
                temp_a2_2 = M2C_FIELD(arg0, s8 **, 0x10);
                temp_v0 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s128, s8 *), 0x11C)(temp_a2_2 + M2C_FIELD(temp_v0, s16 *, 0x118), g_2a2dd0, temp_a2_2);
                temp_a2_3 = M2C_FIELD(arg0, s8 **, 0x10);
                temp_v0_2 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s128, s8 *), 0x124)(temp_a2_3 + M2C_FIELD(temp_v0_2, s16 *, 0x120), g_2a2dd0, temp_a2_3);
                M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
                func_00155AE0(arg0, 1);
            }
            break;
        case 2:
            if (GoalFollowCrv_FAtEnd(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                func_00155AE0(arg0, 1);
            }
            break;
        case 1:
            if (((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x48)) > 2.5f) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f)) {
                temp_v0_3 = PsenseFindNotice(M2C_FIELD(arg0, s8 **, 0x10), M2C_FIELD(arg0, s32 *, 0x4C), 0);
                M2C_FIELD(arg0, s32 *, 0x54) = temp_v0_3;
                if (temp_v0_3 != 0) {
                    func_00155AE0(arg0, 3);
                }
            }
            break;
        case 3:
            M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2dded0;
            if (FGoalReactDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                temp_v0_4 = func_00155A68(arg0);
                var_a1 = 1;
                if (temp_v0_4 != M2C_FIELD(arg0, s32 *, 0x40)) {
                    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0_4;
                    var_a1 = 2;
                }
                func_00155AE0(arg0, var_a1);
            }
            break;
        }
        if (temp_s2 != M2C_FIELD(arg0, s32 *, 0x30)) {
            goto loop_22;
        }
    }
}
}
