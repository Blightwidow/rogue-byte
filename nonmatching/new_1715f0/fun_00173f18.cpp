#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct POINT { int kind; int pad4; char *plo; int pad0C; int pad10; int fBusy; float tReady; };
struct SPAWNER { char pad0[0x50]; int cpoint; POINT *apoint; char pad58[0x38]; int ctemplate; char **atemplate; int coffset; QW *aoffset; };
extern "C" const float RO_FLT_002A53E0;
extern "C" float g_2dded0[1];
extern "C" float D_FLT_002BE5E4;
extern "C" float D_FLT_002BE5E8;
extern "C" float g_2bbb60[2];
extern "C" QW g_2a2dc0;
extern "C" char B_002DDF40[];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void func_001B44D8(int *, int *);
extern "C" QW PosLoWorld(void *);
extern "C" QW *PmatLoWorld(void *);
extern "C" float SMaxCrv(void *);
extern "C" float GRandInRange(float, float);
extern "C" void *PgFindCrvExcludedRange(float, void *);
extern "C" void GetPathPosFromS(float, void *, QW *, QW *);
extern "C" float atan2f(float, float);
extern "C" void LoadRotateMatrixRad(QW *, QW, float);
extern "C" int func_00173768(void *, QW, int, int, float);
#define aframe (fr)
#define posBest (*(QW *)(fr + 0x10))
#define matBest ((QW *)(fr + 0x20))
#define mat0 ((QW *)(fr + 0x50))
#define pos1 (*(QW *)(fr + 0x50))
#define dir1 (*(QW *)(fr + 0x60))
#define mat1 ((QW *)(fr + 0x80))
#define cso (*(int *)(fr + 0xB0))
#define aso (*(int *)(fr + 0xB4))
extern "C" POINT *func_00173F18(SPAWNER *pspawner, QW posFocus, QW *ppos, QW *pmat, unsigned *pfFlip)
{
    float sRadiusMin = RO_FLT_002A53E0;
    for (int itemplate = 0; itemplate < pspawner->ctemplate; itemplate++) {
        float sRadius = *(float *)(pspawner->atemplate[itemplate] + 0x38);
        sRadiusMin = sRadius < sRadiusMin ? sRadius : sRadiusMin;
    }
    char fr[0xB8] __attribute__((aligned(16)));
    POINT *ppointBest;
    unsigned fFlipBest;
    fFlipBest = 0;
    CStackFrame_Construct(aframe);
    func_001B44D8(&cso, &aso);
    ppointBest = 0;
    float sBest = RO_FLT_002A53E0;
    for (int ipoint = 0; ipoint < pspawner->cpoint; ipoint++) {
        POINT *ppoint = &pspawner->apoint[ipoint];
        if (ppoint->fBusy != 0) continue;
        if (g_2dded0[0] < ppoint->tReady) continue;
        char *plo = ppoint->plo;
        if (plo == 0) continue;
        if (((*(unsigned long *)(plo + 0x28) >> 60) & 1) == 0) continue;
        switch (ppoint->kind) {
        case 0:
        case 2:
        {
            QW pos;
            float sRadius;
            if (ppoint->kind == 0) {
                pos = PosLoWorld(plo);
                QW *pm = PmatLoWorld(plo);
                mat0[0] = pm[0];
                mat0[1] = pm[1];
                mat0[2] = pm[2];
                sRadius = *(float *)(plo + 0x38);
            } else {
                sRadius = sRadiusMin;
                pos = PosLoWorld(plo);
                QW *pm = PmatLoWorld(plo);
                mat0[0] = pm[0];
                mat0[1] = pm[1];
                mat0[2] = pm[2];
            }
            QW diff, len;
            asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tvsub.xyzw vf1, vf2, vf3\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (len) : "m" (posFocus), "m" (pos));
            float s = Lane(len);
            if (s < D_FLT_002BE5E4) continue;
            if (sBest < s) continue;
            int ioffset;
            for (ioffset = 0; ioffset < pspawner->coffset; ioffset++) {
                QW p;
                asm("lqc2 vf1, %3\n\tlqc2 vf4, %1\n\tlqc2 vf3, %2\n\tlqc2 vf2, %4\n\tvmulax.xyz ACC, vf4, vf2x\n\tvmadday.xyz ACC, vf3, vf2y\n\tvmaddz.xyz vf2, vf1, vf2z\n\tlqc2 vf1, %5\n\tvadd.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (p) : "m" (mat0[0]), "m" (mat0[1]), "m" (mat0[2]), "m" (pspawner->aoffset[ioffset]), "m" (pos));
                if (func_00173768(pspawner, p, cso, aso, sRadius) == 0) break;
            }
            if (ioffset < pspawner->coffset) continue;
            sBest = s;
            matBest[0] = mat0[0];
            matBest[1] = mat0[1];
            matBest[2] = mat0[2];
            ppointBest = ppoint;
            posBest = pos;
            break;
        }
        case 1:
        {
            int csample = (int)(SMaxCrv(plo) / D_FLT_002BE5E8);
            for (int isample = 0; isample < csample; isample++) {
                float sAlong = D_FLT_002BE5E8 * ((float)isample + GRandInRange(g_2bbb60[0], g_2bbb60[1]));
                if (PgFindCrvExcludedRange(sAlong, *(void **)(plo + 0x180)) != 0) continue;
                GetPathPosFromS(sAlong, plo, &pos1, &dir1);
                QW len;
                asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (len) : "m" (pos1), "m" (posFocus));
                float s = Lane(len);
                if (s < D_FLT_002BE5E4) continue;
                if (sBest < s) continue;
                QW dot;
                asm("lqc2 vf3, %1\n\tlqc2 vf1, %2\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dot) : "m" (dir1), "m" (*(QW *)(B_002DDF40 + 0x60)));
                unsigned fFlip = Lane(dot) < 0.0f;
                if (!fFlip) {
                    QW spill;
                    asm("lui $2, 0xBF80\n\tqmtc2.ni $2, vf1\n\tlqc2 vf3, %1\n\tvmulx.xyzw vf2, vf3, vf1x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %1" : "=m" (spill), "+m" (dir1) : : "$2");
                }
                LoadRotateMatrixRad(mat1, g_2a2dc0, atan2f(((float *)&dir1)[1], ((float *)&dir1)[0]));
                int ioffset;
                for (ioffset = 0; ioffset < pspawner->coffset; ioffset++) {
                    QW p;
                    asm("lqc2 vf1, %3\n\tlqc2 vf5, %1\n\tlqc2 vf4, %2\n\tlqc2 vf3, %4\n\tvmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf1, vf3z\n\tlqc2 vf2, %5\n\tvadd.xyzw vf1, vf2, vf3\n\tqmfc2.ni %0, vf1" : "=r" (p) : "m" (mat1[0]), "m" (mat1[1]), "m" (mat1[2]), "m" (pspawner->aoffset[ioffset]), "m" (pos1));
                    if (func_00173768(pspawner, p, cso, aso, sRadiusMin) == 0) break;
                }
                if (ioffset < pspawner->coffset) continue;
                sBest = s;
                posBest = pos1;
                matBest[0] = mat1[0];
                matBest[1] = mat1[1];
                matBest[2] = mat1[2];
                fFlipBest = fFlip;
                ppointBest = ppoint;
            }
            break;
        }
        default:
            break;
        }
    }
    *ppos = posBest;
    pmat[0] = matBest[0];
    pmat[1] = matBest[1];
    pmat[2] = matBest[2];
    *pfFlip = fFlipBest;
    CStackFrame_Destructor(aframe, 2);
    return ppointBest;
}
