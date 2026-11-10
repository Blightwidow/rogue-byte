#include "sly2.h"
#include "goal.h"
struct GOAL_155560 : GOAL {
    int state;
};
extern "C" void func_001EEF68(GOAL_155560 *);
extern "C" void AddGuardSgs(void *, int);
void func_00155560(GOAL_155560 *self)
{
    func_001EEF68(self);
    AddGuardSgs(((void *)self->pstep), 0x22);
    self->state = -1;
}
