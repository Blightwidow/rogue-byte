struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002D9F70[];
Obj *func_00111518()
{
    Obj *object = (Obj *)__builtin_new(0x120);
    object->vtable = D_002D9F70;
    object->first = 0;
    object->second = 0;
    return object;
}
