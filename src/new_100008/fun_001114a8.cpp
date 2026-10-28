struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002CA9F0[];
Obj *func_001114A8()
{
    Obj *object = (Obj *)__builtin_new(0x140);
    object->vtable = D_002CA9F0;
    object->first = 0;
    object->second = 0;
    return object;
}
