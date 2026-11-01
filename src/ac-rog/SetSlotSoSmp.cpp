#include "sly2.h"
struct V3SetSlot1B17B8 { float x, y, z; };
struct SmpSetSlot1B17B8 { char pad[0x210]; V3SetSlot1B17B8 v; float scale; };
extern V3SetSlot1B17B8 D_002C0248;
static inline float SqrtSetSlot1B17B8(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=f" (result) : "f" (value));
    return result;
}
extern "C" void SetSlotSoSmp(SmpSetSlot1B17B8 *smp, float scale)
{
    smp->v = D_002C0248;
    smp->v.x *= scale;
    smp->v.y *= scale;
    float root = SqrtSetSlot1B17B8(scale);
    smp->scale = scale;
    smp->v.z *= 1.0f / root;
}
