struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002D8C48[];
Obj *func_00112900()
{
    Obj *object = (Obj *)__builtin_new(0xB0);
    object->vtable = D_002D8C48;
    object->first = 0;
    object->second = 0;
    return object;
}
