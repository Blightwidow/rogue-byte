#include "sly2.h"
struct Obj { char pad[0xC]; void *crv; float s; Obj *scale; };
extern "C" void GetPathPosFromS(void *, QW *, QW *, float);
extern "C" void func_0019EA00(Obj *obj, char *out)
{
    QW tangent, junk;
    int fence;
    GetPathPosFromS(obj->crv, 0, &tangent, obj->s);
    obj = obj->scale;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf1, vf1, vf2x" : "=r" (fence) : "r" (obj), "m" (tangent));
    *(int *)(out + 0x34) = 0;
    asm volatile("sqc2 vf1, %0" : "=m" (*(QW *)(out + 0x20)) : "r" (fence));
    asm volatile("sqc2 vf2, %0" : "=m" (junk) : "r" (fence));
}
