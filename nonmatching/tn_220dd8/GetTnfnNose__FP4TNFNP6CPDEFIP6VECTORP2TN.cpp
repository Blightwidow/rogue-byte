#include "sly2.h"
struct TNFN { char pad0[0x40]; char almCam[0x20]; float f60; char pad64[0xC]; float f70; float f74; float f78; };
struct CPDEFI { char pad[0x10]; QW base; char pad20[0x20]; QW focus; };
struct TN { char pad[0x120]; int fCyl; char pad124[0x1C]; float sClosest; };
struct CLQ { float g0, g1, g2, g3; };
struct LM { float a, b; };
enum FTND { FTND_X, FTND_FORWARD };
extern "C" void CalculateTnCrv(TN *, QW, void *, void *);
void CalculateTnPos(TN *, VECTOR *, float, float, CLQ *, LM *, FTND, VECTOR *);

void GetTnfnNose(TNFN *tnfn, CPDEFI *cp, VECTOR *nose, TN *tn)
{
    struct Frame { QW dpos; CLQ clq[3]; QW closest; } frame;
    float u = tnfn->f60;
    float inv = 1.0f - u;
    asm("lqc2 vf3, %0" : : "m" (cp->focus), "f" (u));
    asm("lqc2 vf1, %0" : : "m" (cp->base), "f" (inv));
    asm("qmtc2.ni %0, vf4" : : "r" (u));
    asm("qmtc2.ni %0, vf2" : : "r" (inv));
    asm volatile("sqc2 vf2, %0" : "=m" (frame.dpos));
    asm volatile("vmulax.xyzw ACC, vf1, vf2x\n\tvmaddx.xyzw vf1, vf3, vf4x\n\tsqc2 vf1, %0" : "=m" (*nose));
    asm volatile("sqc2 vf4, %0" : "=m" (frame.dpos));
    if (tn) {
        memset(frame.clq, 0, 0x30);
        frame.clq[0].g1 = tnfn->f70;
        frame.clq[1].g1 = tnfn->f74;
        frame.clq[2].g1 = tnfn->f78;
        int fCyl = tn->fCyl;
        tn->fCyl = 0;
        CalculateTnCrv(tn, *(QW *)nose, &frame.dpos, &frame.closest);
        CalculateTnPos(tn, (VECTOR *)&frame.dpos, tn->sClosest, 0.0f, frame.clq, (LM *)tnfn->almCam, FTND_FORWARD, nose);
        tn->fCyl = fCyl;
    }
}
