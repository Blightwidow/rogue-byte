#include "sly2.h"
struct Obj { char pad[0x1C]; float radius; };
extern "C" int FInsideCmMrd(Obj *obj, QW vec, float scale, float *out)
{
    int chain;
    float lengthSq;
    asm("qmtc2.ni %1, vf3" : "=r" (chain) : "r" (vec));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (lengthSq) : "r" (chain));
    float radius = obj->radius;
    scale = scale * radius;
    float scaleSq = scale * scale;
    if (scaleSq < lengthSq)
        return 0;
    float k = 400.0f;
    asm volatile("nop");
    float diff = scale - radius * k;
    diff = diff * diff;
    if (diff < lengthSq)
        *out = (scaleSq - lengthSq) / (scaleSq - diff);
    else
        { float one = 1.0f; asm volatile("nop"); *out = one; }
    return 1;
}
