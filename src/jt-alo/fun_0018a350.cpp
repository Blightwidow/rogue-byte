#include "sly2.h"
struct Obj { char pad[0x18C4]; void *target; int mode; };
extern "C" QW PosLoWorld(void *);
extern "C" void func_00141588(Obj *, QW *);

static inline float ZOf(QW q) { float t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (t)); return f; }

extern "C" void func_0018A350(Obj *obj, QW *out)
{
    switch (obj->mode) {
    case 3:
        func_00141588(obj, out);
        ((float *)out)[2] = ZOf(PosLoWorld(obj->target)) + -175.0f;
        break;
    case 22:
        func_00141588(obj, out);
        ((float *)out)[2] = ZOf(PosLoWorld(obj->target)) + -100.0f;
        break;
    case 21:
        *out = PosLoWorld(obj);
        break;
    default:
        func_00141588(obj, out);
        break;
    }
}
