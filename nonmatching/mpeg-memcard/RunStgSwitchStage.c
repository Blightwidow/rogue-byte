#include "m2c_macros.h"

M2C_UNK ApplyTaskStateRequests(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK JoltCm(M2C_UNK *, s32);                     /* extern */
M2C_UNK OnDifficultyBreak(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(M2C_UNK *, s32, M2C_UNK); /* extern */
M2C_UNK func_001F6978(void *, s32);                 /* extern */
M2C_UNK func_001F69F8(void *, s32);                 /* extern */
M2C_UNK func_001F6AC8(void *, s32);                 /* extern */
M2C_UNK func_001F6B48(void *, s32);                 /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DE578;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;

void RunStgSwitchStage(void *arg0, void *arg1) {
    char sp[0x400];
    void *sp40;
    M2C_UNK (*var_v1)(void *);
    s16 var_a0;
    s32 var_s3;
    u32 temp_v1;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_2;
    void *var_s1;
    void *var_s5;

    var_s3 = 0;
    var_s5 = NULL;
    if (M2C_FIELD(arg1, s32 *, 8) > 0) {
loop_2:
        temp_s0 = M2C_FIELD(arg1, s32 *, 0xC) + (var_s3 * 8);
        if ((((M2C_FIELD(arg0, s32 *, 0x158) <= 0) && (M2C_FIELD(arg1, s32 *, 4) > 0)) || !((0x3F >> M2C_FIELD(temp_s0, u32 *, 0)) & 1)) && ((var_s1 = NULL, (((0xC3 >> M2C_FIELD(temp_s0, u32 *, 0)) & 1) == 0)) || (var_s1 = PloFindSwObject_thunk(&B_003DD490, 1, M2C_FIELD(temp_s0, s32 *, 4), arg0), (var_s1 != NULL)))) {
            temp_v1 = M2C_FIELD(temp_s0, u32 *, 0);
            switch (temp_v1) {
            case 6:
                var_s5 = var_s1;
                break;
            case 0:
                temp_v0 = M2C_FIELD(var_s1, void **, 0xC);
                var_a0 = M2C_FIELD(temp_v0, s16 *, 0x40);
                var_v1 = M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x44);
block_12:
                var_v1(var_s1 + var_a0);
                break;
            case 1:
                temp_v0_2 = M2C_FIELD(var_s1, void **, 0xC);
                var_a0 = M2C_FIELD(temp_v0_2, s16 *, 0x48);
                var_v1 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x4C);
                goto block_12;
            case 2:
                func_001F6978(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 3:
                func_001F69F8(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 4:
                func_001F6AC8(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 5:
                func_001F6B48(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 7:
                if (FIsBasicDerivedFrom(var_s1, 0x1E) != 0) {
                    temp_v0_3 = M2C_FIELD(var_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *, s32, void *), 0x19C)(var_s1 + M2C_FIELD(temp_v0_3, s16 *, 0x198), sp, 1, (var_s5 != NULL) ? var_s5 : var_s1);
                }
                break;
            case 8:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 2) {
                    JoltCm(&B_002DDF40, M2C_FIELD(temp_s0, s32 *, 4));
                }
                break;
            case 9:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 4) {
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, M2C_FIELD(temp_s0, s32 *, 4), 0x3E99999A);
                }
                break;
            case 10:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 8) {
                    if (var_s5 != NULL) {
                        PosLoWorld(var_s5);
                    } else {
                        PosLoWorld(arg0);
                    }
                    OnDifficultyBreak(&B_002DE578, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), M2C_FIELD(temp_s0, s32 *, 4), -0x64);
                }
                break;
            case 11:
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                sp40 = temp_s0 + 4;
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 4, 0, 1);
                break;
            case 12:
                ApplyTaskStateRequests(&B_002DEB30, 1, M2C_FIELD(temp_s0, s32 *, 4), arg0);
                break;
            }
        }
        var_s3 += 1;
        if (var_s3 < M2C_FIELD(arg1, s32 *, 8)) {
            goto loop_2;
        }
    }
}
