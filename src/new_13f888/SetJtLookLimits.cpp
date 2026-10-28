#include "sly2.h"
struct Raw8 { char b[8]; };
struct Jt { char pad[0x1120]; Raw8 a; Raw8 b; Raw8 c; };
void SetJtLookLimits(Jt *self, Raw8 *a, Raw8 *b, Raw8 *c)
{
    self->a = *a;
    self->b = *b;
    self->c = *c;
}
