#include "sly2.h"
struct Parms { char pad[0x50]; int kind; };
struct Hitfx { char pad[0x14]; Parms *parms; char pad2[8]; QW pos; char pad3[0x1C]; float tstart; int pad4; int state; };
extern "C" QW PosLoWorld(void *);

int NCompareHitfxForGuard(void *guard, Hitfx *a, Hitfx *b)
{
    int d = a->parms->kind - b->parms->kind;
    if (d != 0) return d;
    d = b->state - a->state;
    if (d != 0) return d;
    float ta = a->tstart;
    float tb = b->tstart;
    if (tb < ta) return -1;
    if (ta < tb) return 1;
    QW p = PosLoWorld(guard);
    asm volatile("lqc2 vf2, %0" : : "m" (a->pos));
    int bitsA;
    asm("qmtc2.ni %1, vf3\n\tvsub.xyzw vf1, vf3, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (bitsA) : "r" (p));
    float da;
    asm("mtc1 %1, %0" : "=f" (da) : "r" (bitsA));
    p = PosLoWorld(guard);
    int bitsB;
    asm("qmtc2.ni %1, vf3\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf3, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (bitsB) : "r" (p), "m" (b->pos));
    float db;
    asm("mtc1 %1, %0\n\tnop" : "=f" (db) : "r" (bitsB));
    if (da < db) return -1;
    if (db > da) return 1;
    return (int)(((unsigned)a - (unsigned)b) * 0xAAAAAAABu) >> 5;
}
