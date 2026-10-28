/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SWX { char pad[0x45CC]; void *graph; };
struct PZ { char pad[1]; };
struct PZLINK { char pad[0x128]; PZ *zoneFar; };
struct PZL { char pad[0x10]; PZ *zone; };
struct GX2 { char pad[0xDC]; PZL *pzl; };
struct GUARDX { char pad[0xE8]; GX2 *g2; };
struct GOAL {
    char pad0[0x10]; GUARDX *guard; char pad1[0x40 - 0x14];
    QW target0; QW target1;
    QW resolved0; QW resolved1;
    int pad80[(0xB4 - 0x80) / 4];
    int cpzlink; PZLINK *pzlink[1]; int fStraight; int fLink;
};
extern SWX B_003DD490;
extern "C" {
QW PosLoWorld(void *);
QW func_001C1EC0(void *, QW);
PZ *PpathzoneFindPos(QW, int);
int CpzlinkFindPath(void *, void *, QW, int, int, PZLINK **);
void FFindPathzoneClosestPoint(PZ *, QW, QW *, int);
}
void func_0017D8A8(GOAL *goal)
{
    goal->cpzlink = 0;
    goal->resolved0 = goal->target0;
    goal->resolved1 = goal->target1;
    if (goal->fStraight)
        return;
    QW posGuard = PosLoWorld(goal->guard);
    QW posTarget = func_001C1EC0(&goal->target0, posGuard);
    GX2 *g2 = goal->guard->g2;
    PZL *pzl = g2 ? g2->pzl : 0;
    PZ *zoneGuard = pzl ? pzl->zone : 0;
    PZ *zoneTarget = PpathzoneFindPos(posTarget, 0);
    int stay = 0;
    if (zoneTarget == 0) {
        stay = 1;
    } else if (zoneTarget != zoneGuard) {
        int count;
        if ((goal->cpzlink = CpzlinkFindPath(B_003DD490.graph, goal->guard, posTarget, 1, 1, goal->pzlink)) <= 0) {
            if (goal->fLink == 0) {
                stay = 1;
            } else {
                count = CpzlinkFindPath(B_003DD490.graph, goal->guard, posTarget, 0, 1, goal->pzlink);
                goal->cpzlink = count;
                if (count == 0) {
                    stay = 1;
                } else {
                    PZ *zoneNear;
                    if (goal->pzlink[0] == 0) {
                        goal->cpzlink = 0;
                        zoneNear = zoneGuard;
                    } else {
                        zoneNear = goal->pzlink[count - 1]->zoneFar;
                    }
                    *(int *)&goal->resolved0 = 0;
                    *((int *)&goal->resolved0 + 1) = 0;
                    FFindPathzoneClosestPoint(zoneNear, posTarget, &goal->resolved1, 1);
                }
            }
        }
    }
    if (stay) {
        goal->resolved1 = posGuard;
        *((int *)&goal->resolved0 + 1) = 0;
        *(int *)&goal->resolved0 = 0;
    }
}
