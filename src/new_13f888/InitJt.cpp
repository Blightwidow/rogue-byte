#include "jt.h"
extern "C" {
void InitStep(void *);
void InitJmp(void *, void *);
void InitAttach(void *, void *);
void func_0019F3E8(void *, void *);
void InitJtZap(void *, void *);
void bevy_player_p15_binoc_default(void *, void *);
void CarryThrow_Init(void *, void *);
void InitJtPipe(void *, void *);
void func_00144638(void *, void *);
void SetAloInteract(void *, int, int);
}
// The `0x12F0 = 0x10F0 = 1` chain is two plain stores: 0x10F0 before the 0x10D4/0x10D8 float chain, 0x12F0 after the 0x1144 store. The
// scheduler keeps a store that needs no constant register last in source order, which puts 0x10F0 before 0x10D8 as in retail.
void InitJt(JT *pjt)
{
    InitStep(pjt);
    InitJmp((char *)pjt + 0x2C0, pjt);
    InitAttach((char *)pjt + 0x4C0, pjt);
    func_0019F3E8((char *)pjt + 0x9E0, pjt);
    InitJtZap((char *)pjt + 0xDF0, pjt);
    bevy_player_p15_binoc_default((char *)pjt + 0xF00, pjt);
    CarryThrow_Init((char *)pjt + 0x11B0, pjt);
    InitJtPipe((char *)pjt + 0xF50, pjt);
    func_00144638((char *)pjt + 0xFD0, pjt);
    pjt->field_0x103C = 20.0f;
    pjt->field_0x1048 = 125.0f;
    pjt->field_0x10F0 = 1;
    pjt->field_0x10D4 = pjt->field_0x10D8 = 1.0f;
    pjt->field_0x1138 = 1.5f;
    pjt->field_0x113C = 2.5f;
    pjt->field_0x1140 = 3.0f;
    pjt->field_0x1144 = 5.0f;
    pjt->fGadgetsAllowed = 1;
    pjt->field_0x1020 = 100.0f;
    pjt->nPowerMax = 100;
    pjt->field_0x1304 = -60.0f;
    pjt->focusMode = -1;
    pjt->focusKind = -1;
    pjt->sidDefault = -1;
    pjt->field_0x10C8 = -1;
    SetAloInteract(pjt, 0x3FFFFFF, 0);
    SetAloInteract(pjt, 0x10FF00, 8);
}
