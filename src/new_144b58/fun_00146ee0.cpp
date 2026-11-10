#include "sly2.h"
#include "murray.h"
struct Goal { char pad[0x10]; MURRAY *murray; };
void Goal_Deactivate(Goal *);
void SetMurrayState(MURRAY *, int);
void func_00146EE0(Goal *self)
{
    Goal_Deactivate(self);
    self->murray->field_0x1AC0 = 0;
    SetMurrayState(self->murray, 0);
}
