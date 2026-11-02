struct BASIC { char pad[0xC]; virtual void v0(); virtual void v1(); virtual void v2(int, int, int, void *, int); virtual void v3(int, void *); };
struct ROOTARR { char pad[0xA0]; int count; unsigned char *base; };
struct ASEGA : BASIC {
    char pad0[8]; ROOTARR *paloRoot; int pad18_; 
};
struct ASEGAF { char pad[0x14]; ROOTARR *paloRoot; int oidSel; float tEvent; char pad2[0x20]; float f40; char pad3[0x18]; char sfx[1]; };
struct EVT { float t; int type; void *pv; union { int i; float f; } u; };
struct HOLD {
    ASEGA *p;
    HOLD(ASEGA *a) { p = a; a->v0(); }
    ~HOLD() { p->v1(); }
};
struct MSG { ASEGA *self; float t; void *pv; };
extern "C" {
extern int B_003DD490, B_002DDF40, B_002DFC00;
void *PloRootOrAseg(void *);
void StartSwAmbSfx(void *, int, int, int, int, int, void *, void *, float, float, float, void *);
void StopSwAmbSfx(void *, void *, void *, void *);
void JoltCm(void *, void *);
void TriggerJoyRumbleRumk__FP3JOY4RUMKf(void *, void *, float);
void *PloFindSwObject_thunk(void *, int, void *, void *);
int CidGetBasic(void *);
void ApplyAseg(void *, int, int, int, float, float);
void StartJsg(void *, int);
void SeekAsega(void *, int, float, float);
void RetractAsega(void *);
void SetAsegaHandsOff(void *, int);
void ShowHideLo(void *, int, void *, void *, void *, float);
void func_00210538(void *, int, int, int, void *, void *, float);
void ShowHideLoGlob(void *, int, void *, int, int, void *, void *);
void EnableDisableLoPart(void *, int, void *, int, int, void *, void *);
void ShowCountdownBlot(void *, float);
void HideCountdownBlot(void *);
void SetEyesClosedByOid(void *, int, int, void *, void *, float);
void SnapAsega(void *, void *);
void SetAloSelectedOid(int, int);
int FIsBasicDerivedFrom(int, int);
void SetJtLookLimits(int, void *, void *, void *);
void HandleAsegaEvent(ASEGA *pasega, EVT *pevt)
{
    HOLD hold(pasega);
    ASEGAF *self = (ASEGAF *)pasega;
    int fInside = 0;
    ROOTARR *paloRoot = self->paloRoot;
    self->tEvent = pevt->t;
    if (self->f40 < 0.0f) {
        unsigned char *base = paloRoot->base;
        if ((unsigned char *)pevt >= base)
            fInside = (unsigned char *)pevt < base + paloRoot->count * 16;
    }
    switch (pevt->type) {
    case 0:
        StartSwAmbSfx(&B_003DD490, ((int *)pevt->pv)[0], ((int *)pevt->pv)[1], ((int *)pevt->pv)[2], ((int *)pevt->pv)[3], self->oidSel, PloRootOrAseg(pasega), paloRoot, ((float *)pevt->pv)[4], ((float *)pevt->pv)[5], ((float *)pevt->pv)[6], (char *)pasega + 0x5C);
        break;
    case 1:
        StopSwAmbSfx(&B_003DD490, pevt->pv, paloRoot, (char *)pasega + 0x5C);
        break;
    case 2:
        JoltCm(&B_002DDF40, pevt->pv);
        break;
    case 3:
        TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, pevt->pv, pevt->u.f);
        break;
    case 4: {
        void *obj = PloFindSwObject_thunk(&B_003DD490, 4, pevt->pv, PloRootOrAseg(pasega));
        if (obj != 0) {
            switch (CidGetBasic(obj)) {
            case 0x6D:
                ApplyAseg(obj, 0, 0, 0, 0.0f, 1.0f);
                break;
            case 0x72:
                StartJsg(obj, 0);
                break;
            }
        }
        break;
    }
    case 5:
        SeekAsega(pasega, 0, ((float *)pevt)[2], ((float *)pevt)[3]);
        break;
    case 6:
        RetractAsega(pasega);
        break;
    case 9:
    case 10:
        SetAsegaHandsOff(pasega, fInside ^ (pevt->type == 9));
        break;
    case 7:
    case 8:
        ShowHideLo(&B_003DD490, fInside ^ (pevt->type == 7), pevt->pv, PloRootOrAseg(pasega), paloRoot, pevt->u.f);
        break;
    case 11: {
        MSG msg;
        msg.t = pevt->t;
        msg.self = pasega;
        msg.pv = pevt->pv;
        pasega->v3(9, &msg);
        break;
    }
    case 12: {
        void *pv = (char *)pevt + 8;
        pasega->v2(4, 0, 1, &pv, 0);
        break;
    }
    case 17:
    {
        int *m = (int *)pevt->pv; float *mf = (float *)pevt->pv;
        func_00210538(&B_003DD490, m[0], m[1], m[2], PloRootOrAseg(pasega), paloRoot, mf[3]);
        break;
    }
    case 13:
    case 14:
        ShowHideLoGlob(&B_003DD490, fInside ^ (pevt->type == 13), pevt->pv, pevt->u.i, self->oidSel, PloRootOrAseg(pasega), paloRoot);
        break;
    case 15:
    case 16:
        EnableDisableLoPart(&B_003DD490, fInside ^ (pevt->type == 15), pevt->pv, pevt->u.i, self->oidSel, PloRootOrAseg(pasega), paloRoot);
        break;
    case 18:
        ShowCountdownBlot(&B_003DD490, self->tEvent);
        break;
    case 19:
        HideCountdownBlot(&B_003DD490);
        break;
    case 20:
    {
        int *m = (int *)pevt->pv; float *mf = (float *)pevt->pv;
        SetEyesClosedByOid(&B_003DD490, m[0], m[1], PloRootOrAseg(pasega), paloRoot, mf[2]);
        break;
    }
    case 21:
        SnapAsega(pasega, pevt->pv);
        break;
    case 22:
        SetAloSelectedOid(self->oidSel, (int)pevt->pv);
        break;
    case 23:
        SetAloSelectedOid(self->oidSel, -1);
        break;
    case 24:
        if (self->oidSel != 0 && FIsBasicDerivedFrom(self->oidSel, 0x34) != 0)
            SetJtLookLimits(self->oidSel, pevt->pv, (char *)pevt->pv + 8, (char *)pevt->pv + 0x10);
        break;
    }
}
}
