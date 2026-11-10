#include "murray.h"
#include "sly2.h"
extern "C" {
struct ACT { int pad[3]; int field; };
extern ACT B_002DEB30;
void bevy_camera_follow_activity(ACT *, int, void *);
void SpendJtGadgetPower(void *, int);
void StartAttach(void *, int, void *, int);
void func_00141D38(void *, int);
void SetMurrayState(void *, int);
void func_001B8D30(void *, int);
}
extern "C" void UseMurrayGadget(MURRAY *pmurray, int gadget)
{
    B_002DEB30.field = gadget;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, pmurray);
    void *plo;
    switch (gadget) {
    case 0x14:
        SpendJtGadgetPower(pmurray, gadget);
        SetMurrayState(pmurray, 0xC);
        func_001B8D30(pmurray, 0);
        func_001B8D30(pmurray, 1);
        return;
    case 0xF:
        pmurray->field_0x9BC = gadget;
        pmurray->field_0x130C = pmurray->field_0x1AC4;
        StartAttach((char *)pmurray + 0x4C0, 0xB, 0, 0);
        return;
    case 0x13:
        SpendJtGadgetPower(pmurray, gadget);
        pmurray->field_0x143C = 1;
        SetMurrayState(pmurray, 8);
        return;
    case 0x16:
        SpendJtGadgetPower(pmurray, gadget);
        pmurray->field_0x13E8 = 1;
        SetMurrayState(pmurray, 3);
        return;
    case 0x15:
        pmurray->field_0x9BC = 0x15;
        StartAttach((char *)pmurray + 0x4C0, 0xB, *(void **)((char *)pmurray + 0x10DC), 0);
        return;
    case 0x10:
        SetMurrayState(pmurray, 0x15);
        return;
    default:
        func_00141D38(pmurray, gadget);
        return;
    }
}
