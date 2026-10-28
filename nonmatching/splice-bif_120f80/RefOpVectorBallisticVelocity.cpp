// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRef { int tagk; union { int n; float g; QW *pv; }; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PHYS { char pad[0x80]; QW dvGravity; };
struct SO { char pad[0xE8]; PHYS *pphys; };
struct CFrame;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
QW FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(QW, QW, float, QW);
}
extern "C" CRef *RefOpVectorBallisticVelocity(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    VECTOR accel;
    accel.x = 0.0f;
    accel.y = 0.0f;
    accel.z = -1750.0f;
    if (aref[3].tagk != 0) {
        SO *pso = (SO *)((CPair *)aref[3].n)->ref.n;
        if (pso != 0) {
            if (pso->pphys != 0) {
                *(QW *)&accel = pso->pphys->dvGravity;
            }
        }
    }
    CRef refVelocity;
    SetTag__4CRef4TAGK(&refVelocity, 0x1A);
    CRef refTemp;
    QW *pvelocity = refVelocity.pv;
    QW accelValue = *(QW *)&accel;
    QW posFrom = *aref[0].pv;
    QW posTo = *aref[1].pv;
    CRef_RefCoerceF32(&refTemp, &aref[2]);
    *pvelocity = FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(posFrom, posTo, refTemp.g, accelValue);
    CRef_Destruct(&refTemp);
    CRef *plast = &refVelocity;
    asm("" : "+r" (plast));
    CRef_CopyConstruct(pret, plast);
    CRef_Destruct(plast);
    return pret;
}
