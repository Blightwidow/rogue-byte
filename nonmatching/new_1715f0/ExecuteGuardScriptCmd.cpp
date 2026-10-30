#include "sly2.h"
struct VT {
    char pad0[0x18];
    short delta18; short unused18; void (*fn1C)(void *, int, int, int, void *, int);
    char pad1[0x40 - 0x20];
    short delta40; short unused40; void (*fn44)(void *);
};
struct OBJ { char pad0[0xC]; VT *vt; };
struct PLAYER { char pad[0xF80]; int mode; };
struct EIGHT { char bytes[8]; };
struct CMD { unsigned op; int a; int b; int c; int d; float e; };
struct OBJ2 { char pad[8]; float value; };
struct GUARD {
    char pad0[0xC]; VT *vt; PLAYER *player; char pad1[0x30 - 0x14];
    CMD *labelBase; int object; CMD *current; float timer; int done; OBJ2 *source; float value48; int flag4C;
    char animref[4]; int ref54; int pad58; int ref5C;
};
struct GOAL { char pad0[0xC]; VT *vt; };
extern "C" {
void ApplyAseg(int, int, float, float, int, void *);
void BindAnimref(void *, void *);
void EnsureCrvExcludedRanges(int);
void EnsureSggAlarm__FP3SGGP5ALARM(int, int);
int FIsBasicDerivedFrom(int, int);
CMD *PcmdFindScriptLabel(CMD *, int);
int PloFindScriptObject(GUARD *, int);
void ResetAnimref(void *, void *);
void SetGoalTarget(void *, void *);
void TeleportGuardScript(GUARD *, QW, float);
void func_00171AF8(GUARD *, int, void *, void *);
void func_0017CDB8(void *, void *);
void func_0017D110(void *, void *);
int func_001EEFC0(GUARD *);
int func_001EF038(GUARD *);
char *func_00205438(PLAYER *, int);
void func_002562A8(void *);
extern float g_2dded0;
void ExecuteGuardScriptCmd(GUARD *self, CMD *cmd) {
    struct { QW vec; int target0; int target1; int pad18[2]; QW vec2; float sp30; CMD *sp34; int sp38; } L;
    switch (cmd->op) {
    case 0:
        self->object = PloFindScriptObject(self, cmd->a);
    default:
        break;
    case 1:
        *(EIGHT *)((char *)self->player + 0x2CC) = *(EIGHT *)&cmd->b;
        break;
    case 2:
        *(EIGHT *)((char *)self->player + 0x2D4) = *(EIGHT *)&cmd->b;
        break;
    case 3:
        func_00171AF8(self, PloFindScriptObject(self, cmd->a), &L.vec, &L.sp30);
        TeleportGuardScript(self, L.vec, L.sp30);
        break;
    case 4: {
        VT *vt = self->vt;
        L.sp34 = (CMD *)&cmd->a;
        vt->fn1C((char *)self + vt->delta18, 4, 0, 1, &L.sp34, 0);
        break;
    }
    case 5: {
        PLAYER *player = self->player;
        int mode = player->mode;
        if (mode == 2) {
            OBJ *obj = (OBJ *)func_00205438(player, 0xBB);
            VT *vt = obj->vt;
            vt->fn44((char *)obj + vt->delta40);
        } else if (mode < 3) {
            if (mode == -1) {
                OBJ *obj = (OBJ *)func_00205438(player, 0x9E);
                VT *vt = obj->vt;
                vt->fn44((char *)obj + vt->delta40);
            }
        } else if (mode == 3) {
            OBJ *obj = (OBJ *)func_00205438(player, 0xBC);
            VT *vt = obj->vt;
            vt->fn44((char *)obj + vt->delta40);
        }
        self->done = 1;
        break;
    }
    case 6: {
        int found = PloFindScriptObject(self, self->current->a);
        if (found != 0) {
            PLAYER *player = self->player;
            int mode = player->mode;
            if (mode == 0) {
                char *obj = func_00205438(player, 0xB8);
                func_0017CDB8(obj, &self->current->b);
                VT *vt = ((OBJ *)obj)->vt;
                vt->fn44(obj + vt->delta40);
                self->done = 1;
            } else if (mode == 1) {
                char *obj = func_00205438(player, 0xB9);
                func_0017D110(obj, &self->current->b);
                VT *vt = ((OBJ *)obj)->vt;
                vt->fn44(obj + vt->delta40);
                self->done = 1;
            } else if (mode == -1) {
                char *obj = func_00205438(player, 0xC0);
                *(int *)(obj + 0x30) = found;
                *(int *)(obj + 0x34) = cmd->b;
                *(int *)(obj + 0x58) = self->flag4C;
                if (self->flag4C == 0) EnsureCrvExcludedRanges(found);
                if (self->source != 0) *(float *)(obj + 0x38) = self->source->value;
                int other = cmd->c;
                if (other != mode) *(int *)(obj + 0x50) = PloFindScriptObject(self, other);
                VT *vt = ((OBJ *)obj)->vt;
                vt->fn44(obj + vt->delta40);
                self->done = 1;
            } else {
                self->done = 1;
            }
        }
        break;
    }
    case 7: {
        func_002562A8(&L.target0);
        CMD *current = self->current;
        int objectId = current->a;
        if (objectId == -1) {
            L.vec2 = *(QW *)&current->b;
            self->value48 = current->e;
        } else {
            int found = PloFindScriptObject(self, objectId);
            if (found != 0) {
                func_00171AF8(self, found, 0, &self->value48);
                if (FIsBasicDerivedFrom(found, 0xA) == 0)
                    L.target1 = found;
                else
                    L.target0 = found;
            }
        }
        PLAYER *player = self->player;
        int mode = player->mode;
        if (mode == -1) {
            char *obj = func_00205438(player, 0xBA);
            SetGoalTarget(obj, &L.target0);
            int other = cmd->d;
            if (other != mode) *(int *)(obj + 0xA8) = PloFindScriptObject(self, other);
            VT *vt = ((OBJ *)obj)->vt;
            *(float *)(obj + 0xB0) = cmd->e;
            *(int *)(obj + 0xBC) = self->flag4C;
            vt->fn44(obj + vt->delta40);
        }
        self->done = 1;
        break;
    }
    case 8:
        ApplyAseg(PloFindScriptObject(self, cmd->a), 0, 0.0f, 1.0f, 0, &L.sp38);
        break;
    case 10: {
        CMD *label = PcmdFindScriptLabel(self->labelBase, cmd->a);
        if (label != 0) self->current = label;
        break;
    }
    case 11:
        func_001EEFC0(self);
        break;
    case 12:
        func_001EF038(self);
        break;
    case 13: {
        int found = PloFindScriptObject(self, self->current->a);
        char *obj = func_00205438(self->player, 0xAC);
        *(int *)(obj + 0x60) = found;
        *(int *)(obj + 0x68) = 1;
        VT *vt = ((OBJ *)obj)->vt;
        *(int *)(obj + 0x64) = cmd->b;
        vt->fn44(obj + vt->delta40);
        self->done = 1;
        break;
    }
    case 14: {
        char *animref = self->animref;
        ResetAnimref(animref, self->player);
        self->ref54 = cmd->a;
        self->ref5C = cmd->b;
        BindAnimref(animref, self->player);
        PLAYER *player = self->player;
        if (player->mode == -1) {
            char *obj = func_00205438(player, 0x9D);
            *(void **)(obj + 0x40) = animref;
            VT *vt = ((OBJ *)obj)->vt;
            vt->fn44(obj + vt->delta40);
            self->done = 1;
        }
        break;
    }
    case 15:
        EnsureSggAlarm__FP3SGGP5ALARM(PloFindScriptObject(self, cmd->a), cmd->b);
        break;
    }
    self->timer = g_2dded0;
}
}
