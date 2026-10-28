#include "m2c_macros.h"

M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK DeliverJtLoot(s32);                         /* extern */
s32 IsmsFindSmOptional__FP2SM3OID(s32, s32);        /* extern */
s32 OidFromSmIsms(s32, M2C_UNK);                    /* extern */
M2C_UNK StepHubState(void *, M2C_UNK);              /* extern */
M2C_UNK bevy_jobs_162e38(void *);                   /* extern */
M2C_UNK bevy_player_p18_gadget_refill(s32, M2C_UNK); /* extern */
M2C_UNK func_00187E78(M2C_UNK *);                   /* extern */
M2C_UNK func_001D8A38(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_001F1448(s32, void *, s32, M2C_UNK);   /* extern */
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_002E0D00;
extern M2C_UNK B_003DD490;
extern s32 g_2dfbc0;

void SetHubState(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp114;
    void *sp10;
    void *sp90;
    M2C_UNK sp110;
    M2C_UNK *var_a0;
    s32 *var_s1;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s2;
    s32 var_v0;
    void **var_s1_2;
    void **var_s1_3;
    void *temp_a1;
    void *temp_v0_2;
    void *temp_v0_5;
    void *temp_v0_7;
    void *temp_v0_8;
    void *var_a2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x180);
    if (temp_v0 != arg1) {
        if (temp_v0 == 1) {
            func_001F1448(0, arg0, -1, 0);
            temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 6, 0, 0);
        }
        M2C_FIELD(arg0, s32 *, 0x180) = arg1;
        if (arg1 == 1) {
            if ((M2C_FIELD(&B_003DD490, void **, 0x3B0C) != NULL) && (M2C_FIELD(M2C_FIELD(&B_003DD490, void **, 0x3B0C), s32 *, 0x74) == 0)) {
                bevy_jobs_162e38(M2C_FIELD(&B_003DD490, void **, 0x3B0C));
            }
            temp_v0_3 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0);
            if (temp_v0_3 > 0) {
                var_s2 = temp_v0_3;
                var_s1 = sp;
                var_s0 = *sp;
loop_9:
                var_s2 -= 1;
                var_s1 += 4;
                DeliverJtLoot(var_s0);
                bevy_player_p18_gadget_refill(var_s0, 1);
                if (var_s2 != 0) {
                    var_s0 = *var_s1;
                    goto loop_9;
                }
            }
            temp_v0_4 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x64, 0);
            if (temp_v0_4 > 0) {
                var_s1_2 = &sp10;
                var_s0_2 = temp_v0_4;
                var_a2 = *var_s1_2;
loop_14:
                var_s1_2 += 4;
                var_s0_2 -= 1;
                temp_v0_5 = M2C_FIELD(var_a2, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(var_a2 + M2C_FIELD(temp_v0_5, s16 *, 0x260), 4, var_a2);
                if (var_s0_2 != 0) {
                    var_a2 = *var_s1_2;
                    goto loop_14;
                }
            }
            temp_v0_6 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x4F, 0);
            if (temp_v0_6 > 0) {
                var_s1_3 = &sp90;
                var_s0_3 = temp_v0_6;
                do {
                    temp_a1 = *var_s1_3;
                    var_s0_3 -= 1;
                    var_s1_3 += 4;
                    temp_v0_7 = M2C_FIELD(temp_a1, void **, 0xC);
                    M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_7, s16 *, 0x48), temp_a1);
                } while (var_s0_3 != 0);
            }
            if (M2C_FIELD(arg0, s32 *, 0x184) != 0) {
                func_001D8A38(&sp110, "oidPoCurrent", 0);
                CRef_Destruct(&sp110);
                var_v0 = sp114;
                if (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x184), sp114) == -1) {
                    var_v0 = OidFromSmIsms(M2C_FIELD(arg0, s32 *, 0x184), 0);
                }
            } else {
                var_v0 = -1;
            }
            func_001F1448(M2C_FIELD(arg0, s32 *, 0x184), arg0, var_v0, 0);
            StepHubState(arg0, 0);
            if (g_2dfbc0 & 2) {
                var_a0 = &B_002DFC00;
            } else {
                var_a0 = &B_002E0D00;
            }
            func_00187E78(var_a0);
            temp_v0_8 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_8, s16 *, 0x18), 5, 0, 0);
        }
    }
}
