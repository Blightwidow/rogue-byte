struct Object;
struct Vtable { char pad[0x148]; short delta; short index; void (*function)(Object *, int); };
struct Object { char pad[0xC]; Vtable *vtable; };
void CloneLoVirtual(Object *self, int argument)
{
    Vtable *vtable = self->vtable;
    vtable->function((Object *)((char *)self + vtable->delta), argument);
}
