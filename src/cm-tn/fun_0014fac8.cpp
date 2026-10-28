#include "sly2.h"
struct Guard { char pad[0x4A4]; int flag; };
void InitGuard(Guard *);
void func_0014FAC8(Guard *self)
{
    InitGuard(self);
    self->flag = 1;
}
