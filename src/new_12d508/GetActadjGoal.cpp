#include "sly2.h"
struct VT12D958 { char pad0[0x20]; short delta; short pad22; void (*fn)(void *); };
struct Child12D958 { char pad0[0x18]; VT12D958 *vt; };
struct Body12D958 { char pad0[0xC0]; QW a; char pad1[0xE0 - 0xD0]; QW b; };
struct Goal12D958 { char pad0[8]; Body12D958 *body; char pad1[0x1C - 0xC]; Child12D958 *child; QW delta; };
extern "C" void func_0012CF28(Goal12D958 *);

static inline QW Add(QW a, QW b)
{
    QW result;
    asm("vadd.xyzw %0, %1, %2" : "=j"(result) : "j"(a), "j"(b));
    return result;
}

extern "C" void GetActadjGoal(Goal12D958 *goal)
{
    Child12D958 *child = goal->child;
    if (child != 0) {
        child->vt->fn((char *)child + child->vt->delta);
        goal->body->a = Add(goal->body->a, goal->delta);
        goal->body->b = Add(goal->body->b, goal->delta);
    } else {
        func_0012CF28(goal);
    }
}
