#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct CPDEFI;
struct TNFNELEM { int cid; char pad[0x8C]; };
struct TN {
    int unused0[0x43];
    void *pcrv;
    int ctnfn;
    TNFNELEM *atnfn;
    char pad_118[0x14];
    int fFakeCylinder;
    char pad_130[0x10];
    float sClosest;
    char pad_144[0x40];
    int unused184;
    float f188;
};
struct CM {
    char pad0[0x24];
    float f24;
    char pad1[0x24];
    float f4C;
    char pad2[0x40];
    QW pos90;
    char pad3[0x240];
    QW pos2E0;
};
struct CPTN {
    int vt;
    char pad_4[0xC];
    TN *ptn;
    TNFNELEM *ptnfn;
    float yaw;
    float pitch;
    float dist;
    float f24;
    char pad_28[0xC];
    int f34;
    int fActive;
    int f3C;
    char pad_40[0x8];
    float f48;
    char pad_4c[0x14];
    float f60;
    char pad_64[0xC];
    QW posSphere;
    float f80;
};
extern "C" {
void ActivateCplcy(CPTN *, void *);
void UpdateStepXfWorld__FP4STEP(TNFNELEM *);
void GetCmCpdefi__FP2CMP2SOfP6CPDEFI(CM *, void *, CPDEFI *);
void GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(TNFNELEM *, CPDEFI *, QW *, TN *);
int FIsBasicDerivedFrom(void *, int);
int FIsCidDerivedFrom(int, int);
void FindCrvClosestPointAll(void *, QW, int, QW *, int, int, float *);
void UpdateCptnClosestPoint(CPTN *, CPDEFI *);
void DecomposeSphere(QW, float *, float *, float *);
QW SetVectorSphere__FP6VECTORfff(float, float, float);
int SetResetFlag__FP2CM(CM *);
extern CM B_002DDF40;
extern TNFNELEM D_002C4120;
extern float D_FLT_002C41DC;
extern float g_2dded0;
}
extern "C" void ActivateCptn__FP4CPTNPv(CPTN *pcptn, void *pso, TN *ptn)
{
    char cpdefi[0x50];
    QW nose[1];
    QW closest[1];
    QW sum[1];
    ActivateCplcy(pcptn, pso);
    pcptn->ptn = ptn;
    if (ptn == 0) {
        pcptn->ptnfn = &D_002C4120;
    } else {
        TNFNELEM *pbest = ptn->atnfn;
        for (int index = 1; index < ptn->ctnfn; index++) {
            TNFNELEM *ptnfn = &pcptn->ptn->atnfn[index];
            if (FIsBasicDerivedFrom(pso, ptnfn->cid)) {
                if (FIsCidDerivedFrom(ptnfn->cid, pbest->cid))
                    pbest = ptnfn;
            }
        }
        pcptn->ptnfn = pbest;
    }
    pcptn->fActive = 1;
    UpdateStepXfWorld__FP4STEP(pcptn->ptnfn);
    GetCmCpdefi__FP2CMP2SOfP6CPDEFI(&B_002DDF40, pso, (CPDEFI *)cpdefi);
    GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(pcptn->ptnfn, (CPDEFI *)cpdefi, nose, 0);
    TN *ptnNow = pcptn->ptn;
    if (ptnNow) {
        if (ptnNow->pcrv) {
            FindCrvClosestPointAll(ptnNow->pcrv, nose[0], 0, closest, 0, 0, &ptnNow->sClosest);
        } else if (ptnNow->fFakeCylinder) {
            UpdateCptnClosestPoint(pcptn, (CPDEFI *)cpdefi);
        }
        GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(pcptn->ptnfn, (CPDEFI *)cpdefi, nose, pcptn->ptn);
    }
    CM *pcm = &B_002DDF40;
    sum[0] = VectorAdd(nose[0], pcm->pos2E0);
    DecomposeSphere(VectorSub(pcm->pos90, sum[0]), &pcptn->yaw, &pcptn->pitch, &pcptn->dist);
    pcptn->dist = pcptn->dist - pcm->f4C;
    pcptn->posSphere = VectorAdd(sum[0], SetVectorSphere__FP6VECTORfff(pcptn->yaw, pcptn->pitch, pcptn->dist));
    pcptn->f34 = 0;
    pcptn->f24 = *(float *)((char *)pcptn->ptnfn + 0x5C);
    if (pcptn->ptn) {
        if (pcptn->ptn->unused184)
            SetResetFlag__FP2CM(pcm);
    }
    pcptn->f80 = g_2dded0;
    TN *ptnLast = pcptn->ptn;
    pcptn->f60 = g_2dded0;
    pcptn->f3C = 0;
    *(float *)((char *)pcptn + 0x48) = g_2dded0 - D_FLT_002C41DC;
    if (ptnLast) {
        float f188 = ptnLast->f188;
        if (f188 != 0.0f)
            B_002DDF40.f24 = f188;
    }
}
