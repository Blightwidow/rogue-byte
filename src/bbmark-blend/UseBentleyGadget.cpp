#include "sly2.h"
extern "C" {
struct ACT { int pad[3]; int field; };
extern ACT B_002DEB30;
void bevy_camera_follow_activity(ACT *, int, void *);
void *PslotBentleyGadget(void *, int);
void CarryThrow_SetState(void *, int);
void *PloLeaseCloneObject(int, int);
int FGadgetObjKept(void *);
void func_0018D698(void *, void *, void *);
void GrfbtnJtGadget(void *, int);
void SetBentleyState(void *, int);
void SpendJtGadgetPower(void *, int);
void StartAttach(void *, int, void *, int);
void func_00141D38(void *, int);
}
struct SLOT { int gadget; int pool; void *plo; };
extern "C" void UseBentleyGadget(char *pbentley, int gadget)
{
    B_002DEB30.field = gadget;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, pbentley);
    void *plo;
    switch (gadget) {
    case 4:
    case 5:
    case 7:
    case 9:
    case 0xB:
    case 0xD: {
        SLOT *pslot = (SLOT *)PslotBentleyGadget(pbentley, gadget);
        if ((unsigned)(*(int *)(pbentley + 0x11B4) - 4) < 3) {
            CarryThrow_SetState(pbentley + 0x11B0, 7);
            return;
        }
        plo = pslot->plo;
        if (plo != 0) {
            StartAttach(pbentley + 0x4C0, 0xB, plo, 0);
            return;
        }
        {
        *(void **)(pbentley + 0x16B4) = pslot;
        if (gadget == 7 || gadget == 0xB) {
            char *pnew = (char *)PloLeaseCloneObject(pslot->pool, 0);
            if (pnew == 0)
                return;
            *(int *)(pnew + 0x15C) = pslot->gadget;
            if (FGadgetObjKept(pnew) != 0) {
                *(void **)(pnew + 0x16C) = pbentley;
                func_0018D698(pbentley, pslot, pnew);
            }
            *(void **)(pbentley + 0x11C0) = pnew;
            GrfbtnJtGadget(pbentley, gadget);
            SetBentleyState(pbentley, 0xC);
            CarryThrow_SetState(pbentley + 0x11B0, 4);
            return;
        }
        SpendJtGadgetPower(pbentley, gadget);
        SetBentleyState(pbentley, 6);
        return;
        }
    }
    case 10:
        SpendJtGadgetPower(pbentley, gadget);
        SetBentleyState(pbentley, 0xE);
        return;
    case 8:
        *(int *)(pbentley + 0x9BC) = gadget;
        *(int *)(pbentley + 0x130C) = *(int *)(pbentley + 0x1874);
        StartAttach(pbentley + 0x4C0, 0xB, 0, 0);
        return;
    default:
        func_00141D38(pbentley, gadget);
        return;
    }
}
