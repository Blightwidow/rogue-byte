struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002D97A8[];
Obj *func_00112858()
{
    Obj *object = (Obj *)__builtin_new(0x80);
    object->vtable = D_002D97A8;
    object->first = 0;
    object->second = 0;
    return object;
}
