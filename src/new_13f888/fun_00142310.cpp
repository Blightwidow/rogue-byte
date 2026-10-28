#include "sly2.h"
struct Raw8 { char b[8]; };
struct Jt { char pad[0x11C4]; float a; float b; Raw8 raw; float c; float d; char pad2[4]; QW q; char pad3[0x1280-0x11F0]; QW r; };
void func_00142310(Jt *self, Raw8 *src, QW r, QW q, float a, float b, float c, float d)
{
    self->a = a;
    self->b = b;
    self->raw = *src;
    self->c = c;
    self->d = d;
    self->r = r;
    self->q = q;
}
