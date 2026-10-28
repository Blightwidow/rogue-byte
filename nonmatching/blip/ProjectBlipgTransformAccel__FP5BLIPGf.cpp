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
    char pad3[0x170 - 0x124]; char emitdv[0x43C - 0x170];
    int blipok; char pad4[0x444 - 0x440]; int cblipe; DL blips;
};
struct BLIP { char pad[0x1080]; int iblipfLatest; int cblipe; };
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

extern "C" void *ProjectBlipgTransformAccel__FP5BLIPGf(BLIPG *pblipg, float dt)
{
    VU4 posMin;
    VU4 posMax;
    *(QW *)&posMin = 0;
    *(QW *)&posMax = 0;
    posMin.x = posMin.y = posMin.z = g_2a4af4;
    posMax.x = posMax.y = posMax.z = g_2a4af8;
    MATRIX4 matDv;
    matDv = CalculateEmitdvMatrix(pblipg->emitdv);
    DLI iterator;
    PushDli(&iterator, &pblipg->blips);
    char *pblip = PvFirst(&iterator);
    FlushCache(0);
    {
        int first = ((BLIP *)pblip)->iblipfLatest;
        int cb = ((BLIP *)pblip)->cblipe << 4;
        char *pblipf = pblip + first * 0x840;
        LoadSprBuf__Fie(cb, pblipf, cb, pblipf + 0x2B0, cb, pblipf + 0x560, 0, 0);
    }
    while (pblip != 0) {
        func_00201998();
        char *pblipNext = PvStep(&iterator);
        if (pblipNext != 0) {
            int latest = ((BLIP *)pblipNext)->iblipfLatest;
            char *pblipf = pblipNext + latest * 0x840;
            int cb = ((BLIP *)pblipNext)->cblipe << 4;
            LoadSprBuf__Fie(cb, pblipf, cb, pblipf + 0x2B0, cb, pblipf + 0x560, 0, 0);
        }
        char *psprbuf = &B_003DD2CC[g_2c3c5c * 0x50];
        QW vecDt;
        asm("" : "=r" (vecDt) : "0" (*(int *)&g_2dded0.dt));
        int dead = CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7(
            &matDv, vecDt, *(void **)(psprbuf + 0), *(void **)(psprbuf + 8), *(void **)(psprbuf + 0x10),
            ((BLIP *)pblip)->cblipe, pblipg->blipok, &posMin, &posMax);
        int next = (((BLIP *)pblip)->iblipfLatest + 1) & 1;
        char *pblipfOut = pblip + next * 0x840;
        SaveSprBuf__FPve(pblipfOut, pblipfOut + 0x2B0, pblipfOut + 0x560, 0);
        ((BLIP *)pblip)->cblipe -= dead;
        pblipg->cblipe -= dead;
        if (((BLIP *)pblip)->cblipe < 1)
            RemoveBlip__FP4BLIP(pblip);
        else
            ((BLIP *)pblip)->iblipfLatest = next;
        pblip = pblipNext;
    }
    func_002417F0(g_2de59c, 0, 0);
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
        QW half;
        asm("sqc2 vf3, %0" : "=m" (half));
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
