typedef int QW __attribute__((mode(TI)));
struct VEC_19EAB0 {
    float x, y, z, w;
    void Clear() { x = y = z = 0; }
} __attribute__((aligned(16)));
struct LM_19EAB0 { float gMin; float gMax; };
struct ASEG_19EAB0 { char pad0[0x74]; float duration; };
struct VT_19EAB0 { char pad0[0x18]; short d18; short i18; void (*Notify)(void *, int, int, int, int, int); };
struct PATH_19EAB0 {
    char pad0[0xC];
    VT_19EAB0 *vt;
    char pad10[0x190 - 0x10];
    int n190;
    char pad194[0x1D0 - 0x194];
    int sfxEnter;
    int sfxExit;
};
struct JT_19EAB0 {
    char pad0[0x190];
    VEC_19EAB0 v190;
    char pad1A0[0x1010 - 0x1A0];
    QW posOffset;
    char pad1020[0x1030 - 0x1020];
    char asega[4];
    char sma[0x1060 - 0x1034];
    QW pos1060;
    VEC_19EAB0 dpos1070;
    char pad1080[0x14D4 - 0x1080];
    int f14D4;
};
struct PIPE_19EAB0 {
    JT_19EAB0 *pjt;
    int state;
    float tState;
    PATH_19EAB0 *ppath;
    float s;
    char pad14[0x18 - 0x14];
    int fReverse;
    int n1C;
    int stateExit;
    char pad24[0x30 - 0x24];
    QW pos30;
    char pad40[0x70 - 0x40];
    ASEG_19EAB0 *pasegSlide;
    ASEG_19EAB0 *pasegEnter;
    ASEG_19EAB0 *pasegExit;
    ASEG_19EAB0 *pasegSpin;
};
extern "C" {
void SubscribeLoObject(PATH_19EAB0 *, JT_19EAB0 *);
void UnsubscribeLoObject(PATH_19EAB0 *, JT_19EAB0 *);
void func_00204F78(JT_19EAB0 *, PATH_19EAB0 *, int);
float func_001E6728(PATH_19EAB0 *, float);
void GetPathPosFromS(PATH_19EAB0 *, QW *, int, float);
void bevy_player_p14_19e110(PIPE_19EAB0 *, LM_19EAB0 *);
float GLimitLm__FP2LMf(LM_19EAB0 *, float);
QW ConvertAloPos(JT_19EAB0 *, int, QW);
void func_00140C88(JT_19EAB0 *, int);
int NewEmitter(int);
void SetEmitterUnpositioned(int, void *);
void SetAmbPos(int, QW);
QW PosLoWorld(JT_19EAB0 *);
void SetJtJtcs(JT_19EAB0 *, int);
void RetractSmaRef(void *);
void ApplyAsegToHandle(ASEG_19EAB0 *, JT_19EAB0 *, int, void *, float, float);
extern JT_19EAB0 *g_2e1e40;
extern QW g_2a2dc0;
}
struct CLOCK_19EAB0 { float t; };
extern "C" CLOCK_19EAB0 g_2dded0;

// lane 0 of a QW held in a general register, to an FP register
static inline float Lane0(QW q)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}

// lane 2 of a QW held in a general register
static inline float Lane2(QW q)
{
    float f;
    asm("pextuw %0, $0, %1" : "=r"(f) : "r"(q));
    return f;
}

