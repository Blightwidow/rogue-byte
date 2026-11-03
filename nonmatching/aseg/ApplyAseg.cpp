#include "sly2.h"
struct ALO_12F9B8;
struct XF_12F9B8;
struct ASEGA_12F9B8;
struct ACTVT_12F9B8;
struct ASEGAVT_12F9B8 {
    char pad0[8];
    short deltaRetain; short indexRetain; void (*pfnRetain)(void *);
    short deltaRelease; short indexRelease; void (*pfnRelease)(void *);
    short deltaUpdate; short indexUpdate; void (*pfnUpdate)(void *, int, int, int, int, int);
};
struct ASEGCHN_12F9B8 { int packed; int value; };
struct CHNPART_12F9B8 { int ipart; int oid; int value; };
struct EVENT_12F9B8 { int pad[4]; };
struct CLQ_12F9B8 { float g0; float g1; float g2; };
struct LM_12F9B8 { float gMin; float gMax; };
struct DL_12F9B8 { int pad[3]; };
struct ASEG_12F9B8 {
    int frame;
    char pad4[0x4C];
    DL_12F9B8 dlAsega;
    int cchn;
    ASEGCHN_12F9B8 *achn;
    int cpart;
    CHNPART_12F9B8 *apart;
    int grfAct;
    int handsOff;
    int pad74;
    float rate;
    int pad7C;
    CLQ_12F9B8 clqSpeed;
    int pad8C;
    LM_12F9B8 lmSpeed;
    int cevent;
    EVENT_12F9B8 *aevent;
    int iea;
};
struct ACT_12F9B8 {
    int field0; ALO_12F9B8 *palo; XF_12F9B8 *pxf; int grf; int pad10; int kind; ACTVT_12F9B8 *vt; int target1C; int target20;
    ASEGA_12F9B8 *pasega; ACT_12F9B8 *pactNext;
};
struct PARTLINK_12F9B8 { int value; unsigned nTarget; void *palo; int ipart; PARTLINK_12F9B8 *pnext; };
struct ASEGA_12F9B8 {
    int field0; int field4; int pad8; ASEGAVT_12F9B8 *vt; int pad10;
    ASEG_12F9B8 *paseg; ALO_12F9B8 *palo; float tLocal; float tTarget; int pad24[4];
    ACT_12F9B8 *pact; PARTLINK_12F9B8 *plink; int grfapl; float svt; int pad44; float rate; float speed; int iea; int pad54[2]; int field5C;
};
struct PARTVT_12F9B8 { char pad[0x160]; short delta; short index; void (*fn)(void *, int); };
struct PARTOBJ_12F9B8 { char pad[0xC]; PARTVT_12F9B8 *vt; };
static inline float GFromClq(CLQ_12F9B8 *pclq, float g) { return pclq->g0 + g * (pclq->g1 + g * pclq->g2); }
static inline float GLimitLm(LM_12F9B8 *plm, float g)
{
    float gMin = plm->gMin;
    float gMax = plm->gMax;
    if (g < gMin)
        g = gMin;
    else if (gMax < g)
        g = gMax;
    return g;
}
struct LOCK_12F9B8 {
    ASEGA_12F9B8 *p;
    LOCK_12F9B8(ASEGA_12F9B8 *pasega) { p = pasega; p->vt->pfnRetain((char *)p + p->vt->deltaRetain); }
    ~LOCK_12F9B8() { p->vt->pfnRelease((char *)p + p->vt->deltaRelease); }
};
extern "C" {
extern int B_003E1224;
extern int B_003E1218;
extern int B_002DE578;
extern ASEGAVT_12F9B8 D_002CAF48;
extern ACTVT_12F9B8 D_002CAF08;
void *PvAllocSlotheapImpl(int *);
float GetSuck(int *);
void SetAsegaSpeed(ASEGA_12F9B8 *, float);
void AppendDlEntry(void *, void *);
void CFramePtr_Assign(ASEGA_12F9B8 *, int);
void BindAsegChn(ASEG_12F9B8 *, ALO_12F9B8 *, ASEGCHN_12F9B8 *, ALO_12F9B8 **, XF_12F9B8 **);
void func_001F8668(ALO_12F9B8 *, int);
ACT_12F9B8 *PvAllocAct(int);
void InsertXfAct(ALO_12F9B8 *, XF_12F9B8 *, ACT_12F9B8 *);
void func_00130010(ASEG_12F9B8 *, ALO_12F9B8 *, CHNPART_12F9B8 *, PARTOBJ_12F9B8 **, unsigned *);
PARTLINK_12F9B8 *func_0012CE50(int);
void SetAsegaHandsOff(ASEGA_12F9B8 *, int);
void HandleAsegaEvent(ASEGA_12F9B8 *, EVENT_12F9B8 *);
void SnapAsega(ASEGA_12F9B8 *, int);
void HandleAsegaEventsFF(ASEGA_12F9B8 *);
void UpdateAsegaIeaCur__FP5ASEGA(ASEGA_12F9B8 *);
}
extern "C" void ApplyAseg(ASEG_12F9B8 *paseg, ALO_12F9B8 *paloRoot, float tLocal, float svtLocal, int grfapl, ASEGA_12F9B8 **ppasega)
{
    ASEGA_12F9B8 *pasega = (ASEGA_12F9B8 *)PvAllocSlotheapImpl(&B_003E1224);
    memset(pasega, 0, 0x60);
    pasega->field0 = 0;
    pasega->field4 = 0;
    pasega->vt = &D_002CAF48;
    pasega->field5C = 0;
    pasega->paseg = paseg;
    pasega->palo = paloRoot;
    pasega->tLocal = tLocal;
    pasega->grfapl = grfapl;
    pasega->rate = paseg->rate;
    float suck = GetSuck(&B_002DE578);
    pasega->speed = GLimitLm(&paseg->lmSpeed, GFromClq(&paseg->clqSpeed, suck));
    SetAsegaSpeed(pasega, svtLocal);
    AppendDlEntry(&B_003E1218, pasega);
    AppendDlEntry(&paseg->dlAsega, pasega);
    pasega->vt->pfnRetain((char *)pasega + pasega->vt->deltaRetain);
    LOCK_12F9B8 lock(pasega);
    CFramePtr_Assign(pasega, paseg->frame);
    if (ppasega)
        *ppasega = pasega;
    int ichn = 0;
    if (ichn < paseg->cchn) {
        ACTVT_12F9B8 *pvt = &D_002CAF08;
        int kind = (grfapl & 1) ? 7 : 5;
        do {
            ASEGCHN_12F9B8 *pchn = &paseg->achn[ichn];
            if (pchn->packed & 0x40000000)
                goto next;
            ALO_12F9B8 *palo;
            XF_12F9B8 *pxf;
            BindAsegChn(paseg, paloRoot, pchn, &palo, &pxf);
            if (pxf) {
                func_001F8668(palo, 0);
                ACT_12F9B8 *pact = PvAllocAct(0x2C);
                pact->vt = pvt;
                pact->field0 = 0;
                if (pchn->packed & 0x80000000)
                    pact->target20 = pchn->value;
                else
                    pact->target1C = pchn->value;
                pact->palo = palo;
                pact->pxf = pxf;
                pact->grf = paseg->grfAct;
                pact->kind = kind;
                pact->pasega = pasega;
                pact->pactNext = pasega->pact;
                pasega->pact = pact;
                InsertXfAct(palo, pxf, pact);
            }
        next:;
        } while (++ichn < paseg->cchn);
    }
    for (int ipart = 0; ipart < paseg->cpart; ipart++) {
        CHNPART_12F9B8 *ppart = &paseg->apart[ipart];
        PARTOBJ_12F9B8 *pobj;
        unsigned nTarget;
        func_00130010(paseg, paloRoot, ppart, &pobj, &nTarget);
        if (nTarget) {
            PARTLINK_12F9B8 *plink = func_0012CE50(0x14);
            plink->value = ppart->value;
            plink->nTarget = nTarget;
            plink->palo = pobj;
            plink->ipart = ppart->ipart;
            plink->pnext = pasega->plink;
            pasega->plink = plink;
            pobj->vt->fn((char *)pobj + pobj->vt->delta, ppart->ipart);
        }
    }
    SetAsegaHandsOff(pasega, paseg->handsOff);
    pasega->tTarget = tLocal;
    for (int ievent = 0; ievent < paseg->cevent; ievent++)
        HandleAsegaEvent(pasega, &paseg->aevent[ievent]);
    pasega->tLocal = pasega->tTarget;
    SnapAsega(pasega, (grfapl >> 2) & 1);
    if (grfapl & 2) {
        if (pasega->svt < 0.0f)
            pasega->iea = paseg->iea;
        HandleAsegaEventsFF(pasega);
    } else
        UpdateAsegaIeaCur__FP5ASEGA(pasega);
    pasega->vt->pfnUpdate((char *)pasega + pasega->vt->deltaUpdate, 2, 0, 0, 0, 0);
}
