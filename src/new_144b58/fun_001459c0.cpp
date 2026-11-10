#include "sly2.h"
struct Phys { char p0[0xDC]; struct Link *plink; };
struct Link { char p0[0x10]; void *pzone; };
struct Zone { char p0[0x18]; int oid; };
struct Jt2 { char p0[0x2DC]; int jumpState; };
#include "goal.h"
struct GOAL_1459C0 : GOAL {
    Jt2 *pleader;
    char pad_34[0x4C];
    QW posWarp;
};
struct Owner { char p0[0xE8]; Phys *pphys; };
extern "C" {
Zone *GoalPartnerFollow_PpathzoneTarget(GOAL_1459C0 *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
int FPosFreeInPathzone(Zone *, QW, int);
int FFindSurfaceAlongUp(float, float, QW *, int, int);
}
int func_001459C0(GOAL_1459C0 *pgoal)
{
    Zone *pzone = GoalPartnerFollow_PpathzoneTarget(pgoal);
    if (pzone == 0)
        return 0;
    Phys *pphys = ((struct Owner *)pgoal->pstep)->pphys;
    Link *plink = 0;
    if (pphys)
        plink = pphys->plink;
    void *pown = 0;
    if (plink)
        pown = plink->pzone;
    if (pzone == pown)
        return 0;
    if (pzone->oid == 0x2CA)
        return 0;
    if (FIsBasicDerivedFrom(pgoal->pleader, 0x34)) {
        if (pgoal->pleader->jumpState != -1)
            return 0;
    }
    QW pos = PosLoWorld(pgoal->pleader);
    if (FPosFreeInPathzone(pzone, pos, 0)) {
        if (FFindSurfaceAlongUp(100.0f, -150.0f, &pos, 0, 0)) {
            pgoal->posWarp = pos;
            return 1;
        }
    }
    return 0;
}
