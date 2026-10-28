/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VT { char pad[0x308]; short delta; short index; void (*fn)(void *, void *); };
struct JTOBJ { char pad[0xC]; VT *vt; };
struct PJT { JTOBJ *pobj; };
struct LO { char pad[0x38]; float sMrd; char pad2[0xE0 - 0x3C]; int sRadiusFrustum; char pad3[0x108 - 0xE4]; int visibility; };
struct BINOCRECON {
    char pad[0x20];
    float posEye[4];
    int ctarget;
    LO *atarget[21];
    char pad2[0x8C - 0x34 - 21 * 4];
    LO *ptargetCur;
    char pad3[0xA8 - 0x90];
    PJT *ppjt;
};
extern "C" {
extern char B_002DDF40[];
extern const float RO_FLT_002A8550;
int FReconTargetPickable(LO *);
QW PosLoWorld(void *);
int FInsideCmFrustrum(void *, QW, int);
int FInsideCmMrd(float, void *, QW, void *);
void ProbeReconTargetVisibility(void *, LO *);
void bevy_ui_binoc_recon_202768(void *, int);
}

void PickReconTarget(BINOCRECON *precon)
{
    int index = 0;
    LO *ptargetBest = 0;
    float sBest;
    JTOBJ *pobj = precon->ppjt->pobj;
    VT *vt = pobj->vt;
    vt->fn((char *)pobj + vt->delta, &precon->posEye);
    precon->posEye[2] = precon->posEye[2] + 20.0f;
    sBest = RO_FLT_002A8550;
    for (; index < precon->ctarget; index++) {
        LO *ptarget = precon->atarget[index];
        if (FReconTargetPickable(ptarget) == 0)
            continue;
        QW posTarget = PosLoWorld(ptarget);
        QW posDelta;
        asm("lqc2 vf2, %0" : : "m"(posTarget));
        asm("lqc2 vf1, 0x90(%0)" : : "r"(B_002DDF40));
        asm("vsub.xyzw vf2, vf2, vf1");
        asm("qmfc2.ni %0, vf2" : "=r"(posDelta));
        if (FInsideCmFrustrum(B_002DDF40, posDelta, ptarget->sRadiusFrustum) == 0)
            continue;
        unsigned char abMrd[16];
        if (FInsideCmMrd(ptarget->sMrd, B_002DDF40, PosLoWorld(ptarget), abMrd) == 0)
            continue;
        float distance;
        asm("lqc2 vf2, %0" : : "m"(posTarget));
        asm("lqc2 vf1, 0x90(%0)" : : "r"(B_002DDF40));
        asm("vsub.xyzw vf1, vf2, vf1");
        asm("vmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f"(distance));
        if (distance < sBest) {
            ProbeReconTargetVisibility(precon, ptarget);
            if (ptarget->visibility != 2) {
                ptargetBest = ptarget;
                sBest = distance;
            }
        }
    }
    if (ptargetBest != precon->ptargetCur) {
        precon->ptargetCur = ptargetBest;
        bevy_ui_binoc_recon_202768(precon, 2);
    }
}
