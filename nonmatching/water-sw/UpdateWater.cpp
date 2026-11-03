#include "sly2.h"
struct SW; struct SO; struct PART;
struct ALLOCREQ { int cb; int cbAlign; };
struct VT { char pad[0x20]; short delta; short index; void (*fn)(void *, int, void *); };
struct VT108 { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct VT198 { char pad[0x198]; short delta; short index; void (*fn)(void *, void *); };
struct SOV { char pad[0xC]; void *vt; };
struct XA { char pad0[4]; SO *pso; char pad1[4]; XA *pxaNext; };
struct LNODE { char pad0[4]; LNODE *pnext; char pad8[4]; SO *pso; };
struct SO58 { char pad[0x98]; short kind; };
struct SOB { char pad[0xD4]; float f; };
struct SOEC { float f0, f4, f8, fC, f10, f14; };
struct PARTX { char pad[0x70]; QW pos70; };
struct PARTO { char pad[0x78]; float f78; };
struct SOX {
    char pad0[0xC]; void *vt;
    char pad10[0x58 - 0x10]; SO58 *p58;
    char pad5c[0xE0 - 0x5C]; int cpart; char *apart; SOB *pE8; SOEC *pEC;
    char pad_f0[0x148 - 0xF0]; long flags;
    char pad150[0x248 - 0x150]; float f248;
};
struct PARTY { PARTO *powner; char pad4[0xC]; long flags10; char pad18[0x50 - 0x18]; QW pos50; };
struct SWX {
    char pad[0xE0]; int cpart; char *apart; int padE8; struct XL *pXL; char padF0[0x150 - 0xF0]; XA *pxaFirst; char pad154[0x170 - 0x154]; void *pobj170;
};
struct XL { char pad[0x64]; LNODE *plist; };
struct EVT { int id; int pad4; float f8; int padC; QW q10; QW q20; QW q30; };
static inline float GMin(float a, float b) { return a > b ? b : a; }
struct VEC { float v[4]; } __attribute__((aligned(16)));
struct OBJ170 { char pad[0xC]; void *vt; };
struct MSG { SWX *psw; SOX *pso; };
extern "C" {
void UpdateSo(SWX *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int CpartCollectAlo(SWX *, int (*)(void *, PART *), void *, PART **);
int func_00229D60(void *, PART *);
int GetSoNoXpsAll(SOX *);
int FXfKindDynamic(short);
float UGetWaterSubmerged(SWX *, SOX *, int, int);
XA *PxaAllocSw(void *);
int FIsBasicDerivedFrom(void *, int);
int ClsgClipEdgeToObjects(QW, QW, int, void *, int, char *);
int NewEmitter(int);
void SetEmitterUnpositioned(int, void *);
void SetAmbRange(int, float, float);
void SetAmbVolume(int, float);
void UpdateSwXaList__FP2SWPP2XA(SWX *, XA **);
extern char B_003DD490[];
extern QW g_2a2dd0;
extern QW g_2a2dc0;
}
static inline void *PvAllocStack(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocStackImpl__Fi(preq);
}

extern "C" void UpdateWater(SWX *psw)
{
    char frame[0x10];
    UpdateSo(psw);
    if (psw->cpart != 0) {
        union { ALLOCREQ req; MSG msg; QW vel; } sp10;
        int cpart;
        XA **ppxa = &psw->pxaFirst;
        XA *pxa;
        for (pxa = psw->pxaFirst; pxa; pxa = pxa->pxaNext)
            ((SOX *)pxa->pso)->flags |= 0x80000000L;
        CStackFrame_Construct(frame);
        PART **appart = (PART **)PvAllocStack(&sp10.req, psw->cpart * 4);
        cpart = CpartCollectAlo(psw, func_00229D60, 0, appart);
        for (LNODE *pn = psw->pXL->plist; pn; pn = pn->pnext) {
            SOX *pso = (SOX *)pn->pso;
            if (!pso->pE8)
                continue;
            if (pso->pE8->f < 0.0001f)
                continue;
            if (GetSoNoXpsAll(pso) != 0)
                continue;
            if (FXfKindDynamic(pso->p58->kind) == 0)
                continue;
            if (UGetWaterSubmerged(psw, pso, 0, 0) == 0.0f)
                continue;
            long flags = pso->flags | 0x100000000L;
            pso->flags = flags;
            if (flags & 0x80000000L)
                continue;
            pxa = PxaAllocSw(B_003DD490);
            *(SWX **)pxa = psw;
            pxa->pso = (SO *)pso;
            pxa->pxaNext = psw->pxaFirst;
            psw->pxaFirst = pxa;
            if (!psw->pobj170)
                continue;
            VT108 *vt = (VT108 *)pso->vt;
            sp10.vel = vt->fn((char *)pso + vt->delta);
            if (((float *)&sp10.vel)[2] < -100.0f) {
            for (int i = 0; i < pso->cpart; i++) {
                PARTY *ppart = (PARTY *)(pso->apart + i * 0xB0);
                if (ppart->flags10 & (0xA000L << 35))
                    continue;
                VEC rel0;
                VEC rel1;
                char alsg[0x600];
                VEC origin;
                EVT evt;
                int fence;
                /* origin = g_2a2dd0; rel0 = pos50 - origin; rel1 = powner pos70 - origin */
                asm("lqc2 vf2, %1" : "=r"(fence) : "m"(g_2a2dd0));
                asm("sqc2 vf2, %0" : "=m"(origin) : "r"(fence));
                asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(rel0) : "m"(ppart->pos50), "r"(fence));
                asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(rel1) : "m"(((PARTX *)ppart->powner)->pos70), "r"(fence));
                float dz;
                if (FIsBasicDerivedFrom(pso, 0x33))
                    dz = pso->f248;
                else
                    dz = pso->pEC->f8 - ppart->powner->f78;
                rel0.v[2] += dz;
                rel1.v[2] += dz;
                if (ClsgClipEdgeToObjects(*(QW *)&rel0, *(QW *)&rel1, cpart, appart, 0x10, alsg) <= 0)
                    continue;
                float vol = GMin(-((float *)&sp10.vel)[2], 600.0f) * 0.0016666667f;
                SOEC *pec = pso->pEC;
                float size = ((pec->f10 - pec->f0) + (pec->f14 - pec->f4)) * 0.5f;
                int id = NewEmitter(0x13);
                SetEmitterUnpositioned(id, pso);
                SetAmbRange(id, 100.0f, 1000.0f);
                SetAmbVolume(id, vol);
                memset(&evt, 0, 0x40);
                int fence2;
                asm("lqc2 vf1, %1\n\tlqc2 vf2, %2" : "=r"(fence2) : "m"(*(QW *)alsg), "m"(origin));
                asm("vadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(evt.q20) : "r"(fence2));
                evt.id = 0xE;
                evt.f8 = size * vol;
                evt.q10 = g_2a2dc0;
                OBJ170 *pobj = (OBJ170 *)psw->pobj170;
                VT198 *vt2 = (VT198 *)pobj->vt;
                vt2->fn((char *)pobj + vt2->delta, &evt);
            }
            }
        }
        for (pxa = psw->pxaFirst; pxa; pxa = pxa->pxaNext) {
            SOX *pso = (SOX *)pxa->pso;
            long flags = pso->flags;
            if (((int)(flags >> 31) & 1) != ((int)(flags >> 32) & 1)) {
                sp10.msg.psw = psw;
                sp10.msg.pso = pso;
                VT *vt = (VT *)pso->vt;
                vt->fn((char *)pso + vt->delta, (pso->flags & 0x80000000L) ? 5 : 4, &sp10.msg);
            }
        }
        UpdateSwXaList__FP2SWPP2XA(psw, ppxa);
        CStackFrame_Destructor(frame, 2);
    }
}
