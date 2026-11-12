#include "sly2.h"
#include "vu0inline.h"
#include "ps2inline.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
#include "goal.h"
struct CRVHOLDER { char pad_0[0xE8]; int mode; char pad_ec[0x8]; QW *points; };
struct CRVSTEP { char pad_0[0x294]; CRVHOLDER *pcrv; };
struct CTX { char pad_0[0x120]; int kind; };
struct GOAL_17E6B0 : GOAL {
    CTX *pctx;
    int index;
    int state;
    float tState;
    float tEnd;
};
extern "C" {
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
QW PosLoWorld(void *);
QW func_001C1EC0(void *, QW);
void MeasureCrv(void *);
void GoalFollowCrv_SetCrv(void *, void *, int);
void func_0017E628(void *);
}
extern float g_2dded0;
extern float g_2be7b0;
extern float g_2be7b4;
extern "C" void func_0017E6B0(GOAL_17E6B0 *pgoal, int newState)
{
    if (newState == pgoal->state)
        return;
    Goal_Pop(&((void *)pgoal->pgoalChild));
    pgoal->state = newState;
    pgoal->tState = *(float *)&g_2dded0;
    switch (newState) {
    case 0:
        switch (pgoal->pctx->kind) {
        case 0: {
            OBJ *pfollow = func_00205438(pgoal->pstep, 0xA7);
            CRVSTEP *pcrvstep = (CRVSTEP *)pgoal->pstep;
            CRVHOLDER *pcrv = pcrvstep->pcrv;
            QW pos = PosLoWorld(pcrvstep);
            QW goal = func_001C1EC0((char *)pgoal->pctx + (pgoal->index * 32 + 0x60), pos);
            float distance = LaneX(SqrtX(SquaredLengthXy(VectorSub(pos, goal))));
            float scaled = distance / g_2be7b0;
            float clamped = scaled < g_2be7b4 ? g_2be7b4 : scaled;
            pgoal->tEnd = g_2dded0 + clamped;
            pcrv->mode = 2;
            pcrv->points[0] = pos;
            pcrv->points[1] = goal;
            MeasureCrv(pcrv);
            *(int *)((char *)pfollow + 0x40) = 1;
            *(float *)((char *)pfollow + 0x64) = 10.0f;
            GoalFollowCrv_SetCrv(pfollow, pcrv, 0);
            VT *vtable = pfollow->vptr;
            vtable->fn((char *)pfollow + vtable->delta);
            break;
        }
        case 1:
            func_0017E628(pgoal);
            break;
        }
        break;
    case 1: {
        OBJ *pgoto = func_00205438(pgoal->pstep, 0xBF);
        char *psrc = (char *)((int)pgoal->pctx + pgoal->index * 32);
        VT *vtable = pgoto->vptr;
        *(QW *)((char *)pgoto + 0x30) = *(QW *)(psrc + 0x60);
        *(QW *)((char *)pgoto + 0x40) = *(QW *)(psrc + 0x70);
        vtable->fn((char *)pgoto + vtable->delta);
        break;
    }
    }
}
