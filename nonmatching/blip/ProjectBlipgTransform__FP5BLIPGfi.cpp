#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct VU4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Clock { float time; float dt; };
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct BLIPG {
    char pad0[0xC]; VT *vtable;
    char pad1[0xF0 - 0x10]; VU4 center;
    char pad2[0x120 - 0x100]; float radiusBase;
    char pad3[0x160 - 0x124]; int motion; char pad3b[0x170 - 0x164]; char emitdv[0x43C - 0x170];
    int blipok; char pad4[0x444 - 0x440]; int cblipe; DL blips;
};
struct BLIP { char pad[0x1080]; int iblipfLatest; int cblipe; char *psx; };
struct BLIPSX { QW posFinal; QW vFinal; };
struct BLIPF { VU4 ablipp[43]; VU4 ablipv[43]; VU4 ablipx[43]; char pad[0x30]; };
extern DLI *g_2dd2fc;
extern Clock g_2dded0;
extern int g_2c3c5c;
extern "C" char B_003DD2CC[];
extern "C" MATRIX4 CalculateEmitdvMatrix(void *emitdv);
extern "C" void FlushCache(int);
extern "C" void LoadSprBuf__Fie(int, ...);
extern "C" void SaveSprBuf__FPve(void *, ...);
extern "C" void func_00201998(void);
extern "C" void func_002417F0(int, int, int);
extern int g_2de59c;
extern "C" void RemoveBlip__FP4BLIP(void *);
extern "C" int CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7(MATRIX4 *, QW, void *, void *, void *, int, int, VU4 *, VU4 *);
extern float g_2a4af4;
extern float g_2a4af8;

