#include "m2c_macros.h"

M2C_UNK ClearGuardPathMode(void *);                 /* extern */
s32 FFindSurfaceAlongUp(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK Goal_Pop(s32);                              /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK func_0017D608(void *);                      /* extern */
s128 func_001C1EC0(s32, M2C_UNK);                   /* extern */
void *func_00205438(void *, M2C_UNK);               /* extern */
extern s128 g_2a2dd0;

void func_0017E9B0(void *arg0) {
    char sp[0x400];
    s128 sp0;
    void *temp_a0;
    void *temp_a1;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    Goal_Pop(arg0 + 0x18);
    PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    sp0 = func_001C1EC0(arg0 + 0x30, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    if (FFindSurfaceAlongUp(sp, 1, 0, 0x43160000, 0xC37A0000) == 0) {
        func_0017D608(sp);
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_a0, s32 *, 0xFE8) & 1) {
        temp_v0 = func_00205438(temp_a0, 0xAC);
        temp_a1 = M2C_FIELD(temp_v0, void **, 0xC);
        M2C_FIELD(temp_v0, s128 *, 0x50) = sp0;
        M2C_FIELD(temp_v0, s32 *, 0x68) = 1;
        M2C_FIELD(temp_a1, M2C_UNK (**)(void *, void *), 0x44)(temp_v0 + M2C_FIELD(temp_a1, s16 *, 0x40), temp_a1);
        return;
    }
    ClearGuardPathMode(temp_a0);
    temp_a2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($a2) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0xEC)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0xE8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), temp_a2);
    temp_a2_2 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0_3 = M2C_FIELD(temp_a2_2, void **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x118), g_2a2dd0, temp_a2_2);
    temp_a2_3 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0_4 = M2C_FIELD(temp_a2_3, void **, 0xC);
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s128, void *), 0x124)(temp_a2_3 + M2C_FIELD(temp_v0_4, s16 *, 0x120), g_2a2dd0, temp_a2_3);
}
