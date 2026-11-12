// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "vu0inline.h"
struct SW { char pad[0x402C]; int hitfx; };
extern SW B_003DD490;
extern int D_002C4368[];
extern float D_002C4338[];
struct BURSTENTRY { char bytes[0x60]; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void IntersectSwBoundingSphere(SW *, QW, void *, void *, float, int *, int *);
QW SetVectorSphere__FP6VECTORfff(float, float, float);
QW LimitVectorLength__FP6VECTORfT0(QW, float);
void AddGadgetBurstWkr(char *, int, int, QW, QW, int, int *, int, int *, BURSTENTRY *);
void PaloAbsorbWkr(BURSTENTRY *);
int *PhitfxSpawn(int, QW, char *);
void FFilterOxaBasic();
}
extern "C" void ExplodeGadgetBurst(char *pgadget, int arg1, int arg2, QW origin, float fradius)
{
    char frame[0x10];
    BURSTENTRY aentry[32];
    int cgeom;
    int *ageom;
    int centry;
    CStackFrame_Construct(frame);
    IntersectSwBoundingSphere(&B_003DD490, origin, (void *)FFilterOxaBasic, *(void **)(pgadget + 0xEC), fradius, &cgeom, (int *)&ageom);
    centry = 0;
    for (unsigned int iring = 0; iring < 11; iring++) {
        for (int ipoint = 0; ipoint < D_002C4368[iring]; ipoint++) {
            QW offset = SetVectorSphere__FP6VECTORfff(2.0f * (float)ipoint * 3.1415927f / (float)D_002C4368[iring], D_002C4338[iring], fradius);
            QW pos = VectorAdd(origin, offset);
            AddGadgetBurstWkr(pgadget, arg1, arg2, origin, pos, cgeom, ageom, 0x20, &centry, aentry);
        }
    }
    for (int igeom = 0; igeom < cgeom; igeom++) {
        QW delta = VectorSub(*(QW *)(**(char ***)((char *)ageom + igeom * 4) + 0x70), origin);
        QW offset = LimitVectorLength__FP6VECTORfT0(delta, fradius);
        QW pos = VectorAdd(origin, offset);
        AddGadgetBurstWkr(pgadget, arg1, arg2, origin, pos, cgeom, ageom, 0x20, &centry, aentry);
    }
    for (int ientry = 0; ientry < centry; ientry++)
        PaloAbsorbWkr(&aentry[ientry]);
    PhitfxSpawn(B_003DD490.hitfx, origin, pgadget)[0x15] = 1;
    CStackFrame_Destructor(frame, 2);
}
