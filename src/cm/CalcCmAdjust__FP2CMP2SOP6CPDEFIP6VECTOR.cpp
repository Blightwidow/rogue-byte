#include "sly2.h"
struct CPDEFI { char pad[0x30]; float radHome; float sAdjust; };
extern "C" VECTOR *SetVectorCylind__FP6VECTORfff(VECTOR *, float, float, float);
extern "C" VECTOR *CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(VECTOR *result, CPDEFI *cpdefi)
{
    return SetVectorCylind__FP6VECTORfff(result, cpdefi->radHome + 3.1415927f, cpdefi->sAdjust, 0.0f);
}