inline void PushDli(DLI *it, DL *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvFirst(DLI *it)
{
    char *item = it->list->first;
    it->current = item + it->offset;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}


extern "C" float RadNormalize__Ff(float);
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
extern "C" void *ProjectBlipgTransformAccel__FP5BLIPGf(BLIPG *, float);
extern int D_002BC9C0;
extern float RO_FLT_002A4AFC;
extern float RO_FLT_002A4B00;
extern "C" void *ProjectBlipgTransform__FP5BLIPGfi(BLIPG *pblipg, float dt, int fForce)
{
    MATRIX4 amatDv;
    if (pblipg->motion == 0) {
        if (D_002BC9C0 == 0)
            return ProjectBlipgTransformAccel__FP5BLIPGf(pblipg, dt);
        amatDv = CalculateEmitdvMatrix(pblipg->emitdv);
    }
    VU4 posMin;
    VU4 posMax;
    *(QW *)&posMin = 0;
    *(QW *)&posMax = 0;
    posMin.x = posMin.y = posMin.z = RO_FLT_002A4AFC;
    posMax.x = posMax.y = posMax.z = RO_FLT_002A4B00;
    DLI iterator;
    PushDli(&iterator, &pblipg->blips);
    char *pblip = PvFirst(&iterator);
    QW scratch;
    while (pblip != 0) {
        int dead = 0;
        int out = 0;
        int latest = ((BLIP *)pblip)->iblipfLatest;
        int next = (latest + 1) & 1;
        BLIPF *old = (BLIPF *)(pblip + latest * 0x840);
        BLIPF *fresh = (BLIPF *)(pblip + next * 0x840);
        Clock *pclock = &g_2dded0;
        VU4 *oldx = old->ablipx;
        VU4 *newp = fresh->ablipp;
        VU4 *newv = fresh->ablipv;
        VU4 *newx = fresh->ablipx;
        for (int index = 0; index < ((BLIP *)pblip)->cblipe; index++, oldx++) {
            if (oldx[-43].w <= g_2dded0.time) {
                dead++;
                continue;
            }
            switch (pblipg->motion) {
            case 0:
                asm("lqc2 vf5, %0" : : "m" (oldx[-43]));
                asm("lqc2 vf2, %0" : : "m" (*((QW *)&amatDv + 2)));
                asm("lqc2 vf1, %0" : : "m" (*((QW *)&amatDv + 3)));
                asm("lqc2 vf3, %0" : : "m" (*((QW *)&amatDv + 0)));
                asm("lqc2 vf4, %0" : : "m" (*((QW *)&amatDv + 1)));
                asm("vmulax.xyz ACC, vf3, vf5x");
                asm("vmadday.xyz ACC, vf4, vf5y");
                asm("vmaddaz.xyz ACC, vf2, vf5z");
                asm("vmaddw.xyz vf3, vf1, vf0w");
                asm("sqc2 vf3, %0" : "=m" ((*newv)));
                asm("qmtc2.ni %0, vf2" : : "r" (*(int *)&pclock->dt));
                asm("lqc2 vf1, %0" : : "m" (oldx[-86]));
                goto integrate;
            case 1:
                asm("lqc2 vf3, %0" : : "m" (oldx[-43]));
                asm("sqc2 vf3, %0" : "=m" ((*newv)));
                asm("qmtc2.ni %0, vf2" : : "r" (*(int *)&pclock->dt));
                asm("lqc2 vf1, %0" : : "m" (oldx[-86]));
            integrate:
                asm("vadda.xyzw ACC, vf0, vf1");
                asm("vmaddx.xyzw vf1, vf3, vf2x");
                asm("sqc2 vf2, %0" : "=m" (scratch));
                asm("sqc2 vf1, %0" : "=m" ((*newp)));
                break;
            case 2: {
                float remaining = oldx[-43].w - g_2dded0.time;
                float step;
                asm("min.s %0, %1, %2" : "=f" (step) : "f" (remaining), "f" (pclock->dt));
                QW *psx = (QW *)(((BLIP *)pblip)->psx + index * 0x20);
                EvaluateBezierPos__FfffP6VECTORN63(remaining, step, 1.0f, *(QW *)&oldx[-86], *(QW *)&oldx[-43], psx[0], psx[1],
                                                   (QW *)&(*newp), (QW *)&(*newv), 0);
                if (out != index) {
                    QW *pdestination = (QW *)(((BLIP *)pblip)->psx + out * 0x20);
                    pdestination[0] = psx[0];
                    pdestination[1] = psx[1];
                }
                break;
            }
            default:
                break;
            }
            (*newp).w = oldx[-86].w;
            (*newv).w = oldx[-43].w;
            *(QW *)&(*newx) = *(QW *)&oldx[0];
            if (pblipg->blipok == 2)
                (*newx).w = RadNormalize__Ff(oldx[0].w + oldx[0].z * pclock->dt);
            asm("lqc2 vf3, %0" : : "m" ((*newp)));
            asm("lqc2 vf1, %0" : : "m" (posMin));
            asm("vmini.xyz vf1, vf1, vf3");
            asm("lqc2 vf2, %0" : : "m" (posMax));
            asm("sqc2 vf1, %0" : "=m" (posMin));
            asm("lqc2 vf1, %0" : : "m" ((*newp)));
            asm("vmax.xyz vf2, vf2, vf1");
            asm("sqc2 vf2, %0" : "=m" (posMax));
            out++;
            newp++;
            newv++;
            newx++;
        }
        ((BLIP *)pblip)->cblipe -= dead;
        pblipg->cblipe -= dead;
        if (((BLIP *)pblip)->cblipe < 1)
            RemoveBlip__FP4BLIP(pblip);
        else
            ((BLIP *)pblip)->iblipfLatest = next;
        pblip = PvStep(&iterator);
    }
    if (pblipg->cblipe < 1) {
        VT *vt = pblipg->vtable;
        vt->fn((char *)pblipg + vt->delta);
    } else {
        float halfValue = 0.5f;
        int bits;
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (halfValue));
        asm("lqc2 vf1, %0" : : "m" (posMax));
        asm("lqc2 vf2, %0" : : "m" (posMin));
        asm("qmtc2.ni %0, vf3" : : "r" (bits));
        asm("vmulax.xyzw ACC, vf2, vf3x");
        asm("vmaddx.xyzw vf2, vf1, vf3x");
        float base = pblipg->radiusBase;
        asm("vsub.xyzw vf1, vf2, vf1");
        asm("sqc2 vf3, %0" : "=m" (scratch));
        asm("vmul.xyz vf1, vf1, vf1");
        asm("vaddw.x vf4, vf0, vf0w");
        asm("vadday.x ACC, vf1, vf1y");
        asm("vmaddz.x vf1, vf4, vf1z");
        asm("sqc2 vf2, %0" : "=m" (pblipg->center));
        asm(".word 0x4A0103BD");
        asm("vwaitq");
        asm("vaddq.x vf1, vf0, Q");
        int radiusBits;
        asm("qmfc2.ni %0, vf1" : "=r" (radiusBits));
        float radius;
        asm("mtc1 %1, %0\n\tnop" : "=f" (radius) : "r" (radiusBits));
        *(float *)((char *)pblipg + 0x100) = radius + base;
    }
    DLI *restored = iterator.next;
    g_2dd2fc = restored;
    return restored;
}
