// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct VEC4 { float x, y, z, w; };
struct XF { char pad[0xC0]; QW vecGoal; };
struct ACT { char pad[8]; XF *pxf; };
extern "C" void func_0012DFE0(ACT *pact, QW *ppos, VEC4 *pvel)
{
    if (ppos != 0) *ppos = pact->pxf->vecGoal;
    if (pvel != 0) {
        pvel->z = 0.0f;
        pvel->y = 0.0f;
        pvel->x = 0.0f;
    }
}
