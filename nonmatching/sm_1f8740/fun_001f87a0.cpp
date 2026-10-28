struct D { char pad[0xAC]; unsigned short v; };
struct A { char pad[0x24]; D *d; };
extern "C" float func_001F87A0(A *self)
{
    return (float)self->d->v * 0.001f;
}
