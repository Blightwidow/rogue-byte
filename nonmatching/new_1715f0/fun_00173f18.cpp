#include "sly2.h"

// lane 0 of a QW into an FP register (mtc1 reads the low word)
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }

struct POINT_173F18 { int kind; int pad4; char *plo; int padC; int pad10; int fBusy; float tReady; };
struct SPAWNER_173F18 {
    char pad0[0x50];
    int cpoint;
    POINT_173F18 *apoint;
    char pad58[0x38];
    int ctemplate;
    char **atemplate;
    int coffset;
    QW *aoffset;
};
struct PATH_173F18 { QW pos; QW dir; QW scale; };
struct FRAME_173F18 {
    char aframe[0x10];
    QW posBest;
    QW matBest[3];
    union {
        QW mat[3];
        PATH_173F18 path;
    } u;
    QW matPath[3];
    int cso;
    int aso;
};

extern "C" {
extern const float RO_002A53E0;
extern float g_2dded0[1];
extern float D_002BE5E4;
extern float D_002BE5E8;
extern float g_2bbb60[2];
extern QW g_2a2dc0;
extern char B_002DDF40[];
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void func_001B44D8(int *, int *);
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
float SMaxCrv(void *);
float GRandInRange(float, float);
void *PgFindCrvExcludedRange(float, void *);
void GetPathPosFromS(float, void *, QW *, QW *);
float atan2f(float, float);
void LoadRotateMatrixRad(QW *, QW, float);
int func_00173768(void *, QW, int, int, float);
}

