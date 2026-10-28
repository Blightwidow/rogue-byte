struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002CABD8[];
Obj *func_00111470()
{
    Obj *object = (Obj *)__builtin_new(0x100);
    object->vtable = D_002CABD8;
    object->first = 0;
    object->second = 0;
    return object;
}
