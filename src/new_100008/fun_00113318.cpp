#include "sly2.h"
extern "C" void *__builtin_new(unsigned int);
extern char D_002CC4C0[];
struct Obj { int a; int b; int c; void *vtbl; };
void *func_00113318()
{
    Obj *obj = (Obj *)__builtin_new(0xE0);
    obj->vtbl = D_002CC4C0;
    obj->a = 0;
    obj->b = 0;
    return obj;
}
