extern "C" { struct Ref; void CRef_CopyConstruct(Ref *, Ref *); void CRef_Destruct(Ref *); }
struct Ref {
    int tag; int n; int pad[2];
    Ref() {}
    Ref(Ref &other) { CRef_CopyConstruct(this, &other); }
    ~Ref() { CRef_Destruct(this); }
};
#include "sw.h"
extern "C" {
SAVEPATH *PsavepathNew(const char *, ...);
Ref *RefSetGameSaveValue(Ref *, SAVEPATH *, Ref *, void *);
int IdCurrentLevel(void);
int IEpisodeCurrent(void);
int NEpisodeBest(void);
void func_001D8B20(Ref *, Ref *, const char *, int);
void bevy_camera_follow_activity(void *, int, int);
extern char B_002DEB30[];
extern int B_002E1E54;
extern char B_003D4A60[];
extern const char RO_002A8968[], RO_002A8970[], RO_002A8980[], RO_002A8990[], RO_002A8998[], RO_002A89A0[], RO_002A89A8[], RO_002A89B0[], RO_002A89C0[], RO_002A89D0[], RO_002A89E0[], RO_002A89F0[], RO_002A8A00[], RO_002A8A10[], RO_002A8A20[], RO_002A8A38[], RO_002A8A48[], RO_002A8A58[], RO_002A8A60[], RO_002A8A78[];
extern const char *RO_002A39E8[];
static inline void SetSaveInt(SAVEPATH *path, int n)
{
    Ref value; value.tag = 0x15; value.n = n;
    Ref copy(value);
    Ref result;
    RefSetGameSaveValue(&result, path, &copy, B_003D4A60);
}
void CreateSwSavePaths(SW *self)
{
    self->psavepathDt = PsavepathNew(RO_002A8968, 0);
    self->psavepathWidCurrent = PsavepathNew(RO_002A8970, 0);
    self->psavepathEpisodeCurrent = PsavepathNew(RO_002A8980, 0);
    self->psavepathCcoin = PsavepathNew(RO_002A8990, RO_002A8998, 0);
    self->psavepathLang = PsavepathNew(RO_002A89A0, RO_002A89A8, 0);
    self->psavepathMixerMode = PsavepathNew(RO_002A89A0, RO_002A89B0, 0);
    self->psavepathMusicVolume = PsavepathNew(RO_002A89A0, RO_002A89C0, 0);
    self->psavepathEffectsVolume = PsavepathNew(RO_002A89A0, RO_002A89D0, 0);
    self->psavepathUseHeadset = PsavepathNew(RO_002A89A0, RO_002A89E0, 0);
    self->psavepathDxScreenCenter = PsavepathNew(RO_002A89A0, RO_002A89F0, 0);
    self->psavepathDyScreenCenter = PsavepathNew(RO_002A89A0, RO_002A8A00, 0);
    self->psavepathNoVibration = PsavepathNew(RO_002A89A0, RO_002A8A10, 0);
    self->psavepathReverseLookAround = PsavepathNew(RO_002A89A0, RO_002A8A20, 0);
    self->psavepathReverseAim = PsavepathNew(RO_002A89A0, RO_002A8A38, 0);
    self->psavepathAutosaveWarned = PsavepathNew(RO_002A89A0, RO_002A8A48, 0);
    for (int index = 0; index < 9; index++) {
        self->apsavepathEpisodeDt[index] = PsavepathNew(RO_002A8A58, RO_002A39E8[index], RO_002A8968, 0);
        self->apsavepathEpisodePercent[index] = PsavepathNew(RO_002A8A58, RO_002A39E8[index], RO_002A8A60, 0);
    }
    SetSaveInt(self->psavepathLang, B_002E1E54);
    SetSaveInt(self->psavepathWidCurrent, IdCurrentLevel());
    SetSaveInt(self->psavepathEpisodeCurrent, IEpisodeCurrent());
    int current = IEpisodeCurrent();
    if (NEpisodeBest() < current) {
        Ref result;
        Ref value; value.tag = 0x15; value.n = IEpisodeCurrent();
        func_001D8B20(&result, &value, RO_002A8A78, 0);
    }
    bevy_camera_follow_activity(B_002DEB30, 3, 0);
}
}
