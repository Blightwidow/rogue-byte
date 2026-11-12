#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"
#include "goal.h"

struct ZONEB { char pad0[0x10]; int pzone; };
struct ZONEA { char pad0[0xDC]; ZONEB *pb; };
struct DIVISOR { char pad0[0x20]; float gDivisor; };
struct NOTICESTEP {
    char pad0[0xE8];
    ZONEA *pa;
    char padEC[0x314 - 0xEC];
    float gNear;
    float gFar;
    char pad31C[0xF40 - 0x31C];
    int fActive;
    float tMin;
    char padF48[0xFBC - 0xF48];
    int kind;
    char padFC0[4];
    DIVISOR *pdivisor;
};
struct TARGET { int a[4]; QW pos; };
struct GOALNOTICE : GOAL {
    void *target;
    int state;
    char pad38[0xC];
    int pzoneLast;
    char pad48[0x8];
    QW posLast;
};

extern "C" {
void func_001EEF98();
int func_001EF0A8(GOALNOTICE *);
int func_00209098(NOTICESTEP *);
int func_00176060(GOALNOTICE *);
int func_00175FF0(GOALNOTICE *);
int func_00175D00(GOALNOTICE *);
void GoalNotice_SetState(GOALNOTICE *, int);
QW PosLoWorld(void *);
int PpathzoneFindPos(QW, int);
void func_002562A8(TARGET *, int);
void SetGoalTarget(GOAL *, TARGET *);
int FGoalReactDone(GOAL *);
int FGoalAnimDone(GOAL *);
int func_0017B7F8(GOAL *);
void func_0020B140(NOTICESTEP *, void *);
}
extern float D_FLT_002BE614;
extern float g_2dded0;
extern float B_FLT_003E1BE8;

static inline int ZoneOf(NOTICESTEP *pstep)
{
    ZONEA *pa = pstep->pa;
    ZONEB *pb = 0;
    if (pa != 0)
        pb = pa->pb;
    int pzone = 0;
    if (pb != 0)
        pzone = pb->pzone;
    return pzone;
}

static inline int FMoved(QW current, QW last)
{
    return D_FLT_002BE614 < LaneX(SqrtX(SquaredLength(VectorSub(current, last))));
}

extern "C" void GoalNotice_Update(GOALNOTICE *pgoal)
{
    TARGET target;
    func_001EEF98();
    int state;
    do {
        state = pgoal->state;
        switch (state) {
        case 0:
        case 3:
            if (func_001EF0A8(pgoal) == 0) {
                if (func_00209098((NOTICESTEP *)pgoal->pstep) != 0) {
                    GoalNotice_SetState(pgoal, 5);
                } else if (func_00176060(pgoal) != 0) {
                    GoalNotice_SetState(pgoal, 4);
                } else if (func_00175FF0(pgoal) != 0) {
                    GoalNotice_SetState(pgoal, 1);
                } else if (func_00175D00(pgoal) != 0) {
                    GoalNotice_SetState(pgoal, 2);
                } else {
                    QW pos = PosLoWorld(pgoal->target);
                    QW posStep = PosLoWorld(pgoal->pstep);
                    float distance = LaneX(SqrtX(SquaredLengthXy(VectorSub(pos, posStep))));
                    if (((NOTICESTEP *)pgoal->pstep)->kind == 8 || ((NOTICESTEP *)pgoal->pstep)->kind == 13) {
                        if (((NOTICESTEP *)pgoal->pstep)->pdivisor != 0)
                            distance /= ((NOTICESTEP *)pgoal->pstep)->pdivisor->gDivisor;
                    }
                    int pzone = PpathzoneFindPos(pos, 1);
                    if (pgoal->state != 0) {
                        if (pgoal->state == 3) {
                            NOTICESTEP *pstepFar = (NOTICESTEP *)pgoal->pstep;
                            if (distance < pstepFar->gNear && pzone == ZoneOf(pstepFar)) {
                                GoalNotice_SetState(pgoal, 0);
                            } else if (pgoal->pzoneLast != pzone || FMoved(pos, pgoal->posLast)) {
                                pgoal->pzoneLast = pzone;
                                pgoal->posLast = pos;
                                func_002562A8(&target, pzone);
                                target.pos = pos;
                                SetGoalTarget(pgoal->pgoalChild, &target);
                            }
                        }
                    } else {
                        NOTICESTEP *pstepNear = (NOTICESTEP *)pgoal->pstep;
                        if (pstepNear->gFar < distance || pzone != ZoneOf(pstepNear))
                            GoalNotice_SetState(pgoal, 3);
                    }
                }
            }
            break;
        case 1:
            if (func_00209098((NOTICESTEP *)pgoal->pstep) != 0) {
                GoalNotice_SetState(pgoal, 5);
            } else if (func_001EF0A8(pgoal) == 0) {
                if (FGoalReactDone(pgoal->pgoalChild) != 0)
                    GoalNotice_SetState(pgoal, 0);
            }
            break;
        case 2:
            if (func_00209098((NOTICESTEP *)pgoal->pstep) != 0) {
                GoalNotice_SetState(pgoal, 5);
            } else if (func_001EF0A8(pgoal) == 0) {
                if (func_0017B7F8(pgoal->pgoalChild) != 0)
                    GoalNotice_SetState(pgoal, 0);
            }
            break;
        case 4:
            if (func_001EF0A8(pgoal) == 0 && FGoalAnimDone(pgoal->pgoalChild) != 0)
                GoalNotice_SetState(pgoal, -1);
            break;
        case 5:
            if (func_001EF0A8(pgoal) == 0 && func_00209098((NOTICESTEP *)pgoal->pstep) == 0)
                GoalNotice_SetState(pgoal, 3);
            break;
        }
    } while (state != pgoal->state);
    NOTICESTEP *pstepEnd = (NOTICESTEP *)pgoal->pstep;
    if (pstepEnd->fActive != 0 && state < 4 && state >= 0 && pstepEnd->tMin <= g_2dded0 && B_FLT_003E1BE8 <= g_2dded0)
        func_0020B140(pstepEnd, pgoal->target);
}
