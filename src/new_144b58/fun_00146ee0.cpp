#include "sly2.h"
#include "murray.h"
#include "goal.h"
struct GOAL_146EE0 : GOAL { };
void Goal_Deactivate(GOAL_146EE0 *);
void SetMurrayState(MURRAY *, int);
void func_00146EE0(GOAL_146EE0 *self)
{
    Goal_Deactivate(self);
    ((MURRAY *)self->pstep)->field_0x1AC0 = 0;
    SetMurrayState(((MURRAY *)self->pstep), 0);
}
