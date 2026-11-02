#include "sly2.h"
struct RIP; struct SO;
struct BUBLET { char pad0[0x20]; float f20; char pad24[0xA0 - 0x24]; QW vel; char padB0[0xC4 - 0xB0]; float fC4; };
extern "C" void InitRip__FP3RIPP6VECTORfP2SO(BUBLET *, QW *, float, SO *);
extern QW D_002C1F40;
extern "C" void InitBublet__FP6BUBLETP6VECTORfP2SO(BUBLET *pbublet, QW *ppos, float rScale, SO *pso)
{
    QW scaleVector;
    InitRip__FP3RIPP6VECTORfP2SO(pbublet, ppos, rScale, pso);
    pbublet->f20 = 0.33f;
    float scale = -0.2f;
    asm("lqc2 vf1, %0\n\tqmtc2.ni %1, vf2" : : "m" (D_002C1F40), "r" (scale));
    asm("vmulx.xyzw vf1, vf1, vf2x\n\tsqc2 vf1, %0" : "=m" (pbublet->vel));
    pbublet->fC4 = -8.0f;
    asm("sqc2 vf2, %0" : "=m" (scaleVector));
}
