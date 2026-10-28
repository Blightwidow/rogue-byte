struct VTable { char pad[0x1A0]; short delta; short index; void (*fn)(void *, int); };
struct Object { char pad[0xC]; VTable *vtable; };
extern "C" void ExplodeExplsExplso(Object *self, int arg)
{
    VTable *vtable = self->vtable;
    vtable->fn((char *)self + vtable->delta, arg);
}
