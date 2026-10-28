/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CRV { char pad[0xE4]; int closed; };
struct VJOY { char pad[0x10]; float xLeft; float yLeft; float radLeft; float sLeft; char pad2[0x30 - 0x20]; unsigned grfbtn; };
struct SEQNODE { char pad[0x40]; int *prec; char *pso; int stat48; char pad2[0x78 - 0x4C]; float uGoal; float sGoal; };
extern "C" float atan2f(float, float);
extern "C" float RadNormalize__Ff(float);
extern "C" int FFloatsNear__Ffff(float, float, float);
extern "C" float SMaxCrv(CRV *);
extern "C" float UMaxCrv(CRV *);
extern "C" float func_001E6728(CRV *, float);
extern "C" void GetPathPosFromS(CRV *, void *, int, float);
extern "C" void EvaluateCrvFromU(CRV *, void *, void *, float);
extern "C" QW bevy_player_p14_1c4768(VJOY *, QW);
extern "C" void *PloFindSeqnodeObject(SEQNODE *, int);
extern "C" void GetSeqnodeObjectPosRad(SEQNODE *, void *, void *, void *);
extern "C" void SetStepRadTarget(void *, float);
extern "C" QW PosLoWorld(void *);
extern "C" QW bevy_camera_follow_track_heading_weight(void *, void *, QW);
extern "C" void UpdateVjoyPressTimes(VJOY *);
extern "C" QW g_2a2da0;
extern "C" float g_2c3630[3];
extern "C" float g_2bbb60[2];
extern "C" float g_2c3640;
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }

