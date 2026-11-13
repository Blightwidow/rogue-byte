#include "sly2.h"
#include "dl.h"
#include "vu0inline.h"
#include "ps2inline.h"
struct VU4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Clock { float time; float dt; };
struct VT_139AB8 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct BLIPG {
    char pad0[0xC]; VT_139AB8 *vtable;
    char pad1[0xF0 - 0x10]; QW center;
    char pad2[0x120 - 0x100]; float radiusBase;
    char pad3[0x170 - 0x124]; char emitdv[0x43C - 0x170];
    int blipok; char pad4[0x444 - 0x440]; int cblipe; DL blips;
};
struct BLIP { char pad[0x1080]; int iblipfLatest; int cblipe; };
extern Clock g_2dded0;
extern int g_2c3c5c;
struct SPRBUF { void *first; int pad0; void *second; int pad1; void *third; char pad2[0x3C]; };
extern "C" SPRBUF B_003DD2CC[];
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
    char *pblip = (char *)PvFirst(&iterator);
    int first = ((BLIP *)pblip)->iblipfLatest;
    char *pblipf = pblip + first * 0x840;
    FlushCache(0);
    {
        int cb = ((BLIP *)pblip)->cblipe << 4;
        LoadSprBuf__Fie(cb, pblipf, cb, pblipf + 0x2B0, cb, pblipf + 0x560, 0, 0);
    }
    while (pblip != 0) {
        func_00201998();
        char *pblipNext = (char *)PvStep(&iterator);
        if (pblipNext != 0) {
            int latest = ((BLIP *)pblipNext)->iblipfLatest;
            char *pblipf = pblipNext + latest * 0x840;
            int cb = ((BLIP *)pblipNext)->cblipe << 4;
            LoadSprBuf__Fie(cb, pblipf, cb, pblipf + 0x2B0, cb, pblipf + 0x560, 0, 0);
        }
        QW vecDt = (QW) * (int *)&g_2dded0.dt;
        int dead = CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7(
            &matDv, vecDt, B_003DD2CC[g_2c3c5c].first, B_003DD2CC[g_2c3c5c].second, B_003DD2CC[g_2c3c5c].third,
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
        VT_139AB8 *vt = pblipg->vtable;
        vt->fn((char *)pblipg + vt->delta);
    } else {
        QW half = VectorFromFloat(0.5f);
        QW maxima = *(QW *)&posMax;
        QW center = BlendX(half, *(QW *)&posMin, half, maxima);
        float radius = LaneX(SqrtX(SquaredLength(VectorSub(center, maxima))));
        float base = pblipg->radiusBase;
        pblipg->center = center;
        *(float *)((char *)pblipg + 0x100) = radius + base;
    }
    PopDli(&iterator);
    return g_2dd2fc;
}
