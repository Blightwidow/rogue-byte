struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002D7F40[];
Obj *func_00112890()
{
    Obj *object = (Obj *)__builtin_new(0xC0);
    object->vtable = D_002D7F40;
    object->first = 0;
    object->second = 0;
    return object;
}
