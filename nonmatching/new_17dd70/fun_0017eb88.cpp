// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct GOAL { char pad[0x10]; void *pguard; char pad1[0x1C]; void *pcrv; char padc[4]; float s; char pad2[4]; QW pos; int g0; int g1; int g2; };
extern "C" void func_001EEF70(void);
extern "C" QW PosLoWorld(void *);
extern "C" char B_003DD020;
extern "C" void FindCrvClosestPointFromS(void *, QW, float, void *, QW *, void *, void *, float *);
extern "C" void FindCrvClosestPointAll(void *, QW, void *, QW *, void *, void *, float *);
extern "C" OBJ *func_00205438(void *, int);
extern "C" void func_0017ECF0(GOAL *, int);
#define F(o, off, T) (*(T *)((char *)(o) + (off)))
void func_0017EB88(GOAL *pgoal)
{
    func_001EEF70();
    QW posGuard;
    float zero = 0.0f;
    float cur = pgoal->s;
    asm volatile("nop" : : "f" (zero));
    if (zero <= cur) {
        posGuard = PosLoWorld(pgoal->pguard);
        FindCrvClosestPointFromS(pgoal->pcrv, posGuard, pgoal->s, &B_003DD020, &pgoal->pos, 0, 0, &pgoal->s);
    } else {
        posGuard = PosLoWorld(pgoal->pguard);
        FindCrvClosestPointAll(pgoal->pcrv, posGuard, &B_003DD020, &pgoal->pos, 0, 0, &pgoal->s);
    }
    OBJ *pobj = func_00205438(pgoal->pguard, 0xBA);
    F(pobj, 0xA8, int) = pgoal->g0;
    F(pobj, 0xAC, int) = pgoal->g1;
    F(pobj, 0xBC, int) = pgoal->g2;
    func_0017ECF0(pgoal, 1);
    VT *vt = pobj->vt;
    vt->fn((char *)pobj + vt->delta);
}
