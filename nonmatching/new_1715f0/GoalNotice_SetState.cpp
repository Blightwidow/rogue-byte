#include "sly2.h"
struct VT { char pad[0x40]; short delta; short unused; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct RANGE { char pad[0x60]; float lo; float hi; };
struct PLAYER { char pad0[0x3CC]; char *alert; char pad1[0xF04 - 0x3D0]; float cooldown; char pad2[0xF64 - 0xF08]; void *link; };
struct NOTICE {
    char pad0[0x10]; PLAYER *player; char pad1[0x18 - 0x14]; char popSlot[0x18]; void *target; unsigned state; float since; RANGE *range;
    char pad2[0x44 - 0x40]; void *zone; char pad3[0x50 - 0x48]; QW lastPos;
};
extern "C" {
float GRandInRange(float, float);
void Goal_Pop(void *);
QW PosLoWorld(void *);
void *PpathzoneFindPos(QW, int);
void SetAlertState(char *, int);
void SetGoalTarget(void *, void *);
void func_00154038(void *, void *, int);
char *func_00205438(PLAYER *, int);
void func_00208540(void *, int);
void func_002562A8(void *);
extern float g_2dded0[];
void GoalNotice_SetState(NOTICE *self, unsigned state) {
    struct { int first; int second; int pad[2]; QW vec; } target;
    if (state != self->state) {
        Goal_Pop(self->popSlot);
        if (self->state == 1) {
            RANGE *range = self->range;
            float now = g_2dded0[0];
            self->player->cooldown = now + GRandInRange(range->lo, range->hi);
            self->range = 0;
        }
        self->state = state;
        self->since = g_2dded0[0];
        switch (state) {
        case 0: {
            OBJ *obj = (OBJ *)func_00205438(self->player, 0xB3);
            VT *vt = obj->vt;
            vt->fn((char *)obj + vt->delta);
            return;
        }
        case 1: {
            char *obj = func_00205438(self->player, 0xA4);
            *(void **)(obj + 0x30) = self->target;
            *(RANGE **)(obj + 0x3C) = self->range;
            self->player->cooldown = 3.4028235e38f;
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            SetAlertState(self->player->alert, 3);
            return;
        }
        case 2: {
            char *obj = func_00205438(self->player, 0xAD);
            VT *vt = ((OBJ *)obj)->vt;
            *(void **)(obj + 0x38) = self->target;
            vt->fn(obj + vt->delta);
            SetAlertState(self->player->alert, 4);
            return;
        }
        case 3: {
            char *obj = func_00205438(self->player, 0xBA);
            *(int *)(obj + 0xC0) = 1;
            *(int *)(obj + 0x38) = 0x1C;
            QW posA = PosLoWorld(self->target);
            QW posB = PosLoWorld(self->target);
            func_002562A8(&target);
            target.vec = posB;
            SetGoalTarget(obj, &target);
            VT *vt = ((OBJ *)obj)->vt;
            *(void **)(obj + 0xA8) = self->target;
            *(int *)(obj + 0xAC) = 1;
            vt->fn(obj + vt->delta);
            self->lastPos = posA;
            self->zone = PpathzoneFindPos(posA, 1);
            return;
        }
        case 4: {
            char *obj = func_00205438(self->player, 0x9D);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x3C) = 0xD;
            vt->fn(obj + vt->delta);
            func_00154038(self->player->link, self->target, 0);
            func_00208540(self->player, 0);
            return;
        }
        case 5: {
            char *obj = func_00205438(self->player, 0x9E);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x3C) = 1;
            vt->fn(obj + vt->delta);
            break;
        }
        }
    }
}
}
