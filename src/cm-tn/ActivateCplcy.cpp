struct G { char pad0[0x24]; float f24; char pad1[0x24]; float f4C; };
extern "C" G B_002DDF40;
struct S { int v; float a; float b; };
extern "C" void ActivateCplcy(S *self, int value)
{
    self->v = value;
    self->b = B_002DDF40.f4C;
    self->a = B_002DDF40.f24;
}
