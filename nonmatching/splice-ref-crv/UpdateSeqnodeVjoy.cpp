/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
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

void UpdateSeqnodeVjoy(SEQNODE *pseqnode, VJOY *pvjoy)
{
    struct { QW q0; QW q1; QW q2; QW q3; } l;
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
        QW dir = bevy_player_p14_1c4768(pvjoy, VectorSub(l.q0, l.q1));
        float x = LaneX(dir);
        float y = LaneX(RotateWords3(dir));
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
                QW tangent = l.q1;
                QW dflt = g_2a2da0;
                QW length = SqrtX(SquaredLength(tangent));
                if (LaneX(length) < eps)
                    l.q1 = dflt;
                else
                    l.q1 = ScaleByReciprocalX(tangent, length);
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
                QW posTarget = l.q0;
                QW posSo = PosLoWorld(pso);
                l.q1 = VectorSub(posTarget, posSo);
                pvjoy->radLeft = atan2f(((float *)&l.q1)[1], ((float *)&l.q1)[0]);
                float len = LaneX(SqrtX(SquaredLengthXy(l.q1)));
                float gSpeed = g_2c3630[0] + len * (g_2c3630[1] + len * g_2c3630[2]);
                float gMin = g_2bbb60[0];
                float gMax = g_2bbb60[1];
                if (gSpeed < gMin)
                    gSpeed = gMin;
                else if (gMax < gSpeed)
                    gSpeed = gMax;
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
        QW posTarget = l.q0;
        QW posSo = PosLoWorld(pso);
        l.q1 = VectorSub(posTarget, posSo);
        ((int *)&l.q1)[2] = 0;
        QW local = bevy_camera_follow_track_heading_weight(0, pso, l.q1);
        float sLeft = pvjoy->sLeft;
        l.q2 = ScaleByReciprocalX(local, SqrtX(SquaredLength(local)));
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
        int fNear = 0;
        if (FFloatsNear__Ffff(LaneX(b), LaneX(a), eps)
            && FFloatsNear__Ffff(LaneX(RotateWords3(b)), LaneX(RotateWords3(a)), eps))
            fNear = FFloatsNear__Ffff(LaneZInGeneralRegister(b), LaneZInGeneralRegister(a), eps) != 0;
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
