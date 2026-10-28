#include "sly2.h"
struct Murray { char pad[0x1AC0]; int field; };
struct Goal { char pad[0x10]; Murray *murray; };
void Goal_Deactivate(Goal *);
void SetMurrayState(Murray *, int);
void func_00146EE0(Goal *self)
{
    Goal_Deactivate(self);
    self->murray->field = 0;
    SetMurrayState(self->murray, 0);
}
