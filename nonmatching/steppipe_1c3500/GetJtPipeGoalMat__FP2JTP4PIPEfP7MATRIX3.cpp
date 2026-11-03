// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
// lane 0 of a quadword to a float register, and a float to lane 0 of a quadword
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct JT { char pad[0xE4]; int fClosed; char pad1[0x1C0 - 0xE8]; QW heading; };
struct PIPE;
struct Rows_1C3500 { QW row[3]; };
extern "C" {
extern QW g_2a2da0;
extern QW g_2a2dc0;
float SMinCrv(JT *);
float SMaxCrv(JT *);
float UMinCrv(JT *);
void EvaluateCrvFromU(JT *, float, QW *, QW *);
float GModPositive__Fff(float, float);
float func_001E6728(JT *, float);
void GetPathPosFromS(JT *, float, QW *, int);
void BuildRotateVectorsMatrix(Rows_1C3500 *, QW, QW);
QW bevy_camera_follow_track_heading_weight(JT *, int, QW);
QW GetPerpendicularVector(QW);
}

// The fence outputs order the VU0 blocks, which share vf registers the compiler cannot see.
void GetJtPipeGoalMat(JT *pjt, PIPE *ppipe, float sGoal, MATRIX3 *pmat)
{
    struct {
        QW row[3];
        QW tangent;
        QW dirFirst;
        QW dir;
        QW posAhead;
        QW posBehind;
        Rows_1C3500 basis;
        Rows_1C3500 rot;
    } l;
    float sMin = SMinCrv(pjt);
    float sMax = SMaxCrv(pjt);
    EvaluateCrvFromU(pjt, UMinCrv(pjt), 0, &l.tangent);
    int fence;
    QW def = g_2a2da0;
    asm("lqc2 vf3, %1" : "=r"(fence) : "m"(l.tangent));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r"(fence));
    asm(".word 0x4A0103BD\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r"(fence)); // vsqrt Q, vf1x
    QW len;
    asm("qmfc2.ni %0, vf1" : "=r"(len) : "r"(fence));
    if (Lane(len) < 0.0001f)
        asm("qmtc2.ni %1, vf1" : "+r"(fence) : "r"(def));
    else
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "+r"(fence));
    asm("sqc2 vf1, %0" : "=m"(l.tangent) : "r"(fence));
    int iTry;
    QW dirArg;
    int fence2;
    for (iTry = 0;; iTry++) {
        float offset;
        if (iTry & 1)
            offset = 10.0f * (float)(iTry + 1);
        else
            offset = (float)iTry * -10.0f;
        float s = sGoal + offset;
        if (pjt->fClosed == 0) {
            if (s < sMin)
                continue;
            if (sMax < sGoal)
                continue;
        } else {
            s = sMin + GModPositive__Fff(s - sMin, sMax - sMin);
        }
        float delta = 50.0f;
        GetPathPosFromS(pjt, func_001E6728(pjt, s + delta), &l.posAhead, 0);
        GetPathPosFromS(pjt, func_001E6728(pjt, s - delta), &l.posBehind, 0);
        QW def2 = g_2a2dc0;
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1" : "=r"(fence2) : "m"(l.posAhead), "m"(l.posBehind));
        asm("vmul.xyz vf2, vf3, vf3\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z" : "+r"(fence2));
        asm(".word 0x4A0203BD\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r"(fence2)); // vsqrt Q, vf2x
        QW len2;
        asm("qmfc2.ni %0, vf1" : "=r"(len2) : "r"(fence2));
        if (Lane(len2) < 0.0001f)
            asm("qmtc2.ni %1, vf1" : "+r"(fence2) : "r"(def2));
        else
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "+r"(fence2));
        asm("sqc2 vf1, %1" : "+r"(fence2), "=m"(l.dir));
        if (iTry == 0)
            asm("sqc2 vf1, %1" : "+r"(fence2), "=m"(l.dirFirst));
        asm("lqc2 vf3, %1\n\tlqc2 vf4, %2\n\tvmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z"
            : "+r"(fence2) : "m"(l.tangent), "m"(l.dir));
        QW dot;
        asm("qmfc2.ni %0, vf2" : "=r"(dot) : "r"(fence2));
        float cosine;
        asm("mtc1 %2, %0" : "=f"(cosine), "=r"(fence2) : "r"(dot), "1"(fence2)); // lane 0
        asm("qmfc2.ni %0, vf4" : "=r"(dirArg) : "r"(fence2));
        if (cosine > -0.9f)
            break;
    }
    QW tangentArg;
    asm("qmfc2.ni %0, vf3" : "=r"(tangentArg) : "r"(fence2));
    BuildRotateVectorsMatrix(&l.rot, tangentArg, dirArg);
    l.basis = l.rot;
    QW heading = bevy_camera_follow_track_heading_weight(pjt, 0, pjt->heading);
    int fence3;
    QW def3 = g_2a2dc0;
    asm("lqc2 vf5, %1" : "=r"(fence3) : "m"(l.dirFirst));
    asm("vmul.xyz vf1, vf5, vf5\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r"(fence3));
    asm(".word 0x4A0103BD\n\tvwaitq\n\tvaddq.x vf6, vf0, Q" : "+r"(fence3)); // vsqrt Q, vf1x
    asm("lqc2 vf4, %1" : "+r"(fence3) : "m"(l.basis.row[0]));
    QW len3;
    asm("qmfc2.ni %0, vf6" : "=r"(len3) : "r"(fence3));
    asm("lqc2 vf3, %1\n\tlqc2 vf1, %2" : "+r"(fence3) : "m"(l.basis.row[1]), "m"(l.basis.row[2]));
    asm("qmtc2.ni %1, vf7" : "+r"(fence3) : "r"(heading));
    asm("vmulax.xyz ACC, vf4, vf7x\n\tvmadday.xyz ACC, vf3, vf7y\n\tvmaddz.xyz vf2, vf1, vf7z" : "+r"(fence3));
    asm("sqc2 vf2, %1" : "+r"(fence3), "=m"(l.posAhead));
    if (Lane(len3) < 0.0001f)
        asm("qmtc2.ni %1, vf4" : "+r"(fence3) : "r"(def3));
    else
        asm("vdiv Q, vf0w, vf6x\n\tvwaitq\n\tvmulq.xyzw vf4, vf5, Q" : "+r"(fence3));
    asm("lqc2 vf1, %1\n\tvopmula.xyz ACC, vf4, vf1\n\tvopmsub.xyz vf1, vf1, vf4" : "+r"(fence3) : "m"(l.posAhead));
    asm("vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "+r"(fence3));
    asm("sqc2 vf1, %1" : "+r"(fence3), "=m"(l.row[1]));
    asm(".word 0x4A0203BD\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "+r"(fence3)); // vsqrt Q, vf2x
    asm("sqc2 vf4, %1" : "+r"(fence3), "=m"(l.row[2]));
    QW len4;
    asm("qmfc2.ni %0, vf2" : "=r"(len4) : "r"(fence3));
    float length4 = Lane(len4);
    asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q" : "+r"(fence3));
    asm("sqc2 vf2, %1" : "+r"(fence3), "=m"(l.row[1]));
    asm("sqc2 vf1, %1" : "+r"(fence3), "=m"(l.posBehind));
    if (length4 < 0.0001f) {
        QW normal;
        asm("qmfc2.ni %0, vf4" : "=r"(normal) : "r"(fence3));
        l.row[1] = GetPerpendicularVector(normal);
    }
    int fence4;
    asm("lqc2 vf4, %1\n\tlqc2 vf2, %2\n\tvopmula.xyz ACC, vf4, vf2\n\tvopmsub.xyz vf1, vf2, vf4" : "=r"(fence4) : "m"(l.row[1]), "m"(l.row[2]));
    asm("sqc2 vf1, %1" : "+r"(fence4), "=m"(l.row[0]));
    if (ppipe == 0) {
        asm("qmtc2.ni %1, vf1" : "+r"(fence4) : "r"(Word(-1.0f)));
        asm("vmulx.xyzw vf3, vf2, vf1x" : "+r"(fence4));
        asm("sqc2 vf1, %1" : "+r"(fence4), "=m"(l.posBehind));
        asm("vmulx.xyzw vf2, vf4, vf1x" : "+r"(fence4));
        asm("sqc2 vf3, %1" : "+r"(fence4), "=m"(l.row[2]));
        asm("sqc2 vf2, %1" : "+r"(fence4), "=m"(l.row[1]));
    }
    if (pmat != 0) {
        QW *prow = (QW *)pmat;
        prow[0] = l.row[0];
        prow[1] = l.row[1];
        prow[2] = l.row[2];
    }
}
