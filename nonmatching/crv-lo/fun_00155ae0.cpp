#include "sly2.h"
struct Vt_155AE0 { char pad0[0x40]; short d40; short i40; void (*f44)(void *); };
struct Ent_155AE0 { char pad0[0xC]; Vt_155AE0 *vt; char pad1[0x30 - 0x10]; int f30; char pad2[0x38 - 0x34]; int f38; int f3C; int f40; char pad3[0xC0 - 0x44]; int fC0; char pad4[4]; int fC8; };
struct Crv_155AE0 { char pad0[0xE8]; int fE8; char pad1[0xF4 - 0xEC]; QW *fF4; };
struct Owner_155AE0 { char pad0[0xF04]; float fF04; };
struct Goal_155AE0 { char pad0[0x10]; Owner_155AE0 *owner; char pad1[0x18 - 0x14]; char child[0x18]; int state; float t; float f38; float f3C; void *target; char pad2[0x4C - 0x44]; int f4C; int f50; char *f54; };
extern "C" {
float GRandInRange(float, float);
void GoalFollowCrv_SetCrv(void *, void *, int);
void Goal_Pop(void *);
void MeasureCrv(void *);
QW PosLoWorld(void *);
float atan2f(float, float);
void *func_00155A68(void *);
Ent_155AE0 *func_00205438(void *, int);
void func_00209818(void *, float);
void func_0020AC28(void *, int, int, QW);
extern QW g_2a2dd0;
extern float g_2dded0;
void func_00155AE0(Goal_155AE0 *self, int newState) {
    QW dead;
    int old = self->state;
    if (newState != old) {
        switch (old) {
        case 1:
            func_0020AC28(self->owner, 0, 0, g_2a2dd0);
            break;
        case 3: {
            char *range = self->f54;
            float now = g_2dded0;
            self->owner->fF04 = now + GRandInRange(*(float *)(range + 0x60), *(float *)(range + 0x64));
            self->f54 = 0;
            break; }
        }
        Goal_Pop(self->child);
        self->state = newState;
        self->t = g_2dded0;
        switch (newState) {
        case 0: {
            self->target = func_00155A68(self);
            Ent_155AE0 *ent = func_00205438(self->owner, 0x9D);
            ent->f3C = 0xB;
            dead = PosLoWorld(self->target);
            int token0, token1, xBits, yBits;
            asm("qmtc2.ni %1, vf2" : "=r"(token0) : "r"(PosLoWorld(self->owner)));
            asm("lqc2 vf1, 0(%1)\n\tvsub.xyzw vf1, vf1, vf2" : "=r"(token1) : "r"(&dead), "r"(token0) : "memory");
            asm("qmfc2.ni %0, vf1" : "=r"(xBits) : "r"(token1));
            asm("prot3w %0, %1" : "=r"(yBits) : "r"(xBits));
            func_00209818((char *)self->owner + 0xFD0, atan2f(*(float *)&yBits, *(float *)&xBits) + 3.1415927f);
            ent->vt->f44((char *)ent + ent->vt->d40);
            self->f3C = 3.4028235e38f;
            break; }
        case 1: {
            Ent_155AE0 *ent = func_00205438(self->owner, 0x9E);
            ent->f38 = self->f4C;
            ent->vt->f44((char *)ent + ent->vt->d40);
            break; }
        case 2: {
            Ent_155AE0 *ent = func_00205438(self->owner, 0xA7);
            Crv_155AE0 *crv = *(Crv_155AE0 **)((char *)self->owner + 0x294);
            crv->fE8 = newState;
            QW *first = crv->fF4;
            *first = PosLoWorld(self->owner);
            crv->fF4[1] = PosLoWorld(self->target);
            MeasureCrv(crv);
            GoalFollowCrv_SetCrv(ent, crv, 0);
            ent->fC0 = 8;
            ent->fC8 = self->f4C;
            ent->f40 = 1;
            ent->vt->f44((char *)ent + ent->vt->d40);
            break; }
        case 3: {
            Ent_155AE0 *ent = func_00205438(self->owner, 0xA4);
            ent->f3C = (int)self->f54;
            ent->f30 = self->f4C;
            ent->vt->f44((char *)ent + ent->vt->d40);
            self->owner->fF04 = 3.4028235e38f;
            self->f50 = self->f50 + 1;
            break; }
        }
    }
}
}
