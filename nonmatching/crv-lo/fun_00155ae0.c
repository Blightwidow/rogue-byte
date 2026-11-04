#include "m2c_macros.h"

f32 GRandInRange();                         /* extern */
M2C_UNK GoalFollowCrv_SetCrv(); /* extern */
M2C_UNK Goal_Pop();                           /* extern */
M2C_UNK MeasureCrv();                         /* extern */
s128 PosLoWorld();                      /* extern */
f32 atan2f();                       /* extern */
void *func_00155A68();                        /* extern */
void *func_00205438();               /* extern */
M2C_UNK func_00209818();                 /* extern */
M2C_UNK func_0020AC28(); /* extern */
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void func_00155AE0(void *arg0, s32 arg1) {
    M2C_UNK (*temp_a1)(void *, M2C_UNK);
    f32 temp_f20;
    s128 *temp_s1;
    s128 *temp_s1_2;
    s32 temp_v1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_2;
    void *temp_v1_3;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
    if (arg1 != temp_v1) {
        switch (temp_v1) {                          /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            func_0020AC28(M2C_FIELD(arg0, void **, 0x10), 0, 0, g_2a2dd0);
            break;
        case 3:                                     /* switch 1 */
            temp_v1_2 = M2C_FIELD(arg0, void **, 0x54);
            temp_f20 = g_2dded0;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xF04) = (f32) (temp_f20 + GRandInRange(M2C_FIELD(temp_v1_2, f32 *, 0x60), M2C_FIELD(temp_v1_2, f32 *, 0x64)));
            M2C_FIELD(arg0, void **, 0x54) = NULL;
            break;
        }
        Goal_Pop(arg0 + 0x18);
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(arg0, void **, 0x40) = func_00155A68(arg0);
            temp_v0 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0x9D);
            M2C_FIELD(temp_v0, s32 *, 0x3C) = 0xB;
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10), PosLoWorld(M2C_FIELD(arg0, void **, 0x40)));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            func_00209818(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) + 3.1415927f);
            temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
            M2C_FIELD(arg0, f32 *, 0x3C) = 3.4028235e38f;
            break;
        case 1:                                     /* switch 2 */
            temp_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0x9E);
            temp_v1_3 = M2C_FIELD(temp_v0_3, void **, 0xC);
            M2C_FIELD(temp_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            temp_a1 = M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK), 0x44);
            temp_a1(temp_v0_3 + M2C_FIELD(temp_v1_3, s16 *, 0x40), temp_a1);
            break;
        case 2:                                     /* switch 2 */
            temp_s2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA7);
            temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0x294);
            M2C_FIELD(temp_s0, s32 *, 0xE8) = arg1;
            temp_s1 = M2C_FIELD(temp_s0, s128 **, 0xF4);
            M2C_FIELD(temp_s1, s128 *, 0) = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
            temp_s1_2 = M2C_FIELD(temp_s0, s128 **, 0xF4);
            M2C_FIELD(temp_s1_2, s128 *, 0x10) = PosLoWorld(M2C_FIELD(arg0, void **, 0x40));
            MeasureCrv(temp_s0);
            GoalFollowCrv_SetCrv(temp_s2, temp_s0, 0);
            temp_a1_2 = M2C_FIELD(temp_s2, void **, 0xC);
            M2C_FIELD(temp_s2, s32 *, 0xC0) = 8;
            M2C_FIELD(temp_s2, s32 *, 0x40) = 1;
            M2C_FIELD(temp_s2, s32 *, 0xC8) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            M2C_FIELD(temp_a1_2, M2C_UNK (**)(void *, void *), 0x44)(temp_s2 + M2C_FIELD(temp_a1_2, s16 *, 0x40), temp_a1_2);
            break;
        case 3:                                     /* switch 2 */
            temp_v0_4 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA4);
            temp_a1_3 = M2C_FIELD(temp_v0_4, void **, 0xC);
            M2C_FIELD(temp_v0_4, void **, 0x3C) = (void *) M2C_FIELD(arg0, void **, 0x54);
            M2C_FIELD(temp_v0_4, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            M2C_FIELD(temp_a1_3, M2C_UNK (**)(void *, void *), 0x44)(temp_v0_4 + M2C_FIELD(temp_a1_3, s16 *, 0x40), temp_a1_3);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xF04) = 3.4028235e38f;
            M2C_FIELD(arg0, s32 *, 0x50) = (s32) (M2C_FIELD(arg0, s32 *, 0x50) + 1);
            break;
        }
    }
}
