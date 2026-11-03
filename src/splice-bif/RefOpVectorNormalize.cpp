// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
int CRef_ConstructVector(CRef *, QW *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
extern QW g_2a2dd0;
}
// lane 0 of a QW as a float
static inline float LaneZero(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline QW Length_1229B8(QW v)
{
    QW sq, one, len;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(sq), "=j"(one) : "j"(v));
    asm("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "=j"(len) : "j"(sq));
    return len;
}
extern "C" CRef *RefOpVectorNormalize(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refNormal;
    CRef_ConstructVector(&refNormal, aref[0].pv);
    if (aref[1].tagk == 0) {
        QW *pvec = refNormal.pv;
        QW *pzero = &g_2a2dd0;
        float gEpsilon = 0.0001f;
        QW vec = *pvec;
        QW v;
        asm("qmtc2.ni %1, %0" : "=j"(v) : "r"(vec));
        QW len = Length_1229B8(v);
        if (LaneZero(len) < gEpsilon) {
            *pvec = *pzero;
        } else {
            QW r;
            asm("vdiv Q, vf0w, %2x\n\tvwaitq\n\tvmulq.xyzw %0, %1, Q" : "=j"(r) : "j"(v), "j"(len));
            *pvec = r;
        }
    } else {
        QW *pvec = refNormal.pv;
        float gEpsilon = 0.0001f;
        QW v = *pvec;
        QW len = Length_1229B8(v);
        float length = LaneZero(len);
        QW *pdefault = ((CPair *)aref[1].n)->ref.pv;
        if (length < gEpsilon) {
            *pvec = *pdefault;
        } else {
            QW r;
            asm("vdiv Q, vf0w, %2x\n\tvwaitq\n\tvmulq.xyzw %0, %1, Q" : "=j"(r) : "j"(v), "j"(len));
            *pvec = r;
        }
    }
    CRef_CopyConstruct(pret, &refNormal);
    CRef_Destruct(&refNormal);
    return pret;
}
