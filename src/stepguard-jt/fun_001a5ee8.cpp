#include "sly2.h"
struct VT { char pad[0xA0]; short deltaApply; short indexApply; void (*fnApply)(void *, MATRIX4, int, float, float); };
struct VT2 { char pad[0xF8]; short delta; short index; MATRIX4 *(*fn)(void *); };
struct Lo { char pad[0xC]; VT *vt; };
struct Lo2 { char pad[0xC]; VT2 *vt; };
extern "C" void InvertMatrix4Affine(MATRIX4 *, MATRIX4 *);
extern "C" void __ml__FRC7MATRIX4T0(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);
extern "C" void func_001A5EE8(Lo *lo, MATRIX4 *world, float g0, float g1)
{
    MATRIX4 copy;
    MATRIX4 delta;
    MATRIX4 inverse;
    MATRIX4 *pdelta = &delta; MATRIX4 *pinverse = &inverse;
    VT2 *vtGet = ((Lo2 *)lo)->vt;
    MATRIX4 *current = vtGet->fn((char *)lo + vtGet->delta);
    InvertMatrix4Affine(pinverse, current);
    __ml__FRC7MATRIX4T0(pdelta, world, pinverse);
    copy = delta;
    VT *vt = lo->vt;
    vt->fnApply((char *)lo + vt->deltaApply, copy, 0, g0, g1);
}
