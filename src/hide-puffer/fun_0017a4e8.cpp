#include "sly2.h"
struct Goal_17A4E8 { char pad0[0x10]; char *owner; };
extern "C" {
extern char B_003DD490;
void func_00174950(Goal_17A4E8 *);
void GoalFlinch_SetState(Goal_17A4E8 *, int);
void ResetSensorStates(int);
QW PosLoWorld(char *);
void ReplaceSwHitFx(char *, int, QW, char *, char *);
void func_0017A4E8(Goal_17A4E8 *goal) {
    func_00174950(goal);
    GoalFlinch_SetState(goal, 0);
    ResetSensorStates(*(int *)(goal->owner + 0xF64));
    ReplaceSwHitFx(&B_003DD490, 1, PosLoWorld(goal->owner), goal->owner, goal->owner + 0x35C);
}
}
