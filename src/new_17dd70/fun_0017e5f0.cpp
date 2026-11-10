#include "sly2.h"
extern "C" void func_001C1FA0(void *, int, float);
struct ENT { char b[32]; };
struct HDR { char h[0x60]; ENT e[1]; };
#include "goal.h"
struct GOAL_17E5F0 : GOAL {
    HDR *base;
    int index;
};
void func_0017E5F0(GOAL_17E5F0 *pgoal){ func_001C1FA0((char*)pgoal->base + 0x60 + (pgoal->index << 5), (int)pgoal->pstep, 25.0f); }
