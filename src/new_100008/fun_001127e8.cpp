struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002CAD78[];
Obj *func_001127E8()
{
    Obj *object = (Obj *)__builtin_new(0xC0);
    object->vtable = D_002CAD78;
    object->first = 0;
    object->second = 0;
    return object;
}
