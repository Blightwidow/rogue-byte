struct CRef { int tag; float value; };
struct EPSEL {
    char pad0[0x110]; int episode; int target; int last; int mode; int sub; int pad124; int replay; int hintState; float hintSince;
};
struct SAVEROOT { char pad0[0x3B58]; };
extern "C" {
int CGc_FFindScreen(void *);
void CRef_Destruct(CRef *);
int FBlotLabelPlaying(void *, int);
int FJoyButtonPressed(void *, int);
int IrowLastEpselReplay(void *);
int LabelFromEpselMode(void *);
void *NewEmitter(int);
int PdescFromEpisode(int);
void *PloFindSwObject_thunk(void *, int, int, int);
void QueueMovie(void *, int);
void RefGetGameSaveValue(CRef *, int, void *);
void RequestTransition(void *, int, int, int, int, int);
void SetEmitterUnpositioned(void *, void *);
void SetEpselHint(void *, int);
void SetEpselMode(void *, int, int);
void UpdateBlotMovie();
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
extern SAVEROOT B_003DD490;
extern int D_002BE200[];
extern int D_002BE248[];
extern int D_002BE26C;
extern int D_002BE270;
extern int D_002BE278[];
extern int D_002BE2A8[];
extern float g_2ddf0c;
void UpdateEpsel(EPSEL *self) {
    CRef ref;
    UpdateBlotMovie();
    if (CGc_FFindScreen(B_003D9ED0) == 0 && CGc_FFindScreen(B_002E6550) == 0 && CGc_FFindScreen(B_003DA4F0) == 0) {
        int label = LabelFromEpselMode(self);
        switch (self->mode) {
        case 2: {
            float nav = (float)UpdateJoyNavY(B_002DFC00, label);
            if ((!(nav < 0.0f) || self->episode > 0) && (!(nav > 0.0f) || self->episode < self->last)) {
                if (nav != 0.0f) {
                    int episode = self->episode;
                    int next;
                    if (nav < 0.0f)
                        next = episode - 1;
                    else
                        next = episode + 1;
                    self->target = next;
                    int mode = 6;
                    if (nav > 0.0f) mode = 4;
                    SetEpselMode(self, mode, -1);
                    break;
                }
                if (FJoyButtonPressed(B_002DFC00, 0x40) != 0) {
                    SetEpselMode(self, 7, -1);
                    break;
                }
                if (self->episode != 0 && FJoyButtonPressed(B_002DFC00, 0x10) != 0) {
                    self->target = 0;
                    SetEpselMode(self, 6, -1);
                } else {
                    switch (self->hintState) {
                    case 0: {
                        int slot = self->episode * 4;
                        int shown = 0;
                        int saved = *(int *)((char *)&B_003DD490 + slot + 0x3B7C);
                        int hint = *(int *)((char *)D_002BE248 + slot);
                        if ((saved != 0 && (RefGetGameSaveValue(&ref, saved, B_003D4A60), CRef_Destruct(&ref), !((*(int *)&ref.value) < 0x64))) || D_002BE26C != 0) {
                            shown = 1;
                        }
                        if (hint != 0 && shown != 0 && (g_2ddf0c - self->hintSince) > 10.0f) SetEpselHint(self, 1);
                        break;
                    }
                    case 1:
                        if (FJoyButtonPressed(B_002DFC00, 0x80) != 0) {
                            QueueMovie(B_002F66B0, D_002BE248[self->episode]);
                            RequestTransition(&B_003DD490, 0, 0x189, -1, 0, 0);
                            SetEmitterUnpositioned(NewEmitter(0x34), 0);
                            break;
                        }
                        if ((g_2ddf0c - self->hintSince) > 2.0f) SetEpselHint(self, 0);
                        break;
                    }
                }
            } else {
                SetEmitterUnpositioned(NewEmitter(0x36), 0);
            }
            break;
        }
        case 8:
            switch (self->sub) {
            case -1:
                if (FJoyButtonPressed(B_002DFC00, 0x40) != 0) {
                    SetEpselMode(self, 0xA, -1);
                    break;
                }
                if (FJoyButtonPressed(B_002DFC00, 0x10) != 0) SetEpselMode(self, 9, -1);
                break;
            case 0: {
                if (FJoyButtonPressed(B_002DFC00, 0x40) != 0) {
                    int replay = self->replay;
                    D_002BE270 = replay;
                    QueueMovie(B_002F66B0, D_002BE200[replay]);
                    RequestTransition(&B_003DD490, 0, 0x189, -1, 0, 0);
                    SetEmitterUnpositioned(NewEmitter(0x34), 0);
                    break;
                }
                if (FJoyButtonPressed(B_002DFC00, 0x10) != 0) {
                    SetEpselMode(self, 9, -1);
                    break;
                }
                float nav = (float)UpdateJoyNavX(B_002DFC00);
                if ((nav < 0.0f && self->replay <= 0) || (nav > 0.0f && self->replay >= IrowLastEpselReplay(self))) {
                    SetEmitterUnpositioned(NewEmitter(0x36), 0);
                    break;
                }
                if (nav != 0.0f) {
                    int replay = self->replay;
                    int next;
                    if (nav < 0.0f)
                        next = replay - 1;
                    else
                        next = replay + 1;
                    self->replay = next;
                    int dir = 1;
                    if (nav > 0.0f) dir = 2;
                    SetEpselMode(self, 8, dir);
                }
                break;
            }
            default:
                if (FBlotLabelPlaying(self, label) == 0) SetEpselMode(self, 8, 0);
                break;
            }
            break;
        case 10:
            if (FBlotLabelPlaying(self, label) == 0) {
                int saved = *(int *)((char *)&B_003DD490 + self->episode * 4 + 0x3B58);
                int warp = 0;
                if (saved != 0) {
                    warp = 1;
                    RefGetGameSaveValue(&ref, saved, B_003D4A60);
                    CRef_Destruct(&ref);
                    if (ref.value != 0.0f) warp = 0;
                }
                if (warp != 0) {
                    void *object = PloFindSwObject_thunk(&B_003DD490, 5, D_002BE2A8[self->episode], 0);
                    if (object != 0) {
                        Warp_SetState(object, 3);
                        Warp_Start(object);
                    } else {
                        warp = 0;
                    }
                    if (warp == 0) RequestTransition(&B_003DD490, PdescFromEpisode(self->episode), 0x189, -1, 0, 0);
                } else {
                    RequestTransition(&B_003DD490, PdescFromEpisode(self->episode), 0x189, -1, 0, 0);
                }
                SetEpselMode(self, -1, -1);
            }
            break;
        case -1:
            break;
        default:
            if (FBlotLabelPlaying(self, label) == 0) {
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
}
