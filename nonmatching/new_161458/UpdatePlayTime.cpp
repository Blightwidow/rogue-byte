struct CRef { int tagk; float g; int pad[2]; };
struct Sw { char pad[0x3B0C]; struct Job *pjob; char pad3B10[0x3B1C - 0x3B10]; void *pathPlayTime; char pad3B20[0x3B58 - 0x3B20]; void *pathEpisode[9]; };
struct Job { char pad[0x9C]; float tRampStart; float rampEnd; float tJob; };
struct Clock { float a; float dt; };
extern "C" {
extern Sw B_003DD490;
extern int B_003D4A60[];
extern char B_002DE578[];
extern int B_FLT_002E0C20;
extern Clock g_2dded0;
void RefGetGameSaveValue(CRef *, void *, int *);
void RefSetGameSaveValue(CRef *, void *, CRef *, int *);
void CRef_Destruct(CRef *);
void CRef_CopyConstruct(CRef *, CRef *);
unsigned IEpisodeCurrent(void);
void AddSuck(void *, float);
}
extern "C" void UpdatePlayTime(void)
{
    if (B_003DD490.pathPlayTime == 0)
        return;
    struct { CRef a, b, c, d; } r;
    RefGetGameSaveValue(&r.a, B_003DD490.pathPlayTime, B_003D4A60);
    float playTime = r.a.g;
    CRef_Destruct(&r.a);
    r.b.tagk = 0x16;
    r.b.g = playTime + g_2dded0.dt;
    CRef_CopyConstruct(&r.c, &r.b);
    RefSetGameSaveValue(&r.d, B_003DD490.pathPlayTime, &r.c, B_003D4A60);
    CRef_Destruct(&r.d);
    CRef_Destruct(&r.c);
    CRef_Destruct(&r.b);
    unsigned episode = IEpisodeCurrent();
    if (episode < 9) {
        void *path = B_003DD490.pathEpisode[episode];
        if (path != 0) {
            RefGetGameSaveValue(&r.a, path, B_003D4A60);
            float episodeTime = r.a.g;
            CRef_Destruct(&r.a);
            r.a.tagk = 0x16;
            r.a.g = episodeTime + g_2dded0.dt;
            CRef_CopyConstruct(&r.b, &r.a);
            RefSetGameSaveValue(&r.c, path, &r.b, B_003D4A60);
            CRef_Destruct(&r.c);
            CRef_Destruct(&r.b);
            CRef_Destruct(&r.a);
        }
    }
    Job *pjob = B_003DD490.pjob;
    if (pjob != 0 && (float)B_FLT_002E0C20 < 10.0f) {
        float tJob = pjob->tJob + g_2dded0.dt;
        float tRamp = pjob->tRampStart;
        pjob->tJob = tJob;
        if (tRamp < tJob)
            AddSuck(B_002DE578, g_2dded0.dt / (pjob->rampEnd - tRamp));
    }
}
