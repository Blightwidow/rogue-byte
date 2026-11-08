#include "sly2.h"
struct V3SetSlot1B17B8 { float x, y, z; };
struct SmpSetSlot1B17B8 { char pad[0x210]; V3SetSlot1B17B8 v; float scale; };
extern V3SetSlot1B17B8 D_002C0248;
// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float SqrtSetSlot1B17B8(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=&f"(result) : "f" (value));
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
