#include "sly2.h"
extern "C" void *__builtin_new(unsigned int);
extern char D_002DA9D0[];
struct Obj { int a; int b; int c; void *vtbl; };
void *func_00112F80()
{
    Obj *obj = (Obj *)__builtin_new(0x40);
    obj->vtbl = D_002DA9D0;
    obj->a = 0;
    obj->b = 0;
    return obj;
}
