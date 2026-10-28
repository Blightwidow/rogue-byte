#include "sly2.h"
extern "C" void *__builtin_new(unsigned int);
extern char D_002C94A0[];
struct Obj { int a; int b; int c; void *vtbl; };
void *func_00112FB8()
{
    Obj *obj = (Obj *)__builtin_new(0xB0);
    obj->vtbl = D_002C94A0;
    obj->a = 0;
    obj->b = 0;
    return obj;
}