extern "C" void SetJtPipeState(PIPE_19EAB0 *ppipe, int state)
{
    struct {
        QW posAhead;
        QW posBehind;
        LM_19EAB0 lm;
        QW pos;
        QW posLocal;
        QW posOld;
    } l;
    int stateOld = ppipe->state;
    if (state == stateOld)
        return;
    switch (stateOld) {
    case -1: {
        float ds = 50.0f;
        PATH_19EAB0 *ppath = ppipe->ppath;
        ppath->vt->Notify((char *)ppath + ppath->vt->d18, 5, 0, 0, 0, 0);
        SubscribeLoObject(ppipe->ppath, ppipe->pjt);
        func_00204F78(ppipe->pjt, ppipe->ppath, 1);
        ppipe->stateExit = stateOld;
        float sAhead = func_001E6728(ppipe->ppath, ppipe->s + ds);
        GetPathPosFromS(ppipe->ppath, &l.posAhead, 0, sAhead);
        float sBehind = func_001E6728(ppipe->ppath, ppipe->s - ds);
        GetPathPosFromS(ppipe->ppath, &l.posBehind, 0, sBehind);
        int fence; // orders the VU0 blocks: never written
        QW dir = g_2a2dc0;
        QW length;
        asm("lqc2 vf2, %1" : "=r"(fence) : "m"(l.posAhead));
        asm("lqc2 vf1, %1" : "=r"(fence) : "m"(l.posBehind), "r"(fence));
        asm("vsub.xyzw vf3, vf2, vf1" : "=r"(fence) : "r"(fence));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r"(fence) : "r"(fence));
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(length) : "r"(fence));
        if (Lane0(length) < 0.0001f)
            ;
        else
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q\n\tqmfc2.ni %0, vf2" : "=r"(dir));
        ppipe->fReverse = Lane2(dir) < -0.5f;
        bevy_player_p14_19e110(ppipe, &l.lm);
        ppipe->s = GLimitLm__FP2LMf(&l.lm, ppipe->s);
        GetPathPosFromS(ppipe->ppath, &l.pos, 0, ppipe->s);
        QW posConv = ConvertAloPos(ppipe->pjt, 0, ppipe->pos30);
        asm("qmtc2.ni %0, vf2" : : "r"(posConv));
        asm("lqc2 vf1, %2\n\tsqc2 vf2, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0"
            : "=m"(ppipe->pjt->posOffset), "=m"(l.posLocal) : "m"(l.pos));
        JT_19EAB0 *pjt = ppipe->pjt;
        asm("lqc2 vf2, %0" : : "m"(l.pos));
        asm("lqc2 vf1, %0" : : "m"(pjt->pos1060));
        asm("vsub.xyzw vf1, vf1, vf2");
        asm("sqc2 vf1, %0" : "=m"(*(QW *)&pjt->dpos1070));
        ppipe->pjt->dpos1070.z = 0;
        func_00140C88(ppipe->pjt, ppipe->ppath->n190);
        if (ppipe->ppath->sfxEnter) {
            int emitter = NewEmitter(ppipe->ppath->sfxEnter);
            SetEmitterUnpositioned(emitter, 0);
            SetAmbPos(emitter, l.pos);
        }
        break;
    }
    case 0: {
        JT_19EAB0 *pjt = ppipe->pjt;
        if (pjt == g_2e1e40)
            SetJtJtcs(pjt, pjt->f14D4 ? 10 : 2);
        break;
    }
    }
    ppipe->state = state;
    ASEG_19EAB0 *paseg = 0;
    int grf = 1;
    float tStart = 0.0f;
    float svt = 1.0f;
    ppipe->tState = g_2dded0.t;
    switch (state) {
    case -1: {
        PATH_19EAB0 *ppath = ppipe->ppath;
        ppath->vt->Notify((char *)ppath + ppath->vt->d18, 6, 0, 0, 0, 0);
        UnsubscribeLoObject(ppipe->ppath, ppipe->pjt);
        func_00204F78(ppipe->pjt, ppipe->ppath, 0);
        JT_19EAB0 *pjt = ppipe->pjt;
        l.posOld = pjt->pos1060;
        QW posWorld = PosLoWorld(pjt);
        int fence; // orders the VU0 blocks: never written
        asm("lqc2 vf2, %1" : "=r"(fence) : "m"(l.posOld));
        asm("qmtc2.ni %1, vf3\n\tvsub.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m"(*(QW *)&pjt->dpos1070) : "r"(posWorld), "r"(fence));
        ppipe->pjt->dpos1070.z = 0;
        func_00140C88(ppipe->pjt, 0);
        if (ppipe->ppath->sfxExit) {
            int emitter = NewEmitter(ppipe->ppath->sfxExit);
            SetEmitterUnpositioned(emitter, 0);
            SetAmbPos(emitter, PosLoWorld(ppipe->pjt));
        }
        ppipe->ppath = 0;
        return;
    }
    case 0:
        paseg = ppipe->pasegEnter;
        if (!paseg) {
            paseg = ppipe->pasegSpin;
            tStart = paseg->duration * 0.5f;
            svt = 0.5f;
        }
        ppipe->n1C = 0;
        break;
    case 1:
        paseg = ppipe->pasegExit;
        grf = 9;
        break;
    case 2:
        paseg = ppipe->pasegSlide;
        grf = 9;
        break;
    case 3:
        paseg = ppipe->pasegSlide;
        svt = -1.0f;
        grf = 9;
        break;
    case 4:
        ppipe->fReverse = !ppipe->fReverse;
        paseg = ppipe->pasegSpin;
        break;
    }
    RetractSmaRef(ppipe->pjt->sma);
    JT_19EAB0 *pjt = ppipe->pjt;
    ApplyAsegToHandle(paseg, pjt, grf, pjt->asega, tStart, svt);
    ppipe->pjt->v190.Clear();
}
