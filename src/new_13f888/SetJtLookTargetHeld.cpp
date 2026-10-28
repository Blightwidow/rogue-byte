#include "sly2.h"
struct Jt { char pad[0x1100]; int held; };
void SetJtLookTarget();
void SetJtLookTargetHeld(Jt *self)
{
    SetJtLookTarget();
    self->held = 1;
}
