#include "m2c_macros.h"

M2C_UNK GoalFollowCrv_SetCrv(void *, void *, M2C_UNK); /* extern */
M2C_UNK Goal_Pop(void *);                           /* extern */
M2C_UNK MeasureCrv(void *);                         /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK func_0017E628(void *);                      /* extern */
M2C_UNK func_001C1EC0(void *, s128);                /* extern */
void *func_00205438(void *, M2C_UNK);               /* extern */
extern f32 g_2dded0;

void func_0017E6B0(void *arg0, s32 arg1) {
    s128 sp0;
    s32 temp_v1;
    void *temp_a1;
    void *temp_a2;
    void *temp_s0;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1_2;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x38)) {
        Goal_Pop(arg0 + 0x18);
        M2C_FIELD(arg0, s32 *, 0x38) = arg1;
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            temp_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x120);
            switch (temp_v1) {                      /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                temp_v1_2 = M2C_FIELD(arg0, void **, 0x10);
                temp_s1 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA7);
                temp_s0 = M2C_FIELD(temp_v1_2, void **, 0x294);
                sp0 = PosLoWorld(temp_v1_2);
                func_001C1EC0(M2C_FIELD(arg0, void **, 0x30) + ((M2C_FIELD(arg0, s32 *, 0x34) << 5) + 0x60), sp0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                M2C_FIELD(arg0, f32 *, 0x40) = (f32) (g_2dded0 + M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f2 */));
                M2C_FIELD(temp_s0, s32 *, 0xE8) = 2;
                *M2C_FIELD(temp_s0, s128 **, 0xF4) = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($v1) */);
                MeasureCrv(temp_s0);
                M2C_FIELD(temp_s1, s32 *, 0x40) = 1;
                M2C_FIELD(temp_s1, f32 *, 0x64) = 10.0f;
                GoalFollowCrv_SetCrv(temp_s1, temp_s0, 0);
                temp_v0 = M2C_FIELD(temp_s1, void **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x44)(temp_s1 + M2C_FIELD(temp_v0, s16 *, 0x40));
                break;
            case 1:                                 /* switch 2 */
                func_0017E628(arg0);
                break;
            }
            break;
        case 1:                                     /* switch 1 */
            temp_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xBF);
            temp_a2 = M2C_FIELD(temp_v0_2, void **, 0xC);
            temp_a1 = (M2C_FIELD(arg0, s32 *, 0x34) << 5) + M2C_FIELD(arg0, void **, 0x30);
            M2C_FIELD(temp_v0_2, s128 *, 0x30) = (s128) M2C_FIELD(temp_a1, s128 *, 0x60);
            M2C_FIELD(temp_v0_2, s128 *, 0x40) = (s128) M2C_FIELD(temp_a1, s128 *, 0x70);
            M2C_FIELD(temp_a2, M2C_UNK (**)(void *, void *, void *), 0x44)(temp_v0_2 + M2C_FIELD(temp_a2, s16 *, 0x40), temp_a1, temp_a2);
            break;
        }
    }
}
