#include "sly2.h"
struct Goal { char pad[0x30]; int state; };
void func_001EEF68(Goal *);
void func_001461C8(Goal *self)
{
    func_001EEF68(self);
    self->state = -1;
}
