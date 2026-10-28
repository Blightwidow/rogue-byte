struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002C94E0[];
Obj *func_001129E0()
{
    Obj *object = (Obj *)__builtin_new(0x60);
    object->vtable = D_002C94E0;
    object->first = 0;
    object->second = 0;
    return object;
}
