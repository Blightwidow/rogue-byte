struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002DC890[];
Obj *func_00111400()
{
    Obj *object = (Obj *)__builtin_new(0xE0);
    object->vtable = D_002DC890;
    object->first = 0;
    object->second = 0;
    return object;
}
