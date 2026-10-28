struct B { char pad[0xDC]; struct C *c; };
struct C { int unk0; float value; };
struct A { char pad[0xE8]; B *b; };
extern "C" float func_001F84A0(A *self)
{
    C *c = 0;
    if (self->b) c = self->b->c;
    if (c) return c->value;
    return 0.0f;
}
