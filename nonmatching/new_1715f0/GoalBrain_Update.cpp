#include "sly2.h"
struct VT { char pad[0x268]; short delta268; short u268; int (*fn26C)(char *); char pad2[0x2C0 - 0x270]; short delta2C0; short u2C0; int (*fn2C4)(char *, char *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct CMD { unsigned type; int pad4[3]; int arg; float argf; char rest[0x70 - 0x18]; } __attribute__((aligned(16)));
struct PLAYER { char pad[0xC]; VT *vt; char pad2[0x38C - 0x10]; int f38C; };
struct GOALX { char pad0[0x30]; OBJ *target; char pad1[0x44 - 0x34]; int f44; char pad2[0x50 - 0x48]; int f50; char pad3[0x5C - 0x54]; int f5C; };
struct BRAIN { char pad0[0x10]; PLAYER *player; GOALX *goal; char pad1[0x30 - 0x18]; CMD cmd; char pad2[0xA4 - 0xA0]; float retryAt; };
extern "C" {
int FGoalAnimDone(void *);
int FGoalNoticeDone(void *);
int FGuardScriptDone(void *);
int FIsBasicDerivedFrom(void *, int);
void GoalBrain_AbsorbDamage(BRAIN *, int, int);
void GoalBrain_ChooseNextCommand(BRAIN *);
int GoalBrain_FCmdEqual(CMD *, CMD *);
int GoalBrain_FGotoTargetInWorld(BRAIN *);
void GoalBrain_SetCommand(BRAIN *, CMD *);
void HitFx_Remove(int);
int PhitfxChooseForGuard(PLAYER *, int);
QW PosLoWorld(void *);
void SetSearchGoal(void *, int);
int SpawnSwHitFx(void *, int, QW, void *);
int func_00172550(void *);
int func_00174898(int);
int func_00177D20(BRAIN *);
int func_0017A9C0(void *);
int func_0017DE40(void *);
int func_0017EAE8(void *);
void func_001EEF98();
int func_001EF0A8(BRAIN *);
int func_00208B38(PLAYER *, int);
float func_00208BB0(PLAYER *);
extern char B_003DD490[];
extern float g_2dded0;
void GoalBrain_Update(BRAIN *self) {
    CMD old;
    CMD next;
    func_001EEF98();
    while (func_001EF0A8(self) == 0) {
        old = self->cmd;
        switch (old.type) {
        case 1:
        case 16:
        case 17:
            memset(&next, 0, 0x70);
            if (func_00177D20(self) == 0) {
                PLAYER *player = self->player;
                int target = player->vt->fn2C4((char *)player + player->vt->delta2C0, (char *)player);
                if (target != 0) {
                    if (func_00208B38(self->player, target) != 0) {
                        next.type = 0x12;
                        next.arg = target;
                        next.argf = func_00208BB0(self->player);
                    } else {
                        next.arg = target;
                        next.type = 3;
                    }
                } else {
                    int fx = PhitfxChooseForGuard(self->player, 0);
                    if (fx != 0) {
                        next.arg = fx;
                        next.type = 2;
                    } else {
                        unsigned type = self->cmd.type;
                        if (type == 0x11 && g_2dded0 < self->retryAt) {
                            next.type = type;
                        } else {
                            next.type = GoalBrain_FGotoTargetInWorld(self) == 0 ? 1 : 0x10;
                        }
                    }
                }
            } else {
                next.type = 0xC;
            }
            GoalBrain_SetCommand(self, &next);
            break;
        case 2:
            if (func_00177D20(self) != 0) {
                memset(&next, 0, 0x70);
                next.type = 0xC;
                GoalBrain_SetCommand(self, &next);
            } else {
                PLAYER *player = self->player;
                int target = player->vt->fn2C4((char *)player + player->vt->delta2C0, (char *)player);
                if (target != 0) {
                    memset(&next, 0, 0x70);
                    if (func_00208B38(self->player, target) != 0) {
                        next.type = 0x12;
                        next.arg = target;
                        next.argf = func_00208BB0(self->player);
                    } else {
                        next.arg = target;
                        next.type = 3;
                    }
                    GoalBrain_SetCommand(self, &next);
                } else {
                    GOALX *goal = self->goal;
                    int current = goal->f44;
                    int chosen = PhitfxChooseForGuard(self->player, current);
                    if (chosen != current) {
                        SetSearchGoal(goal, chosen);
                    } else if (func_00172550(goal) != 0) {
                        memset(&next, 0, 0x70);
                        next.type = 1;
                        GoalBrain_SetCommand(self, &next);
                    }
                }
            }
            break;
        case 3:
            if (func_00177D20(self) != 0) {
                memset(&next, 0, 0x70);
                next.type = 0xC;
                GoalBrain_SetCommand(self, &next);
            } else if (FGoalAnimDone(self->goal) != 0) {
                memset(&next, 0, 0x70);
                next.type = FIsBasicDerivedFrom(self->player, 0x3B) != 0 ? 0xD : 4;
                next.arg = self->cmd.arg;
                GoalBrain_SetCommand(self, &next);
            }
            break;
        case 5:
            if (FGuardScriptDone(self->goal) != 0) GoalBrain_ChooseNextCommand(self);
            break;
        case 4: {
            GOALX *goal = self->goal;
            if (func_00177D20(self) != 0) {
                memset(&next, 0, 0x70);
                next.type = 0xC;
                GoalBrain_SetCommand(self, &next);
            } else if (FGoalNoticeDone(goal) == 0) {
                PLAYER *player = self->player;
                int target = player->vt->fn2C4((char *)player + player->vt->delta2C0, (char *)player);
                if (target != self->player->f38C) {
                    memset(&next, 0, 0x70);
                    if (target != 0) {
                        if (func_00208B38(self->player, target) != 0) {
                            next.type = 0x12;
                            next.arg = target;
                            next.argf = func_00208BB0(self->player);
                        } else {
                            next.arg = target;
                            next.type = 3;
                        }
                    } else {
                        next.type = 1;
                        OBJ *other = goal->target;
                        if (other != 0) {
                            if (FIsBasicDerivedFrom(other, 0x34) != 0) {
                                if (other->vt->fn26C((char *)other + other->vt->delta268) == 2) {
                                    int victim = func_00174898(*(int *)((char *)other + 0xE20));
                                    if (victim != 0) {
                                        if (victim != (int)self->player) {
                                            next.arg = victim;
                                            next.type = 0x11;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    GoalBrain_SetCommand(self, &next);
                }
            } else {
                memset(&next, 0, 0x70);
                next.type = 1;
                GoalBrain_SetCommand(self, &next);
            }
            break;
        }
        case 0:
            memset(&next, 0, 0x70);
            next.type = 1;
            GoalBrain_SetCommand(self, &next);
            break;
        case 12:
            if (func_00177D20(self) == 0) {
                memset(&next, 0, 0x70);
                next.type = 1;
                GoalBrain_SetCommand(self, &next);
            }
            break;
        case 8:
            if (FGoalAnimDone(self->goal) != 0) {
                int fx = SpawnSwHitFx(B_003DD490, 0, PosLoWorld(self->player), self->player);
                memset(&next, 0, 0x70);
                next.type = 2;
                next.arg = fx;
                GoalBrain_SetCommand(self, &next);
                HitFx_Remove(fx);
            }
            break;
        case 7: {
            GOALX *goal = self->goal;
            if (FGoalAnimDone(goal) != 0) {
                int state = goal->f50;
                if (state != -1) {
                    if (state == 3) GoalBrain_ChooseNextCommand(self);
                } else {
                    GoalBrain_AbsorbDamage(self, -0x32, goal->f5C);
                    if (self->cmd.type == 7) GoalBrain_ChooseNextCommand(self);
                }
            }
            break;
        }
        case 6:
            if (func_0017A9C0(self->goal) != 0) GoalBrain_ChooseNextCommand(self);
            break;
        case 9:
        case 10:
            if (FGoalAnimDone(self->goal) != 0) GoalBrain_ChooseNextCommand(self);
            break;
        case 19:
            if (func_0017EAE8(self->goal) != 0) GoalBrain_ChooseNextCommand(self);
            break;
        case 18:
            if (func_0017DE40(self->goal) != 0) GoalBrain_ChooseNextCommand(self);
            break;
        default:
            break;
        }
        if (GoalBrain_FCmdEqual(&self->cmd, &old) != 0) break;
    }
}
}
