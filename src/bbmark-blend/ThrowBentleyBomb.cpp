#include "sly2.h"
struct VT { char pad[0x120]; short delta; short index; void (*fn)(void *, QW); };
struct LAUNCH { char pad0[0x50]; QW vecTarget; int unk60; };
struct GEOM { char pad[0x18]; int grf; };
struct BOMB { char pad0[0xC]; VT *vptr; char pad1[0xE4 - 0x10]; GEOM *pgeom; };
struct BENTLEY { char pad0[0x16D8]; int kind; int ppoolA; int ppoolB; LAUNCH *plaunch; char pad1[0x16F0 - 0x16E8]; QW vecAim; float tCooldown; };
extern QW g_2a2dd0;
extern float g_2dded0;
extern "C" {
void CalcBentleyBombTarget(BENTLEY *);
BOMB *PloLeaseCloneObject(int, int);
void LaunchSoAtTarget(LAUNCH *, BOMB *);
void PrimeBomb__FP4BOMBf(BOMB *, float);
void SetBentleyAimState(BENTLEY *, int);
}
void ThrowBentleyBomb(BENTLEY *pbentley, int grfGeom)
{
    CalcBentleyBombTarget(pbentley);
    int ppool;
    switch (pbentley->kind) {
    case 0:
        ppool = pbentley->ppoolA;
        break;
    case 1:
        ppool = pbentley->ppoolB;
        break;
    default:
        return;
    }
    if (ppool == 0)
        return;
    BOMB *pbomb = PloLeaseCloneObject(ppool, 0);
    if (pbomb == 0)
        return;
    pbomb->pgeom->grf = grfGeom;
    LAUNCH *plaunch = pbentley->plaunch;
    plaunch->unk60 = 0;
    plaunch->vecTarget = pbentley->vecAim;
    LaunchSoAtTarget(plaunch, pbomb);
    VT *vtable = pbomb->vptr;
    vtable->fn((char *)pbomb + vtable->delta, g_2a2dd0);
    PrimeBomb__FP4BOMBf(pbomb, 4.0f);
    SetBentleyAimState(pbentley, 1);
    pbentley->tCooldown = g_2dded0;
}
