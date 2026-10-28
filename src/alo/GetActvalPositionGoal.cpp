#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct XF { char pad0[0x30]; QW v30; char pad40[0x68]; float tEnd; char padAC[4]; QW vB0; };
struct ACT { char pad[0x8]; XF *pxf; char pad2[0x14]; QW pos; QW vel; };
extern float g_2dded0;
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);

void GetActvalPositionGoal(ACT *pact, float dt, QW *pvecPos, QW *pvecVel)
{
    XF *pxf = pact->pxf;
    float tEnd = pxf->tEnd;
    if (tEnd <= g_2dded0 + dt) {
        if (pvecPos != 0)
            *pvecPos = pact->pos;
        if (pvecVel != 0)
            *pvecVel = pact->vel;
    } else {
        EvaluateBezierPos__FfffP6VECTORN63(tEnd - g_2dded0, dt, 1.0f, pxf->v30, pxf->vB0, pact->pos, pact->vel, pvecPos, pvecVel, 0);
    }
}
