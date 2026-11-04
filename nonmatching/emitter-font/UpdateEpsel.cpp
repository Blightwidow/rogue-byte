struct CRef_15CF30 { int tag; union { float g; int n; }; int p2; int p3; };
struct EPSEL {
    char pad0[0x110]; int episode; int target; int last; int mode; int sub; int pad124; int replay; int hintState; float hintSince;
};
struct SW_15CF30 { char pad0[0x3B58]; int asaveWarp[9]; int asaveCoins[9]; };
extern "C" {
int CGc_FFindScreen(void *);
void CRef_Destruct(CRef_15CF30 *);
int FBlotLabelPlaying(EPSEL *, int);
int FJoyButtonPressed(void *, int);
int IrowLastEpselReplay(EPSEL *);
int LabelFromEpselMode(EPSEL *);
void *NewEmitter(int);
int PdescFromEpisode(int);
void *PloFindSwObject_thunk(SW_15CF30 *, int, int, int);
void QueueMovie(void *, int);
void RefGetGameSaveValue(CRef_15CF30 *, int, void *);
void RequestTransition(SW_15CF30 *, int, int, int, int, int);
void SetEmitterUnpositioned(void *, void *);
void SetEpselHint(EPSEL *, int);
void SetEpselMode(EPSEL *, int, int);
void UpdateBlotMovie(EPSEL *);
int UpdateJoyNavX(void *);
int UpdateJoyNavY(void *, int);
void Warp_SetState(void *, int);
void Warp_Start(void *);
extern char B_002DFC00[];
extern char B_002E6550[];
extern char B_002F66B0[];
extern char B_003D4A60[];
extern char B_003D9ED0[];
extern char B_003DA4F0[];
extern SW_15CF30 B_003DD490;
extern int D_002BE200[];
extern int D_002BE248[];
extern int D_002BE26C;
extern int D_002BE270;
extern int D_002BE278[];
extern int D_002BE2A8[];
extern float g_2ddf0c;
static inline int GetSaveInt_15CF30(int path)
{
    CRef_15CF30 ref;
    RefGetGameSaveValue(&ref, path, B_003D4A60);
    int n = ref.n;
    CRef_Destruct(&ref);
    return n;
}
static inline float GetSaveFloat_15CF30(int path)
{
    CRef_15CF30 ref;
    RefGetGameSaveValue(&ref, path, B_003D4A60);
    float g = ref.g;
    CRef_Destruct(&ref);
    return g;
}
void UpdateEpsel(EPSEL *self)
{
    UpdateBlotMovie(self);
    if (CGc_FFindScreen(B_003D9ED0) || CGc_FFindScreen(B_002E6550) || CGc_FFindScreen(B_003DA4F0))
        return;
    int label = LabelFromEpselMode(self);
    switch (self->mode) {
    case 2: {
        float nav = (float)UpdateJoyNavY(B_002DFC00, label);
        if ((nav < 0.0f && self->episode <= 0) || (nav > 0.0f && !(self->episode < self->last))) {
            SetEmitterUnpositioned(NewEmitter(0x36), 0);
            break;
        }
        if (nav != 0.0f) {
            if (nav < 0.0f)
                self->target = self->episode - 1;
            else
                self->target = self->episode + 1;
            int mode = 6;
            if (nav > 0.0f)
                mode = 4;
            SetEpselMode(self, mode, -1);
            break;
        }
        if (FJoyButtonPressed(B_002DFC00, 0x40)) {
            SetEpselMode(self, 7, -1);
            break;
        }
        if (self->episode != 0 && FJoyButtonPressed(B_002DFC00, 0x10)) {
            self->target = 0;
            SetEpselMode(self, 6, -1);
            break;
        }
        switch (self->hintState) {
        case 0: {
            int hint = D_002BE248[self->episode];
            int saved = B_003DD490.asaveCoins[self->episode];
            int shown = 0;
            if ((saved != 0 && !(GetSaveInt_15CF30(saved) < 100)) || D_002BE26C != 0)
                shown = 1;
            if (hint != 0 && shown != 0 && g_2ddf0c - self->hintSince > 10.0f)
                SetEpselHint(self, 1);
            break;
        }
        case 1:
            if (FJoyButtonPressed(B_002DFC00, 0x80)) {
                QueueMovie(B_002F66B0, D_002BE248[self->episode]);
                RequestTransition(&B_003DD490, 0, 0x189, -1, 0, -1);
                SetEmitterUnpositioned(NewEmitter(0x34), 0);
                break;
            }
            if (g_2ddf0c - self->hintSince > 2.0f)
                SetEpselHint(self, 0);
            break;
        }
        break;
    }
    case 8:
        switch (self->sub) {
        case -1:
            if (FJoyButtonPressed(B_002DFC00, 0x40)) {
                SetEpselMode(self, 0xA, -1);
                break;
            }
            if (FJoyButtonPressed(B_002DFC00, 0x10))
                SetEpselMode(self, 9, -1);
            break;
        case 0: {
            if (FJoyButtonPressed(B_002DFC00, 0x40)) {
                int replay = self->replay;
                D_002BE270 = replay;
                QueueMovie(B_002F66B0, D_002BE200[replay]);
                RequestTransition(&B_003DD490, 0, 0x189, -1, 0, -1);
                SetEmitterUnpositioned(NewEmitter(0x34), 0);
                break;
            }
            if (FJoyButtonPressed(B_002DFC00, 0x10)) {
                SetEpselMode(self, 9, -1);
                break;
            }
            float nav = (float)UpdateJoyNavX(B_002DFC00);
            if ((nav < 0.0f && self->replay <= 0) || (nav > 0.0f && !(self->replay < IrowLastEpselReplay(self)))) {
                SetEmitterUnpositioned(NewEmitter(0x36), 0);
                break;
            }
            if (nav != 0.0f) {
                if (nav < 0.0f)
                    self->replay = self->replay - 1;
                else
                    self->replay = self->replay + 1;
                int dir = 1;
                if (nav > 0.0f)
                    dir = 2;
                SetEpselMode(self, 8, dir);
            }
            break;
        }
        case 1:
        case 2:
            if (!FBlotLabelPlaying(self, label))
                SetEpselMode(self, 8, 0);
            break;
        }
        break;
    case 10:
        if (!FBlotLabelPlaying(self, label)) {
            int saved = B_003DD490.asaveWarp[self->episode];
            int warp = 0;
            if (saved != 0) {
                warp = 1;
                if (GetSaveFloat_15CF30(saved) != 0.0f)
                    warp = 0;
            }
            if (warp != 0) {
                void *pwarp = PloFindSwObject_thunk(&B_003DD490, 5, D_002BE2A8[self->episode], 0);
                if (pwarp != 0) {
                    Warp_SetState(pwarp, 3);
                    Warp_Start(pwarp);
                } else {
                    warp = 0;
                }
            }
            if (warp == 0) {
                int pdesc = PdescFromEpisode(self->episode);
                RequestTransition(&B_003DD490, pdesc, 0x189, -1, 0, 0x30A);
            }
            SetEpselMode(self, -1, -1);
        }
        break;
    case -1:
        break;
    default:
        if (!FBlotLabelPlaying(self, label)) {
            int next = D_002BE278[self->mode];
            int sub = -1;
            if (next == 8 && self->episode == 0) {
                self->replay = 0;
                sub = 0;
            }
            SetEpselMode(self, next, sub);
        }
        break;
    }
}
}
