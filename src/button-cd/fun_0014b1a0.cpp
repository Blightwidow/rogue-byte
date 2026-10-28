#include "sly2.h"
struct Guard { char pad[0x4A4]; int flag; };
extern Guard *B_002DD648;
void InitGuard(Guard *);
void func_0014B1A0(Guard *self)
{
    InitGuard(self);
    B_002DD648 = self;
    self->flag = 1;
}
