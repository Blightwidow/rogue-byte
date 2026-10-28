#include "sly2.h"
struct VT {
    char p0[8]; short d8; short i8; void (*f8)(void *);
    short d10; short i10; void (*f10)(void *);
    char p1[0x2C0 - 0x18]; short d2c0; short i2c0; void (*f2c0)(void *, int);
};
struct Obj { char p0[0xC]; VT *vt; };
struct Input { char p0[0xC]; VT *vt; char p1[0x30]; int *pkind; };
struct Jt { char p0[0xC]; VT *vt; char p1[0x4C8 - 0x10]; int attachKind; char p2[0x1084 - 0x4CC]; Input *psource; char p3[0x11B4 - 0x1088]; int field11b4; };
extern "C" {
void GoalStack_Clear(void *);
int bevy_player_p15_binoc_active(void *);
void SetBinocState(void *, int);
}
void func_00143DE8(Jt *pjt, Input *pnew)
{
    Input *pold = pjt->psource;
    if (pnew == pold)
        return;
    if (pold != 0) {
        pold->vt->f10((char *)pold + pold->vt->d10);
        if (pjt->attachKind < 7) {
            if (pjt->attachKind >= 5)
                pjt->vt->f2c0((char *)pjt + pjt->vt->d2c0, 0);
        }
    }
    pjt->psource = pnew;
    if (pnew == 0)
        return;
    pnew->vt->f8((char *)pnew + pnew->vt->d8);
    GoalStack_Clear((char *)pjt + 0x26C);
    if (bevy_player_p15_binoc_active(pjt))
        SetBinocState((char *)pjt + 0xF00, -1);
    if (pjt->field11b4 != -1 && *(int *)pjt->psource->pkind != 0x1E)
        pjt->vt->f2c0((char *)pjt + pjt->vt->d2c0, 0);
}
