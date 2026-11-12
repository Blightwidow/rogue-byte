#include "sly2.h"
#include "goal.h"
#include "vu0inline.h"
#include "ps2inline.h"
struct VT_17DE50 { char pad[0x2C0]; short delta; short pad2; int (*fn)(void *); };
struct OBJ_17DE50 { char pad[0xC]; VT_17DE50 *vt; };
struct GOAL_17DE50 : GOAL {
    int state;
    char pad_34[4];
    void *target;
    float sLast;
    float sRemaining;
};
extern "C" {
int FGoalAnimDone(void *);
QW PosLoWorld(void *);
void func_0017E0E0(GOAL_17DE50 *);
void func_0017E278(GOAL_17DE50 *, int);
QW func_001C1EC0(void *, QW);
void func_001EEF98(GOAL_17DE50 *);
int func_001EF0A8(GOAL_17DE50 *);
int func_00208B38(void *, int);
float func_00208BB0(void *);
int func_00209098(void *);
extern const float RO_002BE760;
extern const float RO_002BE764;
extern const float RO_002BE768;
extern float g_2dded0[2];
}
void func_0017DE50(GOAL_17DE50 *pgoal)
{
    int nState;
    func_001EEF98(pgoal);
    while (nState = pgoal->state, func_001EF0A8(pgoal) == 0) {
        switch (pgoal->state) {
        case 0:
            if (FGoalAnimDone(pgoal->pgoalChild) != 0)
                func_0017E278(pgoal, 1);
            break;
        case 1:
            if (func_00209098(pgoal->pstep) != 0)
                func_0017E278(pgoal, 2);
            else {
                float elapsed = g_2dded0[1];
                float remaining = pgoal->sRemaining - elapsed;
                pgoal->sRemaining = remaining;
                if (remaining <= 0.0f) {
                    OBJ_17DE50 *obj = (OBJ_17DE50 *)pgoal->pstep;
                    int result = obj->vt->fn((char *)obj + obj->vt->delta);
                    if (result == (int)pgoal->target && func_00208B38(pgoal->pstep, result) != 0)
                        pgoal->sRemaining = func_00208BB0(pgoal->pstep);
                    else
                        func_0017E278(pgoal, -1);
                }
            }
            break;
        case 2:
            if (func_00209098(pgoal->pstep) == 0)
                func_0017E278(pgoal, 1);
            break;
        }
        if (pgoal->state == nState)
            break;
    }
    if (pgoal->state != 1)
        return;
    {
        if (RO_002BE760 < g_2dded0[0] - pgoal->sLast) {
            int near = 0;
            void *anim = (char *)pgoal->pgoalChild + 0x40;
            QW second = func_001C1EC0(anim, PosLoWorld(pgoal->pstep));
            QW delta = VectorSub(PosLoWorld(pgoal->pstep), second);
            if (LaneX(SqrtX(SquaredLengthXy(delta))) < RO_002BE764)
                near = 1;
            else {
                QW guardPosition = PosLoWorld(pgoal->pstep);
                QW targetPosition = PosLoWorld(pgoal->target);
                if (LaneX(SqrtX(SquaredLengthXy(VectorSub(guardPosition, targetPosition)))) < RO_002BE768)
                    near = 1;
            }
            if (near != 0)
                func_0017E0E0(pgoal);
        }
    }
}
