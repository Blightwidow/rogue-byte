#include "sly2.h"
struct Goal { char pad[0x10]; void *guard; char pad2[0x30 - 0x14]; int state; };
extern "C" void func_001EEF68(Goal *);
extern "C" void AddGuardSgs(void *, int);
void func_00155560(Goal *self)
{
    func_001EEF68(self);
    AddGuardSgs(self->guard, 0x22);
    self->state = -1;
}
