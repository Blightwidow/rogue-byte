// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct M3 { QW row[3]; };
struct VT { char pad[0xF0]; short delta; short index; void (*fn)(void *, M3 *); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(M3 *, QW);

void func_001A63B0(OBJ *pobj, QW vec)
{
    struct L { M3 copy; QW junk; M3 mat; } l;
    float k = 0.017453294f;
    float z = LaneZInGeneralRegister(vec) * k;
    float y = LaneX(RotateWords3(vec)) * k;
    float x = LaneX(vec) * k;
    QW low = InterleaveLowWords(y, x);
    QW euler = JoinLowDoublewords(z, low);
    l.junk = euler;
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.mat, euler);
    l.copy = l.mat;
    VT *vtable = pobj->vptr;
    vtable->fn((char *)pobj + vtable->delta, &l.copy);
}
