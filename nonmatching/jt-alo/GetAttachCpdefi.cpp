#include "sly2.h"
#include "vu0inline.h"
struct SO { char pad[0x1024]; void *pvCam; };
struct CRV { char pad[0xE4]; int fClosed; char pad2[0x1BC - 0xE8]; int grfCrv; };
struct SMOOTHED { char pad[0x10]; float g; };
struct CAMHOLD { char pad[0x114]; SMOOTHED *psm; };
struct SMP;
struct ATTACH {
    SO *pso;
    int unk4;
    int state;
    char pad0C[0x14 - 0x0C];
    CRV *pcrv;
    char pad18[0x20 - 0x18];
    float s;
    char pad24[0x2C - 0x24];
    int dir;
    char pad30[0x40 - 0x30];
    VECTOR posTarget;
    float speed;
    char pad54[0x68 - 0x54];
    CAMHOLD *pcam;
};
struct CPDEFI { int grf; char pad[0x30 - 4]; float radYaw; int unk34; char pad38[4]; int fCut; };
union VU_SCALE { QW q; VECTOR v; };
struct MATRIX { QW row0; QW row1; };
extern float g_2dded4;
extern SMP D_002BF348;
extern "C" float RadYawSo(SO *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" float SMaxCrv(CRV *);
extern "C" float SMinCrv(CRV *);
extern "C" void GetPathPosFromS(CRV *, float, QW *, int);
extern "C" QW PosLoWorld(SO *);
extern "C" MATRIX *PmatLoWorld(SO *);
float GSmooth(float, float, float, SMP *, float *);

static inline float GClamp01(float g)
{
    if (g < 0.0f)
        return 0.0f;
    if (1.0f < g)
        return 1.0f;
    return g;
}

void GetAttachCpdefi(ATTACH *pattach, CPDEFI *pcpdefi)
{
    VU_SCALE tmp0;
    if (pattach->state != 0)
        return;
    pcpdefi->radYaw = RadYawSo(pattach->pso);
    if (pattach->pso->pvCam != pattach->pcam)
        return;
    pcpdefi->unk34 = 0;
    int dir = pattach->dir;
    if (dir < 3) {
        if (dir > 0) {
            if (FIsBasicDerivedFrom(pattach->pcrv, 0xC)) {
                CRV *pcrv = pattach->pcrv;
                float s;
                if (pattach->dir == 1) {
                    s = pattach->s + pattach->speed * (pattach->speed * 125.0f);
                    if (!pcrv->fClosed) {
                        float sMax = SMaxCrv(pcrv);
                        if (pcrv->grfCrv & 2)
                            sMax += 100.0f;
                        s = sMax < s ? sMax : s;
                    }
                } else {
                    s = pattach->s - pattach->speed * (pattach->speed * 125.0f);
                    if (!pcrv->fClosed) {
                        float sMin = SMinCrv(pcrv);
                        if (pcrv->grfCrv & 1)
                            sMin -= 100.0f;
                        s = sMin > s ? sMin : s;
                    }
                }
                GetPathPosFromS(pcrv, s, (QW *)&pattach->posTarget, 0);
                pattach->posTarget.z += 125.0f;
            } else {
                if (pattach->dir == 1) {
                    QW posBase = PosLoWorld(pattach->pso);
                    VU_SCALE scale;
                    tmp0.q = scale.q = VectorFromFloat(pattach->speed * (pattach->speed * 125.0f));
                    MATRIX *pmat = PmatLoWorld(pattach->pso);
                    *(QW *)&pattach->posTarget = VectorAdd(posBase, VectorScaleX(pmat->row1, scale.q));
                } else {
                    QW posBase = PosLoWorld(pattach->pso);
                    VU_SCALE scale;
                    tmp0.q = scale.q = VectorFromFloat(pattach->speed * (pattach->speed * 125.0f));
                    MATRIX *pmat = PmatLoWorld(pattach->pso);
                    *(QW *)&pattach->posTarget = VectorSub(posBase, VectorScaleX(pmat->row1, scale.q));
                }
                pattach->posTarget.z += 50.0f;
            }
        } else if (dir == 0) {
            *(QW *)&pattach->posTarget = PosLoWorld(pattach->pso);
            pattach->posTarget.z += 50.0f;
        }
    }
    if (FIsBasicDerivedFrom(pattach->pcrv, 0xC) && !pattach->pcrv->fClosed) {
        float sEdge = 30.0f;
        float sMax = SMaxCrv(pattach->pcrv) - sEdge;
        float sRamp = (sMax - sEdge) * 0.5f;
        sRamp = sRamp < 300.0f ? sRamp : 300.0f;
        float s = pattach->s;
        float gTarget;
        if (s < sRamp + sEdge) {
            float t = GClamp01((sRamp + sEdge - s) / sRamp);
            gTarget = -t * t * 150.0f;
        } else if (sMax - sRamp < s) {
            float t = GClamp01((s - (sMax - sRamp)) / sRamp);
            gTarget = t * t * 150.0f;
        } else {
            gTarget = 0.0f;
        }
        pattach->pcam->psm->g = GSmooth(pattach->pcam->psm->g, gTarget, g_2dded4, &D_002BF348, 0);
    }
    switch (pattach->state) {
    case 0:
    case 13:
        pcpdefi->fCut = 1;
        break;
    case 1:
    case 3:
    case 4:
        break;
    default:
        pcpdefi->grf |= 1;
        break;
    }
}
