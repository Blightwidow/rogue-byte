#include "sly2.h"
struct BUBLET;
extern "C" {
void InitRip__FP3RIPP6VECTORfP2SO();
extern QW D_002C1F40;
void InitBublet__FP6BUBLETP6VECTORfP2SO(char *bublet)
{
    QW junk;
    InitRip__FP3RIPP6VECTORfP2SO();
    *(float *)(bublet + 0x20) = 0.33f;
    float scale = -0.2f;
    asm("lqc2 vf1, %0" : : "m"(D_002C1F40));
    asm("qmtc2.ni %0, vf2" : : "r"(scale));
    asm("vmulx.xyzw vf1, vf1, vf2x");
    asm("sqc2 vf1, %0" : "=m"(*(QW *)(bublet + 0xA0)));
    *(float *)(bublet + 0xC4) = -8.0f;
    asm("sqc2 vf2, %0" : "=m"(junk));
}
}
