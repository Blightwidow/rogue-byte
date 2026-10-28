#include "m2c_macros.h"

M2C_UNK AddSuck(void *, f32);                       /* extern */
M2C_UNK CRef_CopyConstruct(s32 *, s32 *);           /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
s32 PsavepathNew(M2C_UNK *, M2C_UNK *, M2C_UNK);    /* extern */
M2C_UNK RefGetSaveValue(s32 *, M2C_UNK *, s32, M2C_UNK *); /* extern */
M2C_UNK RefSetGameSaveValue(s32 *, s32, s32 *, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003E0EA8;
extern s32 B_003E0F9C;
extern M2C_UNK D_002BDC00;

void OnDifficultyEvent(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    s32 sp10;
    s32 sp20;
    s32 sp30;
    f32 sp34;
    s32 sp40;
    s32 sp50;
    M2C_UNK *temp_s0;
    s32 temp_s1;

    switch (arg1) {
    case 3:
        temp_s0 = "suck_history";
        M2C_FIELD(arg0, M2C_UNK **, 0x14) = &D_002BDC00;
        M2C_FIELD(arg0, s32 *, 8) = PsavepathNew(temp_s0, "mission_0", 0);
        M2C_FIELD(arg0, s32 *, 0xC) = PsavepathNew(temp_s0, "mission_1", 0);
        M2C_FIELD(arg0, s32 *, 0x10) = PsavepathNew(temp_s0, "mission_2", 0);
    default:
        break;
    case 34:
        RefGetSaveValue(sp, &B_003E0EA8, M2C_FIELD(arg0, s32 *, 0xC), &B_003D4A60);
        RefSetGameSaveValue(&sp10, M2C_FIELD(arg0, s32 *, 8), sp, &B_003D4A60);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        RefGetSaveValue(sp, &B_003E0EA8, M2C_FIELD(arg0, s32 *, 0x10), &B_003D4A60);
        RefSetGameSaveValue(&sp20, M2C_FIELD(arg0, s32 *, 0xC), sp, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(sp);
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x10);
        sp30 = 0x16;
        sp34 = *M2C_FIELD(arg2, f32 **, 0xA8);
        CRef_CopyConstruct(&sp40, &sp30);
        RefSetGameSaveValue(&sp50, temp_s1, &sp40, &B_003D4A60);
        CRef_Destruct(&sp50);
        CRef_Destruct(&sp40);
        CRef_Destruct(&sp30);
        break;
    case 37:
        if (B_003E0F9C == M2C_FIELD(arg2, s32 *, 0x7C)) {
            if (M2C_FIELD(arg2, s32 *, 0x54) == 2) {
                if (M2C_FIELD(arg2, s32 *, 0x68) == 1) {
                    AddSuck(arg0, M2C_FIELD(M2C_FIELD(arg0, M2C_UNK **, 0x14), f32 *, 0xC));
                }
            }
        }
        break;
    case 16:
    case 29:
        AddSuck(arg0, M2C_FIELD(M2C_FIELD(arg0, M2C_UNK **, 0x14), f32 *, 8));
        break;
    }
}
