struct Object;
struct Vtable { char pad[0x48]; short delta; short index; void (*function)(Object *); };
struct Object { char pad[0xC]; Vtable *vtable; };
void func_001A5D08(Object *self)
{
    Vtable *vtable = self->vtable;
    vtable->function((Object *)((char *)self + vtable->delta));
}
