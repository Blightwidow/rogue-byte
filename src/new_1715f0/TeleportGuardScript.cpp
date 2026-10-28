#include "sly2.h"
struct VT {
    char pad0[0xE8]; short d0; short i0; void (*setPos)(void *, QW);
    short d1; short i1; void (*setOrient)(void *, void *);
    char pad1[0x118 - 0xF8]; short d2; short i2; void (*setVel)(void *, QW);
    short d3; short i3; void (*setAng)(void *, QW);
};
struct ACTOR { char pad[0xC]; VT *vt; };
struct BEH { char pad[0x10]; ACTOR *actor; };
extern QW g_2a2dd0;
extern "C" void ClearGuardPathMode(ACTOR *);
extern "C" void SetStepRadTarget(ACTOR *, float);
void TeleportGuardScript(BEH *beh, QW pos, float rad)
{
    ACTOR *actor = beh->actor;
    ClearGuardPathMode(actor);
    register VT *vt asm("$2") = actor->vt;
    vt->setPos((char *)actor + vt->d0, pos);
    SetStepRadTarget(actor, rad);
    vt = actor->vt;
    vt->setOrient((char *)actor + vt->d1, (char *)actor + 0x1B0);
    vt = actor->vt;
    vt->setVel((char *)actor + vt->d2, g_2a2dd0);
    vt = actor->vt;
    vt->setAng((char *)actor + vt->d3, g_2a2dd0);
}
