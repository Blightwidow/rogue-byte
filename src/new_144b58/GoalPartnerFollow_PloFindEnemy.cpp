// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "sly2.h"
struct ENT { char pad[0x2C0]; long flags; };
struct LIST { char pad[0x28]; int count; ENT *items[1]; };
struct OWNER { char pad[0x1088]; LIST *plist; };
struct PLO { char pad[0x10]; OWNER *powner; };
struct POLY { float c0, c1, c2; };
struct SELF { char pad0[0x10]; OWNER *powner; char pad1[0x1C]; void *ptarget; char pad2[0x5C]; ENT *penemy; };
struct LOCALS { ENT *best; };
extern float RO_002A4E30;
extern POLY RO_002BD300;
extern POLY RO_002BD310;
extern POLY RO_002BD320;
extern "C" int FIsGuardInSgs(void *, int);
extern "C" long GrfsgsFromSgs(int);
extern "C" LIST *PalertFind(void *);
extern "C" QW PosLoWorld(void *);
static inline float Distance(QW pos, QW other)
{
    return LaneX(SqrtX(SquaredLength(VectorSub(pos, other))));
}
extern "C" ENT *GoalPartnerFollow_PloFindEnemy(SELF *self)
{
    LOCALS loc;
    QW pos;
    int index = 0;
    float best_distance = RO_002A4E30;
    loc.best = 0;
    PosLoWorld(self->powner);
    pos = PosLoWorld(self->ptarget);
    long mask = GrfsgsFromSgs(7) | GrfsgsFromSgs(0x10) | GrfsgsFromSgs(0x16) | GrfsgsFromSgs(0x17) | GrfsgsFromSgs(0x2A) | GrfsgsFromSgs(0x2B);
    LIST *list = self->powner->plist;
    if (list->count > 0) {
        ENT **pentry = list->items;
        do {
            ENT *ent = *pentry;
            if ((mask & ent->flags) == 0) {
                QW other = PosLoWorld(ent);
                ENT *enemy = self->penemy;
                float distance = Distance(pos, other);
                if (ent == enemy)
                    distance = RO_002BD300.c0 + distance * (RO_002BD300.c1 + distance * RO_002BD300.c2);
                if (FIsGuardInSgs(ent, 3) != 0)
                    distance = RO_002BD320.c0 + distance * (RO_002BD320.c1 + distance * RO_002BD320.c2);
                if (distance < best_distance) {
                    loc.best = ent;
                    best_distance = distance;
                }
            }
            index += 1;
            pentry += 1;
        } while (index < list->count);
    }
    LIST *alert = PalertFind(self->ptarget);
    if (alert != 0) {
        index = 0;
        if (index < alert->count) {
        ENT **pentry = alert->items;
        do {
            ENT *ent = *pentry;
            if ((mask & ent->flags) == 0) {
                QW other = PosLoWorld(ent);
                ENT *enemy = self->penemy;
                float distance = Distance(pos, other);
                distance = RO_002BD310.c0 + distance * (RO_002BD310.c1 + distance * RO_002BD310.c2);
                if (ent == enemy)
                    distance = RO_002BD300.c0 + distance * (RO_002BD300.c1 + distance * RO_002BD300.c2);
                if (FIsGuardInSgs(ent, 3) != 0)
                    distance = RO_002BD320.c0 + distance * (RO_002BD320.c1 + distance * RO_002BD320.c2);
                if (distance < best_distance) {
                    loc.best = ent;
                    best_distance = distance;
                }
            }
            index += 1;
            pentry += 1;
        } while (index < alert->count);
        }
    }
    return loc.best;
}
