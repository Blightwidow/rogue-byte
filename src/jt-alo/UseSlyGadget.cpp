#include "sly.h"
#include "sly2.h"
extern "C" {
struct ACT { int pad[3]; int field; };
extern ACT B_002DEB30;
extern float B_003E1BEC;
extern float D_002BF3EC;
extern float D_002BF3F0;
extern char g_2dded0[];
void bevy_camera_follow_activity(ACT *, int, void *);
void CarryThrow_SetState(void *, int);
void ExplodeExpl(int);
int FGadgetObjKept(void *);
void GrfbtnJtGadget(void *, int);
void *NewEmitter(int);
void *PloLeaseCloneObject(int, int);
void SetClockRate(void *, int, float);
void SetEmitterUnpositioned(void *, int);
void SetJmpBodyState(void *, int, int);
void SetJmpState(void *, int, int, int);
void SetJtState(void *, int, int);
void SpendJtGadgetPower(void *, int);
void StartAttach(void *, int, int, int);
void VirtualRefPtr_Assign(void *, void *);
void func_00141D38(void *, int);
void func_0018D698(void *, void *, void *);
int *func_0018D6F8(void *, int);
}
struct SLOT { int gadget; int pool; int plo; };
// Retail repeats the time-gadget body (SpendJtGadgetPower, SetClockRate, the
// B_003E1BEC store, NewEmitter, SetEmitterUnpositioned, VirtualRefPtr_Assign)
// for gadgets 29 and 42, and gcc's cross-jumping merges only their common tail
// (emitter id in the branch delay slot). Written as one block with a goto to a
// shared label, the argument moves before SpendJtGadgetPower and SetClockRate
// schedule in the other order; two full case bodies give retail's order.
extern "C" void UseSlyGadget(SLY *psly, int gadget)
{
    B_002DEB30.field = gadget;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, psly);
    switch (gadget) {
    case 29: {
        SpendJtGadgetPower(psly, gadget);
        SetClockRate(g_2dded0, 1, D_002BF3EC);
        B_003E1BEC = -1.0f;
        void *emitter = NewEmitter(0x67);
        SetEmitterUnpositioned(emitter, 0);
        VirtualRefPtr_Assign((char *)psly + 0x2044, emitter);
        return;
    }
    case 42: {
        SpendJtGadgetPower(psly, gadget);
        SetClockRate(g_2dded0, 1, D_002BF3F0);
        B_003E1BEC = 0.7f;
        void *emitter = NewEmitter(0x66);
        SetEmitterUnpositioned(emitter, 0);
        VirtualRefPtr_Assign((char *)psly + 0x2044, emitter);
        return;
    }
    case 33:
        SpendJtGadgetPower(psly, gadget);
        SetJtState(psly, 9, -1);
        return;
    case 27:
        SpendJtGadgetPower(psly, gadget);
        SetJmpBodyState((char *)psly + 0x2C0, 0x13, 0);
        return;
    case 26:
    case 37:
    case 38:
    case 41: {
        SLOT *pslot = (SLOT *)func_0018D6F8(psly, gadget);
        if ((unsigned)(psly->field_0x11B4 - 4) < 3) {
            CarryThrow_SetState((char *)psly + 0x11B0, 7);
            return;
        }
        if (pslot->plo != 0) {
            StartAttach((char *)psly + 0x4C0, 0xB, pslot->plo, 0);
            return;
        }
        char *pnew = (char *)PloLeaseCloneObject(pslot->pool, 0);
        if (pnew == 0)
            return;
        *(int *)(pnew + 0x15C) = pslot->gadget;
        if (FGadgetObjKept(pnew) != 0) {
            *(void **)(pnew + 0x16C) = psly;
            func_0018D698(psly, pslot, pnew);
        }
        *(void **)((char *)psly + 0x11C0) = pnew;
        GrfbtnJtGadget(psly, gadget);
        SetJtState(psly, 0x17, -1);
        CarryThrow_SetState((char *)psly + 0x11B0, 4);
        return;
    }
    case 34:
    case 35:
        psly->field_0x9BC = gadget;
        if (gadget == 35)
            psly->field_0x130C = psly->field_0x1FE0;
        else
            psly->field_0x130C = psly->field_0x1FE4;
        StartAttach((char *)psly + 0x4C0, 0xB, 0, 0);
        return;
    case 24:
        SpendJtGadgetPower(psly, gadget);
        SetJtState(psly, 6, -1);
        return;
    case 25:
        SpendJtGadgetPower(psly, gadget);
        SetJtState(psly, 0x18, 0xC);
        return;
    case 39:
        SpendJtGadgetPower(psly, gadget);
        SetJtState(psly, 5, 9);
        return;
    case 40:
        SpendJtGadgetPower(psly, gadget);
        StartAttach((char *)psly + 0x4C0, 2, 0, 0);
        return;
    case 31: {
        int expl = psly->field_0x204C;
        if (expl != 0)
            ExplodeExpl(expl);
        SpendJtGadgetPower(psly, gadget);
        SetJmpState((char *)psly + 0x2C0, 9, 0, 0);
        return;
    }
    case 30:
        SpendJtGadgetPower(psly, gadget);
        SetJmpState((char *)psly + 0x2C0, 0xE, 0, 0);
        return;
    default:
        func_00141D38(psly, gadget);
        return;
    }
}