void UpdateSeqnodeVjoy(SEQNODE *pseqnode, VJOY *pvjoy)
{
    struct { QW q0; QW q1; QW q2; QW q3; QW q4; QW q5; } l;
    int *prec = pseqnode->prec;
    char *pso = pseqnode->pso;
    switch (prec[0]) {
    case 0x1a: {
        int fBackward = 0;
        float step = 50.0f;
        float ahead = func_001E6728(*(CRV **)(pso + 0xF5C), *(float *)(pso + 0xF60) + step);
        GetPathPosFromS(*(CRV **)(pso + 0xF5C), &l.q0, 0, ahead);
        float behind = func_001E6728(*(CRV **)(pso + 0xF5C), *(float *)(pso + 0xF60) - step);
        GetPathPosFromS(*(CRV **)(pso + 0xF5C), &l.q1, 0, behind);
        QW diff;
        asm volatile("lqc2 vf2, %0" : : "m" (l.q0));
        asm("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf2, vf1\n\tqmfc2.ni %0, vf3" : "=r" (diff) : "m" (l.q1));
        QW dir = bevy_player_p14_1c4768(pvjoy, diff);
        float x = Lane(dir);
        float y = Lane(__builtin_prot3w(dir));
        pvjoy->radLeft = atan2f(y, x);
        pvjoy->xLeft = x;
        pvjoy->yLeft = y;
        CRV *pcrv = *(CRV **)(pso + 0xF5C);
        if (pcrv->closed != 0) {
            float sBackward, sForward;
            if (pseqnode->sGoal < *(float *)(pso + 0xF60)) {
                sBackward = *(float *)(pso + 0xF60) - pseqnode->sGoal;
                sForward = (SMaxCrv(pcrv) + pseqnode->sGoal) - *(float *)(pso + 0xF60);
            } else {
                sForward = pseqnode->sGoal - *(float *)(pso + 0xF60);
                sBackward = (SMaxCrv(pcrv) + *(float *)(pso + 0xF60)) - pseqnode->sGoal;
            }
            if (sBackward < sForward)
                fBackward = 1;
        } else {
            if (pseqnode->sGoal < *(float *)(pso + 0xF60))
                fBackward = 1;
        }
        if (fBackward) {
            pvjoy->radLeft = RadNormalize__Ff(pvjoy->radLeft + 3.1415927f);
            pvjoy->xLeft = -pvjoy->xLeft;
            pvjoy->yLeft = -pvjoy->yLeft;
        }
        pvjoy->sLeft = 1.0f;
        break;
    }
    case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22:
    group:
        pvjoy->sLeft = 0.0f;
        if (*(int *)(pso + 0x4CC) != -1)
            pvjoy->grfbtn |= 0x20;
        break;
    case 0x23: {
        void *ptarget = PloFindSeqnodeObject(pseqnode, prec[5]);
        if (ptarget != 0) {
            GetSeqnodeObjectPosRad(pseqnode, ptarget, 0, &l.q3);
            SetStepRadTarget(pso, *(float *)&l.q3);
            pvjoy->radLeft = *(float *)&l.q3;
        }
    }
        goto group;
    case 0x24: {
        pvjoy->sLeft = __builtin_fabsf(((float *)prec)[5]);
        if (prec[9] != 0)
            pvjoy->grfbtn |= 8;
        void *ptarget = PloFindSeqnodeObject(pseqnode, prec[4]);
        if (ptarget != 0) {
            if (*(int *)(pso + 0x4CC) != -1 && *(int *)(pso + 0x4C8) == 3) {
                CRV *pcrv = *(CRV **)(pso + 0x4D4);
                EvaluateCrvFromU(pcrv, &l.q0, &l.q1, *(float *)(pso + 0x4DC));
                ((int *)&l.q1)[2] = 0;
                float eps = 0.0001f;
                QW *pdflt = &g_2a2da0;
                QW lenWord;
                asm volatile("lqc2 vf3, %0\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z"
                    : : "m" (l.q1));
                QW dflt = *pdflt;
                asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (lenWord));
                if (Lane(lenWord) < eps)
                    asm volatile("qmtc2.ni %0, vf1" : : "r" (dflt));
                else
                    asm volatile("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
                asm volatile("sqc2 vf1, %0" : "=m" (l.q1));
                int fBackward = 0;
                pvjoy->radLeft = atan2f(((float *)&l.q1)[1], ((float *)&l.q1)[0]);
                if (pcrv->closed != 0) {
                    float uBackward, uForward;
                    if (pseqnode->uGoal < *(float *)(pso + 0x4DC)) {
                        uBackward = *(float *)(pso + 0x4DC) - pseqnode->uGoal;
                        uForward = (UMaxCrv(pcrv) + pseqnode->uGoal) - *(float *)(pso + 0x4DC);
                    } else {
                        uForward = pseqnode->uGoal - *(float *)(pso + 0x4DC);
                        uBackward = (UMaxCrv(pcrv) + *(float *)(pso + 0x4DC)) - pseqnode->uGoal;
                    }
                    if (uBackward < uForward)
                        fBackward = 1;
                } else {
                    if (pseqnode->uGoal < *(float *)(pso + 0x4DC))
                        fBackward = 1;
                }
                if (fBackward)
                    pvjoy->radLeft = RadNormalize__Ff(pvjoy->radLeft + 3.1415927f);
            } else {
                GetSeqnodeObjectPosRad(pseqnode, ptarget, &l.q0, 0);
                l.q4 = l.q0;
                QW posSo = PosLoWorld(pso);
                asm("qmtc2.ni %1, vf3\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m" (l.q1) : "r" (posSo), "m" (l.q4));
                pvjoy->radLeft = atan2f(((float *)&l.q1)[1], ((float *)&l.q1)[0]);
                QW lenWord;
                asm("lqc2 vf1, %1\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
                    : "=r" (lenWord) : "m" (l.q1));
                float len = Lane(lenWord);
                float gSpeed = g_2c3630[0] + len * (g_2c3630[1] + len * g_2c3630[2]);
                if (gSpeed < g_2bbb60[0])
                    gSpeed = g_2bbb60[0];
                else if (g_2bbb60[1] < gSpeed)
                    gSpeed = g_2bbb60[1];
                pvjoy->sLeft = pvjoy->sLeft * gSpeed;
            }
        }
        if (*(int *)(pso + 0x4CC) == -1)
            break;
        if (*(int *)(pso + 0x4C8) != 0 && *(int *)(pso + 0x4C8) != 0xD)
            break;
        pvjoy->grfbtn |= 0x20;
        break;
    }
    case 0x29: {
        pvjoy->sLeft = __builtin_fabsf(((float *)prec)[5]);
        void *ptarget = PloFindSeqnodeObject(pseqnode, prec[4]);
        if (ptarget == 0 || *(int *)(pso + 0x4CC) == -1)
            break;
        if (*(int *)(pso + 0x4C8) != 8)
            break;
        GetSeqnodeObjectPosRad(pseqnode, ptarget, &l.q0, 0);
        l.q5 = l.q0;
        QW posSo = PosLoWorld(pso);
        asm("lqc2 vf2, %2\n\tqmtc2.ni %1, vf3\n\tvsub.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m" (l.q1) : "r" (posSo), "m" (l.q5));
        ((int *)&l.q1)[2] = 0;
        QW local = bevy_camera_follow_track_heading_weight(0, pso, l.q1);
        float sLeft = pvjoy->sLeft;
        asm("qmtc2.ni %1, vf2\n\tvmul.xyz vf1, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\t"
            "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q\n\tsqc2 vf1, %0"
            : "=m" (l.q2) : "r" (local));
        float ux = ((float *)&l.q2)[0];
        float uy = -((float *)&l.q2)[1];
        pvjoy->yLeft = ux * sLeft;
        pvjoy->xLeft = uy * sLeft;
        break;
    }
    case 0x58:
        pvjoy->sLeft = 0.0f;
        pvjoy->grfbtn |= 0x20;
        UpdateVjoyPressTimes(pvjoy);
        goto tail;
    case 0x5a: {
        float eps = g_2c3640;
        QW b = *(QW *)(pso + 0x1A20);
        QW a = *(QW *)(pso + 0x19F0);
        register QW zeroReg asm("$0");
        int fNear = 0;
        if (FFloatsNear__Ffff(Lane(b), Lane(a), eps)
            && FFloatsNear__Ffff(Lane(__builtin_prot3w(b)), Lane(__builtin_prot3w(a)), eps))
            fNear = FFloatsNear__Ffff(Lane(__builtin_pextuw(zeroReg, b)), Lane(__builtin_pextuw(zeroReg, a)), eps) != 0;
        if (fNear)
            pvjoy->grfbtn |= 0x40;
        pvjoy->sLeft = 0.0f;
        UpdateVjoyPressTimes(pvjoy);
        goto tail;
    }
    case 0x2a:
        pvjoy->sLeft = 0.0f;
        break;
    case 0x50:
        pseqnode->stat48 = 1;
        break;
    case 0x51:
        pseqnode->stat48 = 0;
        break;
    default:
        break;
    }
tail:
    if (pseqnode->stat48 != 0) {
        pvjoy->grfbtn |= 0x10;
        if (prec[0] == 0x50)
            UpdateVjoyPressTimes(pvjoy);
    }
}
