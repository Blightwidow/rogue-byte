#include "bentley.h"
#include "sly2.h"
extern "C" {
struct ACT { int pad[3]; int field; };
extern ACT B_002DEB30;
void bevy_camera_follow_activity(ACT *, int, void *);
BENTLEYSLOT *PslotBentleyGadget(void *, int);
void CarryThrow_SetState(void *, int);
void *PloLeaseCloneObject(void *, int);
int FGadgetObjKept(void *);
void func_0018D698(void *, void *, void *);
void GrfbtnJtGadget(void *, int);
void SetBentleyState(void *, int);
void SpendJtGadgetPower(void *, int);
void StartAttach(void *, int, void *, int);
void func_00141D38(void *, int);
}
extern "C" void UseBentleyGadget(BENTLEY *pbentley, int gadget)
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
        BENTLEYSLOT *pslot = PslotBentleyGadget(pbentley, gadget);
        if ((unsigned)(pbentley->field_0x11B4 - 4) < 3) {
            CarryThrow_SetState((char *)pbentley + 0x11B0, 7);
            return;
        }
        plo = pslot->plo;
        if (plo != 0) {
            StartAttach((char *)pbentley + 0x4C0, 0xB, plo, 0);
            return;
        }
        {
        pbentley->pslotActive = pslot;
        if (gadget == 7 || gadget == 0xB) {
            char *pnew = (char *)PloLeaseCloneObject(pslot->ppool, 0);
            if (pnew == 0)
                return;
            *(int *)(pnew + 0x15C) = pslot->gadget;
            if (FGadgetObjKept(pnew) != 0) {
                *(void **)(pnew + 0x16C) = pbentley;
                func_0018D698(pbentley, pslot, pnew);
            }
            *(void **)((char *)pbentley + 0x11C0) = pnew;
            GrfbtnJtGadget(pbentley, gadget);
            SetBentleyState(pbentley, 0xC);
            CarryThrow_SetState((char *)pbentley + 0x11B0, 4);
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
        pbentley->field_0x9BC = gadget;
        pbentley->field_0x130C = pbentley->field_0x1874;
        StartAttach((char *)pbentley + 0x4C0, 0xB, 0, 0);
        return;
    default:
        func_00141D38(pbentley, gadget);
        return;
    }
}
