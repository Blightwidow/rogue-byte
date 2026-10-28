struct Vtable { char pad[0x58]; short delta; short index; void (*fn)(void *); };
struct Object { char pad[0xC]; Vtable *vptr; };
void func_002097E0(Object **slot)
{
    Object *object = *slot;
    if (object != 0) {
        Vtable *vtable = object->vptr;
        vtable->fn((char *)object + vtable->delta);
    }
}
