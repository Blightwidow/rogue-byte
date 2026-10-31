#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(); /* extern */
M2C_UNK CRef_Destruct();                       /* extern */
s32 IEpisodeCurrent();                              /* extern */
s32 IdCurrentLevel();                               /* extern */
s32 NEpisodeBest();                                 /* extern */
s32 PsavepathNew(); /* extern */
M2C_UNK RefSetGameSaveValue(); /* extern */
M2C_UNK bevy_camera_follow_activity(); /* extern */
M2C_UNK func_001D8B20(); /* extern */
extern M2C_UNK B_002DEB30;
extern s32 B_002E1E54;
extern M2C_UNK B_003D4A60;
extern M2C_UNK *RO_002A39E8;
extern M2C_UNK RO_002A8968;
extern M2C_UNK RO_002A8A78;

void CreateSwSavePaths(void *arg0) {
    char sp[0x400];
    s32 sp10;
    s32 sp14;
    s32 sp20;
    M2C_UNK **var_s0;
    M2C_UNK *temp_a1;
    M2C_UNK *temp_s0;
    M2C_UNK *temp_v0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_v0_2;
    s32 var_s5;
    void *var_s1;

    var_s1 = arg0 + 0x3B7C;
    var_s5 = 8;
    M2C_FIELD(arg0, s32 *, 0x3B1C) = PsavepathNew(&RO_002A8968, NULL);
    M2C_FIELD(arg0, s32 *, 0x3B24) = PsavepathNew("widCurrent", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B28) = PsavepathNew("episodeCurrent", NULL);
    temp_s0 = "flags";
    M2C_FIELD(arg0, s32 *, 0x3B20) = PsavepathNew("loot", "ccoin", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B2C) = PsavepathNew(temp_s0, "lang", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B30) = PsavepathNew(temp_s0, "nMixerMode", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B34) = PsavepathNew(temp_s0, "uMusicVolume", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B38) = PsavepathNew(temp_s0, "uEffectsVolume", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B3C) = PsavepathNew(temp_s0, "fUseHeadset", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B40) = PsavepathNew(temp_s0, "dxScreenCenter", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B44) = PsavepathNew(temp_s0, "dyScreenCenter", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B48) = PsavepathNew(temp_s0, "fNoVibration", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B4C) = PsavepathNew(temp_s0, "fReverseLookAround", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B50) = PsavepathNew(temp_s0, "fReverseAim", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B54) = PsavepathNew(temp_s0, "fAutosaveWarned", NULL);
    temp_v0 = "episode";
    var_s0 = &RO_002A39E8;
    do {
        var_s5 -= 1;
        M2C_FIELD(var_s1, s32 *, -0x24) = PsavepathNew(temp_v0, *var_s0, &RO_002A8968, 0);
        temp_a1 = *var_s0;
        var_s0 += 4;
        M2C_FIELD(var_s1, s32 *, 0) = PsavepathNew(temp_v0, temp_a1, "percent_complete", 0);
        var_s1 += 4;
    } while (var_s5 >= 0);
    temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x3B2C);
    CRef_CopyConstruct(&sp10, sp, 0x15, B_002E1E54);
    RefSetGameSaveValue(&sp20, temp_s0_2, &sp10, &B_003D4A60);
    CRef_Destruct(&sp20);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
    temp_s0_3 = M2C_FIELD(arg0, s32 *, 0x3B24);
    CRef_CopyConstruct(&sp10, sp, 0x15, IdCurrentLevel());
    RefSetGameSaveValue(&sp20, temp_s0_3, &sp10, &B_003D4A60);
    CRef_Destruct(&sp20);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
    temp_s0_4 = M2C_FIELD(arg0, s32 *, 0x3B28);
    CRef_CopyConstruct(&sp10, sp, 0x15, IEpisodeCurrent());
    RefSetGameSaveValue(&sp20, temp_s0_4, &sp10, &B_003D4A60);
    CRef_Destruct(&sp20);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
    temp_s0_5 = IEpisodeCurrent();
    if (NEpisodeBest() < temp_s0_5) {
        temp_v0_2 = IEpisodeCurrent();
        sp10 = 0x15;
        sp14 = temp_v0_2;
        func_001D8B20(sp, &sp10, &RO_002A8A78, 0);
        CRef_Destruct(sp);
        CRef_Destruct(&sp10);
    }
    bevy_camera_follow_activity(&B_002DEB30, 3, 0);
}
