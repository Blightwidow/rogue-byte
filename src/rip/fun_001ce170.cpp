#include "sly2.h"
struct Dest_1CE170 { QW a; QW b; QW c; float d; };
extern "C" {
void func_001F4BA8(void *);
extern int B_003E115C;
}
struct Obj_1CE170 { char pad0[0xEC]; Dest_1CE170 *dest; char pad1[0x170 - 0xF0]; QW q0; QW q1; QW q2; float f; };
extern "C" void func_001CE170(Obj_1CE170 *obj)
{
    obj->dest->a = obj->q0;
    obj->dest->b = obj->q1;
    obj->dest->c = obj->q2;
    obj->dest->d = obj->f;
    B_003E115C = 1;
    func_001F4BA8(obj);
}
