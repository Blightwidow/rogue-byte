#include "m2c_macros.h"

s32 FActiveCplcy(M2C_UNK *);                        /* extern */
s32 FJoyButtonPressed(M2C_UNK *, s32);              /* extern */
s32 GetSmaCur(s32);                                 /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK ShopMenu_SetPage(M2C_UNK *, M2C_UNK, s32);  /* extern */
M2C_UNK StartJsg(s32, M2C_UNK);                     /* extern */
M2C_UNK StepHubState(void *, s32);                  /* extern */
s32 UpdateJoyNavX(M2C_UNK *);                       /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK B_002DE2E0;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_002E0D00;
extern M2C_UNK B_003DA150;
extern M2C_UNK B_003DD490;
extern s32 g_2dfbc0;

void UpdateHub(void *arg0) {
    M2C_UNK *var_s3;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s2;
    void *var_s0;

    UpdateSo();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x180);
    if (temp_v1 != 0) {
        if ((temp_v1 == 1) && (M2C_FIELD(arg0, s32 *, 0x188) != 0) && (FActiveCplcy(&B_002DE2E0) == 0)) {
            if (g_2dfbc0 & 2) {
                var_s3 = &B_002DFC00;
            } else {
                var_s3 = &B_002E0D00;
            }
            temp_v0 = UpdateJoyNavX(var_s3);
            if (temp_v0 == 0) {
                var_s2 = 0;
                var_s0 = arg0 + 0x190;
loop_11:
                if (var_s2 < M2C_FIELD(arg0, s32 *, 0x18C)) {
                    if ((M2C_FIELD(var_s0, s32 *, 0) == GetSmaCur(M2C_FIELD(arg0, s32 *, 0x188))) && (FJoyButtonPressed(var_s3, M2C_FIELD(var_s0, s32 *, 4)) != 0) && (temp_a2 = M2C_FIELD(var_s0, s32 *, 8), (temp_a2 != -1))) {
                        if (temp_a2 == 0x378) {
                            ShopMenu_SetPage(&B_003DA150, 0, temp_a2);
                        } else {
                            temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, temp_a2, arg0);
                            if (temp_v0_2 == 0) {
                                goto block_10;
                            }
                            StartJsg(temp_v0_2, 0);
                        }
                    } else {
block_10:
                        var_s0 += 0xC;
                        var_s2 += 1;
                        goto loop_11;
                    }
                }
            } else {
                StepHubState(arg0, temp_v0);
            }
        }
    }
}
