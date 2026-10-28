// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct VEC4 { float x, y, z, w; };
struct LOOKAT { char pad[0x20]; QW posTarget; };
extern "C" void func_0012D0D8(LOOKAT *plookat, QW *ppos, VEC4 *pv)
{
    if (ppos != 0) *ppos = plookat->posTarget;
    if (pv != 0) {
        pv->z = 0.0f;
        pv->y = 0.0f;
        pv->x = 0.0f;
    }
}