extern "C" POINT_173F18 *func_00173F18(SPAWNER_173F18 *pspawner, QW posFocus, QW *ppos, QW *pmat, unsigned *pfFlip)
{
    float sRadiusMin = RO_002A53E0;
    for (int itemplate = 0; itemplate < pspawner->ctemplate; itemplate++) {
        float sRadius = *(float *)(pspawner->atemplate[itemplate] + 0x38);
        sRadiusMin = sRadiusMin < sRadius ? sRadiusMin : sRadius;
    }
    FRAME_173F18 fr;
    unsigned fFlipBest = 0;
    CStackFrame_Construct(fr.aframe);
    func_001B44D8(&fr.cso, &fr.aso);
    POINT_173F18 *ppointBest = 0;
    float sBest = RO_002A53E0;
    for (int ipoint = 0; ipoint < pspawner->cpoint; ipoint++) {
        POINT_173F18 *ppoint = &pspawner->apoint[ipoint];
        if (ppoint->fBusy != 0)
            continue;
        if (g_2dded0[0] < ppoint->tReady)
            continue;
        char *plo = ppoint->plo;
        if (plo == 0)
            continue;
        if (((*(unsigned long *)(plo + 0x28) >> 60) & 1) == 0)
            continue;
        switch (ppoint->kind) {
        case 0:
        case 2: {
            QW pos;
            float sRadius;
            switch (ppoint->kind) {
            case 0: {
                pos = PosLoWorld(ppoint->plo);
                QW *pm = PmatLoWorld(ppoint->plo);
                fr.u.mat[0] = pm[0];
                fr.u.mat[1] = pm[1];
                fr.u.mat[2] = pm[2];
                sRadius = *(float *)(ppoint->plo + 0x38);
                break;
            }
            case 2: {
                sRadius = sRadiusMin;
                pos = PosLoWorld(ppoint->plo);
                QW *pm = PmatLoWorld(ppoint->plo);
                fr.u.mat[0] = pm[0];
                fr.u.mat[1] = pm[1];
                fr.u.mat[2] = pm[2];
                break;
            }
            }
            float s;
            {
                asm("qmtc2.ni %0, vf2" : : "r"(posFocus));
                asm("qmtc2.ni %0, vf3" : : "r"(pos));
                asm("vsub.xyzw vf1, vf2, vf3");
                asm("vmul.xy vf1, vf1, vf1");
                asm("vaddy.x vf1, vf1, vf1y");
                asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                QW bits;
                asm("qmfc2.ni %0, vf1" : "=r"(bits));
                s = LaneX(bits);
            }
            if (s < D_002BE5E4)
                continue;
            if (sBest < s)
                continue;
            for (int ioffset = 0; ioffset < pspawner->coffset; ioffset++) {
                QW posTest;
                {
                    asm("lqc2 vf1, %0" : : "m"(fr.u.mat[2]));
                    asm("lqc2 vf4, %0" : : "m"(fr.u.mat[0]));
                    asm("lqc2 vf3, %0" : : "m"(fr.u.mat[1]));
                    asm("lqc2 vf2, %0" : : "m"(pspawner->aoffset[ioffset]));
                    asm("vmulax.xyz ACC, vf4, vf2x\n\tvmadday.xyz ACC, vf3, vf2y\n\tvmaddz.xyz vf2, vf1, vf2z");
                    asm("qmtc2.ni %0, vf1" : : "r"(pos));
                    asm("vadd.xyzw vf1, vf1, vf2");
                    asm("qmfc2.ni %0, vf1" : "=r"(posTest));
                }
                if (func_00173768(pspawner, posTest, fr.cso, fr.aso, sRadius) == 0)
                    goto LNextPoint;
            }
            sBest = s;
            fr.matBest[0] = fr.u.mat[0];
            fr.matBest[1] = fr.u.mat[1];
            fr.matBest[2] = fr.u.mat[2];
            ppointBest = ppoint;
            fr.posBest = pos;
            break;
        }
        case 1: {
            int csample = (int)(SMaxCrv(plo) / D_002BE5E8);
            for (int isample = 0; isample < csample; isample++) {
                float sAlong = D_002BE5E8 * ((float)isample + GRandInRange(g_2bbb60[0], g_2bbb60[1]));
                if (PgFindCrvExcludedRange(sAlong, *(void **)(plo + 0x180)) != 0)
                    continue;
                GetPathPosFromS(sAlong, plo, &fr.u.path.pos, &fr.u.path.dir);
                float s;
                {
                    asm("lqc2 vf1, %0" : : "m"(fr.u.path.pos));
                    asm("qmtc2.ni %0, vf2" : : "r"(posFocus));
                    asm("vsub.xyzw vf1, vf1, vf2");
                    asm("vmul.xy vf1, vf1, vf1");
                    asm("vaddy.x vf1, vf1, vf1y");
                    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                    QW bits;
                    asm("qmfc2.ni %0, vf1" : "=r"(bits));
                    s = LaneX(bits);
                }
                if (s < D_002BE5E4)
                    continue;
                if (sBest < s)
                    continue;
                unsigned fFlip;
                {
                    asm("lqc2 vf3, %0" : : "m"(fr.u.path.dir));
                    asm("lqc2 vf1, %0" : : "m"(*(QW *)(B_002DDF40 + 0x60)));
                    asm("vmul.xyz vf1, vf1, vf3");
                    asm("vaddw.x vf2, vf0, vf0w");
                    asm("vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
                    QW bits;
                    asm("qmfc2.ni %0, vf1" : "=r"(bits));
                    fFlip = LaneX(bits) < 0.0f;
                    if (!fFlip) {
                        asm("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
                        asm("vmulx.xyzw vf2, vf3, vf1x");
                        asm("sqc2 vf1, %0" : "=m"(fr.u.path.scale));
                        asm("sqc2 vf2, %0" : "=m"(fr.u.path.dir));
                    }
                }
                int ioffset = 0;
                float angle = atan2f(((float *)&fr.u.path.dir)[1], ((float *)&fr.u.path.dir)[0]);
                LoadRotateMatrixRad(fr.matPath, g_2a2dc0, angle);
                for (; ioffset < pspawner->coffset; ioffset++) {
                    QW posTest;
                    {
                        asm("lqc2 vf1, %0" : : "m"(fr.matPath[2]));
                        asm("lqc2 vf5, %0" : : "m"(fr.matPath[0]));
                        asm("lqc2 vf4, %0" : : "m"(fr.matPath[1]));
                        asm("lqc2 vf3, %0" : : "m"(pspawner->aoffset[ioffset]));
                        asm("vmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf1, vf3z");
                        asm("lqc2 vf2, %0" : : "m"(fr.u.path.pos));
                        asm("vadd.xyzw vf1, vf2, vf3");
                        asm("qmfc2.ni %0, vf1" : "=r"(posTest));
                    }
                    if (func_00173768(pspawner, posTest, fr.cso, fr.aso, sRadiusMin) == 0)
                        break;
                }
                if (ioffset < pspawner->coffset)
                    continue;
                sBest = s;
                fr.posBest = fr.u.path.pos;
                fr.matBest[0] = fr.matPath[0];
                fr.matBest[1] = fr.matPath[1];
                fr.matBest[2] = fr.matPath[2];
                fFlipBest = fFlip;
                ppointBest = ppoint;
            }
            break;
        }
        }
    LNextPoint:;
    }
    *ppos = fr.posBest;
    pmat[0] = fr.matBest[0];
    pmat[1] = fr.matBest[1];
    pmat[2] = fr.matBest[2];
    *pfFlip = fFlipBest;
    CStackFrame_Destructor(fr.aframe, 2);
    return ppointBest;
}
