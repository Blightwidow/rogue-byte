struct Obj { int first; int second; int pad0x8; void *vtable; };
extern "C" void *__builtin_new(unsigned int);
extern char D_002CE118[];
Obj *func_00111550()
{
    Obj *object = (Obj *)__builtin_new(0x110);
    object->vtable = D_002CE118;
    object->first = 0;
    object->second = 0;
    return object;
}
