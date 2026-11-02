#include "sly2.h"
struct ENT { char pad[0x2C0]; long flags; };
struct LIST { char pad[0x28]; int count; ENT *items[1]; };
struct OWNER { char pad[0x1088]; LIST *plist; };
struct PLO { char pad[0x10]; OWNER *powner; };
struct POLY { float c0, c1, c2; };
struct SELF { char pad0[0x10]; OWNER *powner; char pad1[0x1C]; void *ptarget; char pad2[0x5C]; ENT *penemy; };
struct LOCALS { ENT *best; QW pos; };
extern float RO_002A4E30;
extern POLY RO_002BD300;
extern POLY RO_002BD310;
extern POLY RO_002BD320;
extern "C" int FIsGuardInSgs(void *, int);
extern "C" long GrfsgsFromSgs(int);
extern "C" LIST *PalertFind(void *);
extern "C" QW PosLoWorld(void *);
static inline float LaneZero(QW value)
{
    float lane;
    asm("mtc1 %1, %0" : "=f" (lane) : "r" (value));
    return lane;
}
static inline float Distance(QW other, const QW &pos)
{
    int fence1, fence2, fence3, fence4, fence5, fence6, fence7, fence8;
    asm("lqc2 vf2, %1" : "=r" (fence1) : "m" (pos));
    asm("qmtc2.ni %1, vf3" : "=r" (fence2) : "r" (other), "r" (fence1));
    asm("vsub.xyzw vf1, vf2, vf3" : "=r" (fence3) : "r" (fence2));
    asm("vmul.xyz vf1, vf1, vf1" : "=r" (fence4) : "r" (fence3));
    asm("vaddw.x vf2, vf0, vf0w" : "=r" (fence5) : "r" (fence4));
    asm("vadday.x ACC, vf1, vf1y" : "=r" (fence6) : "r" (fence5));
    asm("vmaddz.x vf1, vf2, vf1z" : "=r" (fence7) : "r" (fence6));
    asm volatile("vsqrt Q, vf1x" : : "r" (fence7));
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    QW result;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (result));
    return LaneZero(result);
}
extern "C" ENT *GoalPartnerFollow_PloFindEnemy(SELF *self)
{
    LOCALS loc;
    int index = 0;
    float best_distance = RO_002A4E30;
    loc.best = 0;
    PosLoWorld(self->powner);
    loc.pos = PosLoWorld(self->ptarget);
    long mask = GrfsgsFromSgs(7) | GrfsgsFromSgs(0x10) | GrfsgsFromSgs(0x16) | GrfsgsFromSgs(0x17) | GrfsgsFromSgs(0x2A) | GrfsgsFromSgs(0x2B);
    LIST *list = self->powner->plist;
    if (list->count > 0) {
        ENT **pentry = list->items;
        do {
            ENT *ent = *pentry;
            if ((mask & ent->flags) == 0) {
                QW other = PosLoWorld(ent);
                ENT *enemy = self->penemy;
                float distance = Distance(other, loc.pos);
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
    index = 0;
    if (alert != 0 && alert->count > 0) {
        ENT **pentry = alert->items;
        do {
            ENT *ent = *pentry;
            if ((mask & ent->flags) == 0) {
                QW other = PosLoWorld(ent);
                ENT *enemy = self->penemy;
                float distance = Distance(other, loc.pos);
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
    return loc.best;
}
