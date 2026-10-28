#include "sly2.h"
struct Basic { char pad0[0x188]; int kind; int fAlert; int pad190; };
struct LootDef { char pad[0x10]; int fAllowed; int kind; };
struct Loot { char pad[0x158]; LootDef *pdef; int pguard; int pthief; };
struct Guard { char pad[0x188]; int kind; int pad18C; int fAlert; Loot *ploot; };
struct Jt { char pad[0x11A8]; Loot *ploot; };
extern int B_003E0F9C;
extern char B_003DA0C0[];
extern char B_002DEB30[];
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void ShowHudLabel(void *, int, float);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void bevy_camera_follow_activity(void *, int, void *);
void UpdateJtLootSave(void *, int, void *);
void SetLootState(void *, int);
void func_00184130(void *, void *);
}
extern "C" void Crfodb_OnGrab(Guard *guard, Jt *jt)
{
    if (FIsBasicDerivedFrom(jt, 0x34) == 0)
        return;
    Loot *plootCarried = guard->ploot;
    Loot *plootHeld = jt->ploot;
    if (plootHeld == 0 && plootCarried == 0)
        return;
    if (plootCarried != 0 && B_003E0F9C != 0) {
        if (plootCarried->pdef->fAllowed == 0) {
            ShowHudLabel(B_003DA0C0, 0x124, 15.0f);
            SetEmitterUnpositioned(NewEmitter(0x36), 0);
            return;
        }
    }
    if (guard->fAlert != 0 || (plootHeld != 0 && plootHeld->pdef->kind != guard->kind)) {
        bevy_camera_follow_activity(B_002DEB30, 0x32, guard);
        return;
    }
    if (guard->ploot != 0)
        SetEmitterUnpositioned(NewEmitter(0x27), 0);
    UpdateJtLootSave(jt, 0, guard);
    if (jt->ploot != 0) {
        if (guard->ploot != 0) {
            jt->ploot->pguard = (int)guard;
            SetLootState(jt->ploot, 3);
            guard->ploot->pthief = (int)jt;
            SetLootState(guard->ploot, 2);
        } else {
            jt->ploot->pguard = (int)guard;
            SetLootState(jt->ploot, 3);
        }
    } else {
        guard->ploot->pthief = (int)jt;
        SetLootState(guard->ploot, 2);
    }
    func_00184130(guard, jt);
}
