#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"
#include "stepguard.h"
struct SEARCHBEH {
    char pad0[0x10];
    STEPGUARD *pguard;
    char pad14[4];
    void *pgoal;
    char pad1c[0x30 - 0x1C];
    int state;
    char pad34[4];
    float tRetarget;
    float tSwitch;
    char pad40[8];
    int fRequest;
};
struct GOAL {
    char pad0[0x10];
    QW pos;
};
extern "C" {
void func_001EEF98(SEARCHBEH *);
int func_001EF0A8(SEARCHBEH *);
int FGoalAnimDone(void *);
int func_00209098(STEPGUARD *);
void func_00209818(void *, float);
int func_00172658(SEARCHBEH *);
QW func_00172760(SEARCHBEH *);
void func_00172560(SEARCHBEH *);
void func_00172F10(SEARCHBEH *);
void func_002562A8(GOAL *);
void SetGoalTarget(void *, GOAL *);
int GoalGoto_FArrived(void *);
int GoalGoto_FBlocked(void *);
void SetSearchState(SEARCHBEH *, int);
QW PosLoWorld(void *);
float atan2f(float, float);
extern float g_2dded0;
}

extern "C" void UpdateSearchBeh(SEARCHBEH *pbeh)
{
    func_001EEF98(pbeh);
    while (!func_001EF0A8(pbeh)) {
        int state = pbeh->state;
        switch (state) {
        case 0:
            if (FGoalAnimDone(pbeh->pgoal))
                SetSearchState(pbeh, 1);
            break;
        case 1:
            if (func_00209098(pbeh->pguard)) {
                SetSearchState(pbeh, 5);
            } else if (pbeh->fRequest) {
                if (func_00172658(pbeh)) {
                    SetSearchState(pbeh, 2);
                    pbeh->fRequest = 0;
                } else {
                    QW target = func_00172760(pbeh);
                    GOAL goal;
                    func_002562A8(&goal);
                    goal.pos = target;
                    SetGoalTarget(pbeh->pgoal, &goal);
                    pbeh->fRequest = 0;
                }
            } else if (func_00172658(pbeh) || GoalGoto_FArrived(pbeh->pgoal) || GoalGoto_FBlocked(pbeh->pgoal)) {
                SetSearchState(pbeh, 2);
            }
            break;
        case 2:
            if (func_00209098(pbeh->pguard)) {
                SetSearchState(pbeh, 5);
            } else if (pbeh->fRequest) {
                if (func_00172658(pbeh)) {
                    func_00172560(pbeh);
                    pbeh->fRequest = 0;
                } else {
                    SetSearchState(pbeh, 1);
                    pbeh->fRequest = 0;
                }
            } else if (pbeh->tRetarget < g_2dded0 || FGoalAnimDone(pbeh->pgoal)) {
                SetSearchState(pbeh, 4);
            } else if (pbeh->tSwitch < g_2dded0) {
                SetSearchState(pbeh, 3);
            } else {
                QW offset = VectorSub(func_00172760(pbeh), PosLoWorld(pbeh->pguard));
                void *pxps = &pbeh->pguard->field_0xFD0;
                func_00209818(pxps, atan2f(LaneYInGeneralRegister(offset), LaneX(offset)));
            }
            break;
        case 3:
            if (func_00209098(pbeh->pguard)) {
                SetSearchState(pbeh, 5);
            } else if (pbeh->fRequest) {
                if (func_00172658(pbeh)) {
                    SetSearchState(pbeh, 2);
                    pbeh->fRequest = 0;
                } else {
                    SetSearchState(pbeh, 1);
                    pbeh->fRequest = 0;
                }
            } else if (pbeh->tRetarget < g_2dded0) {
                SetSearchState(pbeh, 4);
            } else {
                func_00172F10(pbeh);
            }
            break;
        case 5:
            if (!func_00209098(pbeh->pguard))
                SetSearchState(pbeh, 1);
            break;
        case 4:
            if (pbeh->fRequest) {
                if (func_00172658(pbeh)) {
                    SetSearchState(pbeh, 2);
                    pbeh->fRequest = 0;
                } else {
                    SetSearchState(pbeh, 1);
                    pbeh->fRequest = 0;
                }
            } else if (FGoalAnimDone(pbeh->pgoal)) {
                SetSearchState(pbeh, -1);
            }
            break;
        }
        if (pbeh->state == state)
            break;
    }
}
