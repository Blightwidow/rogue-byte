/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SM;
struct ACTADJ;
struct XMG;
struct ALO;
struct SO { char pad[0xC]; char *vt; char pad1[0x4C - 0x10]; SO *base; };
struct JT {
    char pad0[0xC]; char *vt; char pad1[0x208 - 0x10]; SO *surface;
    char pad2[0x1028 - 0x20C]; SM *sm; char pad3[0x1034 - 0x102C]; void *sma;
    char pad4[0x1514 - 0x1038]; int tight; char pad5[0x1520 - 0x1518];
    char xmgLeft[0x100]; char xmgRight[0x100];
    char pad6[0x19D4 - 0x1720];
    ALO *rightBall; ALO *leftBall; ALO *rightHeel; ALO *leftHeel;
    char pad7[0x19F0 - 0x19E4];
    ACTADJ *leftAdj; ACTADJ *rightAdj;
};
struct VT0 { short delta; short index; int (*fn)(void *); };
struct VT1 { short delta; short index; QW (*fn)(void *); };
extern "C" {
extern float g_2dded4;
int func_001430C8(JT *);
void SetSmaMask(void *, int);
float GLimitAbs__Fff(float, float);
void SetStepRadTarget(JT *, float);
int IsmsFindSmOptional__FP2SM3OID(SM *, int);
void SeekSma(void *, int);
int FMatchJtXmg(JT *, void *, void *);
}
void RebuildJtXmg(JT *, ALO *, float, ALO *, ACTADJ *, XMG *);
void UpdateJtStand(JT *jt)
{
    SetSmaMask(jt->sma, func_001430C8(jt));
    VT0 *vt0 = (VT0 *)(jt->vt + 0x2E0);
    if (vt0->fn((char *)jt + vt0->delta) == 0 && jt->surface) {
        SO *base = jt->surface->base;
        VT1 *vt1 = (VT1 *)(base->vt + 0x110);
        union { QW q; float f[4]; } angular;
        angular.q = vt1->fn((char *)base + vt1->delta);
        angular.f[2] = GLimitAbs__Fff(angular.f[2], 10.0f);
        float rad = *(float *)((char *)jt + 0x1A8);
        SetStepRadTarget(jt, rad + angular.f[2] * g_2dded4);
    }
    if (jt->leftAdj) {
        XMG *left = (XMG *)jt->xmgLeft;
        XMG *right = (XMG *)jt->xmgRight;
        RebuildJtXmg(jt, jt->leftBall, 5.0f, jt->leftHeel, jt->leftAdj, left);
        RebuildJtXmg(jt, jt->rightBall, 5.0f, jt->rightHeel, jt->rightAdj, right);
        if (FMatchJtXmg(jt, left, jt->leftAdj) == 0 || FMatchJtXmg(jt, right, jt->rightAdj) == 0) {
            if (jt->tight == 0 && jt->sm) {
                if (IsmsFindSmOptional__FP2SM3OID(jt->sm, 0x17C) >= 0)
                    SeekSma(jt->sma, 0x17C);
                jt->tight = 1;
            }
        }
    }
}
