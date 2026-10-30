typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct CRef { int tagk; int n; int pad[2]; };
extern "C" {
struct _m2c_stack_CreateSwSavePaths {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0x9C];
};                                                  /* size = 0xC0 */
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
s32 IEpisodeCurrent();
s32 IdCurrentLevel();
s32 NEpisodeBest();
s32 PsavepathNew(...);
s32 RefSetGameSaveValue(CRef *, s32, CRef *, void *);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK);
void func_001D8B20(CRef *, CRef *, void *, M2C_UNK);
extern M2C_UNK B_002DEB30;
extern s32 B_002E1E54;
extern M2C_UNK B_003D4A60;
extern const char *RO_002A39E8[];
extern M2C_UNK RO_002A8A78;
void CreateSwSavePaths(s8 *arg0) {
    s32 sp10;
    s32 sp14;
    s32 sp20;
    const char **var_s0;
    const char *temp_a1;
    M2C_UNK *temp_s0;
    M2C_UNK *temp_v0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_v0_2;
    s32 var_s5;
    s8 *var_s1;
    var_s1 = arg0 + 0x3B7C;
    var_s5 = 8;
    M2C_FIELD(arg0, s32 *, 0x3B1C) = PsavepathNew("", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B24) = PsavepathNew("widCurrent", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B28) = PsavepathNew("episodeCurrent", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B20) = PsavepathNew("loot", "ccoin", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B2C) = PsavepathNew("flags", "lang", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B30) = PsavepathNew("flags", "nMixerMode", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B34) = PsavepathNew("flags", "uMusicVolume", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B38) = PsavepathNew("flags", "uEffectsVolume", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B3C) = PsavepathNew("flags", "fUseHeadset", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B40) = PsavepathNew("flags", "dxScreenCenter", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B44) = PsavepathNew("flags", "dyScreenCenter", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B48) = PsavepathNew("flags", "fNoVibration", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B4C) = PsavepathNew("flags", "fReverseLookAround", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B50) = PsavepathNew("flags", "fReverseAim", NULL);
    M2C_FIELD(arg0, s32 *, 0x3B54) = PsavepathNew("flags", "fAutosaveWarned", NULL);
    var_s0 = RO_002A39E8;
    do {
        var_s5 -= 1;
        M2C_FIELD(var_s1, s32 *, -0x24) = PsavepathNew("episode", *var_s0, "", 0);
        temp_a1 = *var_s0;
        var_s0 += 1;
        M2C_FIELD(var_s1, s32 *, 0) = PsavepathNew("episode", temp_a1, "percent_complete", 0);
        var_s1 += 4;
    } while (var_s5 >= 0);
    {
        CRef a; CRef b; CRef c;
        int path;
        path = *(int *)(arg0 + 0x3B2C);
        a.tagk = 0x15; a.n = B_002E1E54;
        CRef_CopyConstruct(&b, &a);
        RefSetGameSaveValue(&c, path, &b, &B_003D4A60);
        CRef_Destruct(&c);
        CRef_Destruct(&b);
        CRef_Destruct(&a);
        path = *(int *)(arg0 + 0x3B24);
        a.n = IdCurrentLevel(); a.tagk = 0x15;
        CRef_CopyConstruct(&b, &a);
        RefSetGameSaveValue(&c, path, &b, &B_003D4A60);
        CRef_Destruct(&c);
        CRef_Destruct(&b);
        CRef_Destruct(&a);
        path = *(int *)(arg0 + 0x3B28);
        a.n = IEpisodeCurrent(); a.tagk = 0x15;
        CRef_CopyConstruct(&b, &a);
        RefSetGameSaveValue(&c, path, &b, &B_003D4A60);
        CRef_Destruct(&c);
        CRef_Destruct(&b);
        CRef_Destruct(&a);
        int current = IEpisodeCurrent();
        if (NEpisodeBest() < current) {
            b.tagk = 0x15;
            b.n = IEpisodeCurrent();
            func_001D8B20(&a, &b, &RO_002A8A78, 0);
            CRef_Destruct(&a);
            CRef_Destruct(&b);
        }
    }
    bevy_camera_follow_activity(&B_002DEB30, 3, 0);
}
}
