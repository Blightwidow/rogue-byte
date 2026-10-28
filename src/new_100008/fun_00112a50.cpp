struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002DA840[];
Obj *func_00112A50()
{
    Obj *object = (Obj *)__builtin_new(0xD0);
    object->vtable = D_002DA840;
    object->first = 0;
    object->second = 0;
    return object;
}
