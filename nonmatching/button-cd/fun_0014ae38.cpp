#include "sly2.h"
struct Vt_14AE38 { char pad0[0x40]; short d40; short i40; void (*f44)(void *); char pad1[0x118 - 0x48]; short d118; short i118; void (*f11C)(void *, QW, void *); short d120; short i120; void (*f124)(void *, QW, void *); };
struct Ent_14AE38 { char pad0[0xC]; Vt_14AE38 *vt; char pad1[0x30 - 0x10]; int f30; char pad2[0x38 - 0x34]; int f38; int f3C; int f40; char pad3[0x50 - 0x44]; QW f50; char pad4[0x64 - 0x60]; float f64; int f68; char pad5[0xC0 - 0x6C]; int fC0; char pad6[4]; int fC8; };
struct Crv_14AE38 { char pad0[0xE8]; int fE8; char pad1[0xF4 - 0xEC]; QW *fF4; };
struct Owner_14AE38 { char pad0[0xC]; Vt_14AE38 *vt; char pad1[0xF04 - 0x10]; float fF04; };
struct Goal_14AE38 { char pad0[0x10]; Owner_14AE38 *owner; char pad1[0x18 - 0x14]; char child[0x18]; int state; float t; char pad2[0x44 - 0x38]; char *f44; };
extern "C" {
float GRandInRange(float, float);
void GoalFollowCrv_SetCrv(void *, void *, int);
void Goal_Pop(void *);
void MeasureCrv(void *);
QW PosLoWorld(void *);
int PpoSwFocusBase(void *);
void SetSoCnstrForce(void *, int);
void SetSoCnstrTorque(void *, int);
void *func_0014AE18(void *);
Ent_14AE38 *func_00205438(void *, int);
void func_0020AC28(void *, int, int, QW);
extern char B_003DD490[];
extern QW g_2a2dd0;
extern float g_2dded0;
void func_0014AE38(Goal_14AE38 *self, int newState) {
    int old = self->state;
    if (newState != old) {
        switch (old) {
        case 0:
            func_0020AC28(self->owner, 0, 0, g_2a2dd0);
            break;
        case 1:
        case -1:
            SetSoCnstrForce(self->owner, 1);
            SetSoCnstrTorque(self->owner, 1);
            break;
        case 3: {
            char *range = self->f44;
            float now = g_2dded0;
            self->owner->fF04 = now + GRandInRange(*(float *)(range + 0x60), *(float *)(range + 0x64));
            self->f44 = 0;
            break; }
        }
        Goal_Pop(self->child);
        self->state = newState;
        self->t = g_2dded0;
        Ent_14AE38 *ent;
        switch (newState) {
        case 0:
            ent = func_00205438(self->owner, 0x9E);
            ent->f38 = PpoSwFocusBase(B_003DD490);
            ent->vt->f44((char *)ent + ent->vt->d40);
            {
                Owner_14AE38 *owner = self->owner;
                owner->vt->f11C((char *)owner + owner->vt->d118, g_2a2dd0, owner);
                owner = self->owner;
                owner->vt->f124((char *)owner + owner->vt->d120, g_2a2dd0, owner);
                int *zero = (int *)((char *)self->owner + 0x190);
                zero[1] = 0;
                zero[2] = 0;
                zero[0] = 0;
            }
            return;
        case 1: {
            Crv_14AE38 *crv = *(Crv_14AE38 **)((char *)self->owner + 0x294);
            crv->fE8 = 2;
            QW *first = crv->fF4;
            *first = PosLoWorld(self->owner);
            QW *second = crv->fF4;
            second[1] = PosLoWorld(func_0014AE18(self));
            MeasureCrv(crv);
            ent = func_00205438(self->owner, 0xA7);
            GoalFollowCrv_SetCrv(ent, crv, 0);
            ent->f64 = 25.0f;
            ent->fC0 = 8;
            ent->f40 = 1;
            ent->fC8 = PpoSwFocusBase(B_003DD490);
            ent->vt->f44((char *)ent + ent->vt->d40);
            self->owner->fF04 = g_2dded0;
            SetSoCnstrForce(self->owner, 0);
            SetSoCnstrTorque(self->owner, 0);
            return; }
        case 2:
            ent = func_00205438(self->owner, 0xAC);
            ent->f50 = PosLoWorld(func_0014AE18(self));
            ent->f68 = 1;
            goto callFn;
        case 3:
            ent = func_00205438(self->owner, 0xA4);
            ent->f30 = *(int *)((char *)self->owner + 0x38C);
            ent->f3C = (int)self->f44;
            ent->vt->f44((char *)ent + ent->vt->d40);
            self->owner->fF04 = 3.4028235e38f;
            return;
        case 4:
            ent = func_00205438(self->owner, 0x9E);
            ent->f38 = PpoSwFocusBase(B_003DD490);
            ent->f3C = 1;
callFn:
            ent->vt->f44((char *)ent + ent->vt->d40);
            return;
        case -1:
            SetSoCnstrForce(self->owner, 0);
            SetSoCnstrTorque(self->owner, 0);
            break;
        }
    }
}
}
