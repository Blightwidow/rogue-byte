#include "sly2.h"
struct VT12D958 { char pad0[0x20]; short delta; short pad22; void (*fn)(void *); };
struct Child12D958 { char pad0[0x18]; VT12D958 *vt; };
struct Body12D958 { char pad0[0xC0]; QW a; char pad1[0xE0 - 0xD0]; QW b; };
struct Goal12D958 { char pad0[8]; Body12D958 *body; char pad1[0x1C - 0xC]; Child12D958 *child; char pad2[0x20 - 0x20]; };
struct GoalQ12D958 { char pad0[0x20]; QW delta; };
extern "C" void func_0012CF28(Goal12D958 *);
extern "C" void GetActadjGoal(Goal12D958 *goal)
{
    Child12D958 *child = goal->child;
    if (child != 0) {
        child->vt->fn((char *)child + child->vt->delta);
        Body12D958 *body = goal->body;
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(body->a) : "m"(((GoalQ12D958 *)goal)->delta), "m"(body->a));
        Body12D958 *body2 = goal->body;
        int fence;
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyzw vf1, vf1, vf2" : "=r"(fence) : "m"(((GoalQ12D958 *)goal)->delta), "m"(body2->b));
        asm("sqc2 vf1, %0" : "=m"(body2->b) : "r"(fence));
    } else {
        func_0012CF28(goal);
    }
}
