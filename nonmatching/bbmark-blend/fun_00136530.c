#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(s32, void *, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CarryThrow_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK ConvertXfMatrix4(s128 *, s32, s32, void *); /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *);         /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP(void *);    /* extern */
f32 RadYawSo(void *);                               /* extern */
M2C_UNK RetractSmaRef(void *);                      /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK SetXfKind(void *, void *, M2C_UNK);         /* extern */
s32 func_0012DC18(void *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0012E460(void *);                      /* extern */
M2C_UNK func_001A58D0(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s128 g_2a2dd0;
extern f32 g_2dded0;
extern void *g_2f7900;

void func_00136530(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp50;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp30;
    s128 sp40;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_v1;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1800);
    if (arg1 != temp_v1) {
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            temp_s0 = M2C_FIELD(arg0, s32 *, 0x9E4);
            func_001A58D0(arg0, 0, 0xF);
            M2C_FIELD(arg0, s32 *, 0x9E4) = temp_s0;
            func_0012E460(arg0 + 0x1810);
            func_0012E460(arg0 + 0x1814);
            SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x58), 2);
            SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x5C), 2);
            break;
        case 1:                                     /* switch 1 */
            SetStepRadTarget(arg0, RadYawSo(arg0));
            M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
            FixStepAngularVelocity__FP4STEP(arg0);
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x1800) = arg1;
        M2C_FIELD(arg0, f32 *, 0x1804) = (f32) g_2dded0;
        temp_s3 = M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x1808);
        switch (arg1) {                             /* switch 2; irregular */
        case -1:                                    /* switch 2 */
            if (M2C_FIELD(g_2f7900, s32 *, 0x13D0) == 0xF) {
                if (M2C_FIELD(g_2f7900, s32 *, 0x1914) != 7) {
                    CarryThrow_SetState(g_2f7900 + 0x1910, 0);
                }
            }
            break;
        case 0:                                     /* switch 2 */
            temp_a2 = M2C_FIELD(g_2f7900, void **, 0x191C);
            temp_v1_2 = M2C_FIELD(temp_a2, void **, 0xC);
            temp_s0_2 = M2C_FIELD(temp_v1_2, s32 (**)(void *, void *, void *), 0x104)(temp_a2 + M2C_FIELD(temp_v1_2, s16 *, 0x100), sp, temp_a2);
            ConvertXfMatrix4(&sp40, M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), s32 *, 0xA0), M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xA0), sp);
            sp30 = sp70;
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            temp_s1 = M2C_FIELD(arg0, s32 *, 0x9E4);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *, s32, M2C_UNK, s128, s128, s128), 0x54)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x50), g_2f7900, temp_s0_2, 3, sp40, sp50, sp60);
            M2C_FIELD(arg0, s32 *, 0x9E4) = temp_s1;
            temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x118), g_2a2dd0);
            temp_v1_4 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x120), g_2a2dd0);
            M2C_FIELD(arg0, s32 *, 0x1810) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x58), 1, 7);
            DecomposeRotateMatrixEuler(sp);
            M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
            M2C_FIELD(arg0, s32 *, 0x1814) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x5C), 1, 7);
        default:                                    /* switch 2 */
block_17:
            RetractSmaRef(arg0 + 0x1034);
            ApplyAsegToHandle(temp_s3, arg0, 9, arg0 + 0x1030, 0, 0x3F800000);
            temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x2D4)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x2D0));
            break;
        case 1:                                     /* switch 2 */
            M2C_FIELD(arg0, s32 *, 0x1A4) = -1;
            goto block_17;
        }
    }
}
