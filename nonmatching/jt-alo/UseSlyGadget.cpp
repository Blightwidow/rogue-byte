#include "sly2.h"
extern "C" {
struct ACT { int pad[3]; int field; };
extern ACT B_002DEB30;
extern float B_003E1BEC;
extern float D_002BF3EC;
extern float D_002BF3F0;
extern int g_2dded0;
void bevy_camera_follow_activity(ACT *, int, void *);
void CarryThrow_SetState(void *, int);
void ExplodeExpl(int);
int FGadgetObjKept(void *);
void GrfbtnJtGadget(void *, int);
int NewEmitter(int);
void *PloLeaseCloneObject(int, int);
void SetClockRate(void *, int, float);
void SetEmitterUnpositioned(int, int);
void SetJmpBodyState(void *, int, int);
void SetJmpState(void *, int, int, int);
void SetJtState(void *, int, int);
void SpendJtGadgetPower(void *, int);
void StartAttach(void *, int, int, int);
void VirtualRefPtr_Assign(void *, int);
void func_00141D38(void *, int);
void func_0018D698(void *, void *, void *);
int *func_0018D6F8(void *, int);
}
struct SLOT { int gadget; int pool; int plo; };
extern "C" void UseSlyGadget(char *psly, int gadget)
{
    B_002DEB30.field = gadget;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, psly);
    int emitterId;
    switch (gadget) {
    case 29: {
        SpendJtGadgetPower(psly, gadget);
        SetClockRate(&g_2dded0, 1, D_002BF3EC);
        B_003E1BEC = -1.0f;
        emitterId = 0x67;
        goto emit;
    }
    case 42:
        SpendJtGadgetPower(psly, gadget);
        SetClockRate(&g_2dded0, 1, D_002BF3F0);
        B_003E1BEC = 0.7f;
        emitterId = 0x66;
    emit: {
        int emitter = NewEmitter(emitterId);
        SetEmitterUnpositioned(emitter, 0);
        VirtualRefPtr_Assign(psly + 0x2044, emitter);
        return;
    }
    case 33:
        SpendJtGadgetPower(psly, gadget);
        SetJtState(psly, 9, -1);
        return;
    case 27:
        SpendJtGadgetPower(psly, gadget);
        SetJmpBodyState(psly + 0x2C0, 0x13, 0);
        return;
    case 26:
    case 37:
    case 38:
    case 41: {
        SLOT *pslot = (SLOT *)func_0018D6F8(psly, gadget);
        if ((unsigned)(*(int *)(psly + 0x11B4) - 4) < 3) {
            CarryThrow_SetState(psly + 0x11B0, 7);
            return;
        }
        if (pslot->plo != 0) {
            StartAttach(psly + 0x4C0, 0xB, pslot->plo, 0);
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
        *(void **)(psly + 0x11C0) = pnew;
        GrfbtnJtGadget(psly, gadget);
        SetJtState(psly, 0x17, -1);
        CarryThrow_SetState(psly + 0x11B0, 4);
        return;
    }
    case 34:
    case 35:
        *(int *)(psly + 0x9BC) = gadget;
        if (gadget == 35)
            *(int *)(psly + 0x130C) = *(int *)(psly + 0x1FE0);
        else
            *(int *)(psly + 0x130C) = *(int *)(psly + 0x1FE4);
        StartAttach(psly + 0x4C0, 0xB, 0, 0);
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
        StartAttach(psly + 0x4C0, 2, 0, 0);
        return;
    case 31: {
        int expl = *(int *)(psly + 0x204C);
        if (expl != 0)
            ExplodeExpl(expl);
        SpendJtGadgetPower(psly, gadget);
        SetJmpState(psly + 0x2C0, 9, 0, 0);
        return;
    }
    case 30:
        SpendJtGadgetPower(psly, gadget);
        SetJmpState(psly + 0x2C0, 0xE, 0, 0);
        return;
    default:
        func_00141D38(psly, gadget);
        return;
    }
}
