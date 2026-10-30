#include "sly2.h"
struct VT { char pad[0x40]; short delta; short unused; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct CMD { int type; int pad4[3]; int arg; float argf; char rest[0x70 - 0x18]; } __attribute__((aligned(16)));
struct PAYLOAD { char bytes[0x60]; } __attribute__((aligned(16)));
struct PLAYER { char pad0[0x4B0]; QW q4B0; char pad1[0xF68 - 0x4C0]; int f68; int pad6C; QW q70; char pad2[0x108C - 0xF80]; int f108C; };
struct BRAIN { char pad0[0x10]; PLAYER *player; char pad1[0x18 - 0x14]; char popSlot[0x18]; CMD cmd; char pad2[0xA0 - 0xA0]; float since; float next; };
extern "C" {
float GRandInRange(float, float);
int GoalBrain_FCmdEqual(CMD *, CMD *);
void Goal_Pop(void *);
void SetGuardScript(char *, int, int, int);
void SetSearchGoal(char *, int);
char *func_00205438(PLAYER *, int);
void func_00208540(PLAYER *, int);
extern float D_FLT_002BE618[2];
extern float g_2dded0;
void GoalBrain_SetCommand(BRAIN *self, CMD *cmd) {
    if (GoalBrain_FCmdEqual(cmd, &self->cmd) == 0) {
        Goal_Pop(self->popSlot);
        self->cmd = *cmd;
        self->since = g_2dded0;
        int notify = 0;
        int id;
        switch (cmd->type) {
        case 5: {
            notify = 1;
            char *obj = func_00205438(self->player, 0xA9);
            SetGuardScript(obj, cmd->arg, 1, 0);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 1: {
            notify = 1;
            char *obj = func_00205438(self->player, 0xAA);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 3: {
            char *obj = func_00205438(self->player, 0x9D);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x3C) = 0xB;
            *(int *)(obj + 0x38) = cmd->arg;
            vt->fn(obj + vt->delta);
            break;
        }
        case 4: {
            char *obj = func_00205438(self->player, 0xA5);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x30) = cmd->arg;
            vt->fn(obj + vt->delta);
            break;
        }
        case 2: {
            notify = 1;
            char *obj = func_00205438(self->player, 0xAB);
            SetSearchGoal(obj, cmd->arg);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 9: {
            char *obj = func_00205438(self->player, 0xA1);
            *(PAYLOAD *)(obj + 0x50) = *(PAYLOAD *)((char *)cmd + 0x10);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 10: {
            char *obj = func_00205438(self->player, 0xA2);
            *(PAYLOAD *)(obj + 0x50) = *(PAYLOAD *)((char *)cmd + 0x10);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 11: {
            char *obj = func_00205438(self->player, 0xA3);
            *(PAYLOAD *)(obj + 0x50) = *(PAYLOAD *)((char *)cmd + 0x10);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            notify = 1;
            break;
        }
        case 8: {
            char *obj = func_00205438(self->player, 0xAF);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 6: {
            char *obj = func_00205438(self->player, 0xB0);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x3C) = self->cmd.arg;
            vt->fn(obj + vt->delta);
            break;
        }
        case 7: {
            char *obj = func_00205438(self->player, 0xB1);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x5C) = cmd->arg;
            vt->fn(obj + vt->delta);
            break;
        }
        case 12: {
            char *obj = func_00205438(self->player, 0xB2);
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn(obj + vt->delta);
            break;
        }
        case 13:
            id = 0xB4;
            goto sharedTail;
        case 14:
            id = 0xB6;
        sharedTail: {
            char *obj = func_00205438(self->player, id);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x38) = cmd->arg;
            vt->fn(obj + vt->delta);
            break;
        }
        case 15: {
            char *obj = func_00205438(self->player, 0xAE);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x38) = self->player->f108C;
            vt->fn(obj + vt->delta);
            break;
        }
        case 16: {
            notify = 1;
            char *obj = func_00205438(self->player, 0xB7);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x30) = self->player->f68;
            *(QW *)(obj + 0x40) = self->player->q70;
            vt->fn(obj + vt->delta);
            break;
        }
        case 17: {
            char *obj = func_00205438(self->player, 0x9E);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x3C) = 0x1A;
            *(int *)(obj + 0x38) = cmd->arg;
            vt->fn(obj + vt->delta);
            float now = g_2dded0;
            self->next = now + GRandInRange(D_FLT_002BE618[0], D_FLT_002BE618[1]);
            break;
        }
        case 18: {
            char *obj = func_00205438(self->player, 0xBD);
            VT *vt = ((OBJ *)obj)->vt;
            *(int *)(obj + 0x38) = cmd->arg;
            *(float *)(obj + 0x40) = cmd->argf;
            vt->fn(obj + vt->delta);
            break;
        }
        case 19: {
            char *obj = func_00205438(self->player, 0xBF);
            VT *vt = ((OBJ *)obj)->vt;
            *(QW *)(obj + 0x40) = self->player->q4B0;
            vt->fn(obj + vt->delta);
            break;
        }
        }
        if (notify != 0) func_00208540(self->player, 0);
    }
}
}
