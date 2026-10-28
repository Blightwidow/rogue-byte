// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct XF { char pad[0xC0]; QW vecGoal; QW vecVel; };
struct ACT { char pad[8]; XF *pxf; };
extern "C" void GetActPositionGoal__FP3ACTfP6VECTORT2(ACT *pact, QW *ppos, QW *pvel)
{
    if (ppos != 0) *ppos = pact->pxf->vecGoal;
    if (pvel != 0) *pvel = pact->pxf->vecVel;
}
