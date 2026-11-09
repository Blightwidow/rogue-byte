// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SM;
struct CRef { int tagk; int n; int pad[2]; };
struct PAD12 { char pad[0xC]; };
// Retail's virtual calls read the gcc 2.95 vtable at +0xC: slot k sits at (k + 1) * 8 ({short delta, short index, fn}).
// HUB calls slot 2 (+0x18) with five arguments. The vtable pointer is declared in a base so that gcc 2.95 puts it
// at +0xC, ahead of the derived class's fields.
struct HUB_BASE : PAD12 {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Message(int message, int arg1, int arg2, int arg3, int arg4);
};
struct HUB : HUB_BASE {
    char pad1[0x180 - 0x10];
    int state;
    SM *sm;
    int sma;
};
// Objects of class 0x64 receive slot 75 (+0x260) with one int argument.
struct NOTIFY_OBJECT : PAD12 {
    virtual void Slot0();  virtual void Slot1();  virtual void Slot2();  virtual void Slot3();  virtual void Slot4();
    virtual void Slot5();  virtual void Slot6();  virtual void Slot7();  virtual void Slot8();  virtual void Slot9();
    virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14();
    virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19();
    virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23(); virtual void Slot24();
    virtual void Slot25(); virtual void Slot26(); virtual void Slot27(); virtual void Slot28(); virtual void Slot29();
    virtual void Slot30(); virtual void Slot31(); virtual void Slot32(); virtual void Slot33(); virtual void Slot34();
    virtual void Slot35(); virtual void Slot36(); virtual void Slot37(); virtual void Slot38(); virtual void Slot39();
    virtual void Slot40(); virtual void Slot41(); virtual void Slot42(); virtual void Slot43(); virtual void Slot44();
    virtual void Slot45(); virtual void Slot46(); virtual void Slot47(); virtual void Slot48(); virtual void Slot49();
    virtual void Slot50(); virtual void Slot51(); virtual void Slot52(); virtual void Slot53(); virtual void Slot54();
    virtual void Slot55(); virtual void Slot56(); virtual void Slot57(); virtual void Slot58(); virtual void Slot59();
    virtual void Slot60(); virtual void Slot61(); virtual void Slot62(); virtual void Slot63(); virtual void Slot64();
    virtual void Slot65(); virtual void Slot66(); virtual void Slot67(); virtual void Slot68(); virtual void Slot69();
    virtual void Slot70(); virtual void Slot71(); virtual void Slot72(); virtual void Slot73(); virtual void Slot74();
    virtual void Notify(int message);
};
// Objects of class 0x4F receive slot 8 (+0x48) with no argument besides this.
struct RESET_OBJECT : PAD12 {
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3();
    virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7();
    virtual void Reset();
};
struct JOB { char pad[0x74]; int field74; };
struct GLOBALS { char pad[0x3B0C]; JOB *job; };
extern "C" {
extern GLOBALS B_003DD490;
extern int g_2dfbc0;
extern char B_002DFC00[];
extern char B_002E0D00[];
extern const char RO_002A7878[];
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
void DeliverJtLoot(void *);
int IsmsFindSmOptional__FP2SM3OID(SM *, int);
int OidFromSmIsms(SM *, int);
void StepHubState(HUB *, int);
void bevy_jobs_162e38(JOB *);
void bevy_player_p18_gadget_refill(void *, int);
void func_00187E78(void *);
void func_001D8A38(CRef *, const char *, int);
void CRef_Destruct(CRef *);
void func_001F1448(SM *, HUB *, int, int, int *);
}
// Retail's third loop loads each object into $a1 and calls slot 8 with $a0 = object + delta and nothing else set up:
// $a1 is just the next free register, not an argument. Declaring that slot with an argument (the object) makes gcc
// copy the object into $a1 and keep it in $a0 (score 12); the slot takes no argument, as written here.
// The three virtual calls are real C++ virtual calls (gcc 2.95 vtables), as in src/new_17dd70/Mount_SetState.cpp.
void SetHubState(HUB *hub, int state)
{
    void *players[4];
    NOTIFY_OBJECT *notified[0x20];
    RESET_OBJECT *reset[0x20];
    CRef ref;
    if (hub->state == state)
        return;
    if (hub->state == 1) {
        func_001F1448(0, hub, -1, 0, &hub->sma);
        hub->Message(6, 0, 0, 0, 0);
    }
    hub->state = state;
    if (state != 1)
        return;
    JOB *job = B_003DD490.job;
    if (job && job->field74 == 0)
        bevy_jobs_162e38(job);
    int count = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0, 3, players);
    for (int index = 0; index < count; index++) {
        void *player = players[index];
        DeliverJtLoot(player);
        bevy_player_p18_gadget_refill(player, 1);
    }
    count = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x64, 0, 0x20, notified);
    for (int index = 0; index < count; index++)
        notified[index]->Notify(4);
    count = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x4F, 0, 0x20, reset);
    for (int index = 0; index < count; index++)
        reset[index]->Reset();
    int oid;
    if (hub->sm) {
        func_001D8A38(&ref, RO_002A7878, 0);
        int value = ref.n;
        CRef_Destruct(&ref);
        if (IsmsFindSmOptional__FP2SM3OID(hub->sm, value) == -1)
            oid = OidFromSmIsms(hub->sm, 0);
        else
            oid = value;
    } else {
        oid = -1;
    }
    func_001F1448(hub->sm, hub, oid, 0, &hub->sma);
    StepHubState(hub, 0);
    func_00187E78(g_2dfbc0 & 2 ? B_002DFC00 : B_002E0D00);
    hub->Message(5, 0, 0, 0, 0);
}
