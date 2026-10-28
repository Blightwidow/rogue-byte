#include "sly2.h"
struct SENSOR { char pad[0xE8]; unsigned long *volume; };
struct VOL { char pad[0x28]; unsigned long flags; };
struct GUARD { char pad0[0xEC]; int fEC; char pad1[0xE68 - 0xF0]; int fE68; char pad2[0xF64 - 0xE6C]; SENSOR *sensor; };
struct TARGET { char pad[0x50]; int kind; };
struct STIM { char pad0[0x14]; TARGET *target; char pad1[8]; QW pos; char pad2[0x40 - 0x30]; void *emitter; void *source; char pad3[0x54 - 0x48]; int level; };
extern "C" {
int func_00208D70(GUARD *);
void *PentryFindSensorLo(SENSOR *, void *);
QW PosLoWorld(GUARD *);
int FHitFxCoversPos(STIM *, QW);
int func_00227C90(void *, QW);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void bevy_camera_follow_push_out(void *, QW, QW, void *, int, int *, int *);
void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, int);
int FFilterOxaBasic(void *, void *);
extern char B_003DD490[];
}
int func_00208BE0(GUARD *guard, STIM *stim)
{
    if (func_00208D70(guard) == 0) return 0;
    if (stim->level < guard->fE68) return 0;
    if (stim->emitter != 0 && stim->emitter == guard) return 0;
    if (stim->level == 4) {
        void *source = stim->source;
        void *entry = PentryFindSensorLo(guard->sensor, source);
        if (source != guard && entry == 0) return 0;
    }
    TARGET *target = stim->target;
    QW posGuard = PosLoWorld(guard);
    int kind = target->kind;
    QW posStim = stim->pos;
    if (kind != 0) {
        if (kind != 1)
            return 0;
    } else {
        return FHitFxCoversPos(stim, PosLoWorld(guard));
    }
    VOL *volume = (VOL *)guard->sensor->volume;
    if (volume == 0) return 0;
    if (((volume->flags >> 60) & 1) == 0) return 0;
    if (func_00227C90(volume, posStim) == 0) return 0;
    struct { char frame[4]; int cpso; int apso; } l;
    CStackFrame_Construct(&l);
    bevy_camera_follow_push_out(B_003DD490, posGuard, posStim, (void *)FFilterOxaBasic, guard->fEC, &l.cpso, &l.apso);
    if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, posGuard, posStim, l.cpso, l.apso, 0) != 0) {
        CStackFrame_Destructor(&l, 2);
        return 0;
    }
    CStackFrame_Destructor(&l, 2);
    return 1;
}
