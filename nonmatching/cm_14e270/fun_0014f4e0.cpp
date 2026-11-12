// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "ps2inline.h"
#include "sly2.h"
struct CM { char pad[0x60]; QW mat[4]; };
struct LOCALS { QW matNew[4]; QW vecEuler; MATRIX3 matRotate; };
extern "C" void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(MATRIX3 *pmatrix, QW vecEuler);
extern "C" void SetCmPosMat(CM *, QW *);
extern "C" void func_0014F4E0(CM *pcm, QW vecDegrees)
{
    LOCALS l;
    const float rDegToRad = 0.0174532942f;
    float zr = LaneZ(vecDegrees) * rDegToRad;
    float xr = LaneX(vecDegrees) * rDegToRad;
    float yr = LaneYInGeneralRegister(vecDegrees) * rDegToRad;
    l.matNew[3] = pcm->mat[3];
    l.matNew[2] = pcm->mat[2];
    l.matNew[1] = pcm->mat[1];
    l.matNew[0] = pcm->mat[0];
    QW low = InterleaveLowWords(yr, xr);
    l.vecEuler = JoinLowDoublewords(zr, low);
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.matRotate, l.vecEuler);
    l.matNew[0] = ((QW *)&l.matRotate)[0];
    l.matNew[1] = ((QW *)&l.matRotate)[1];
    l.matNew[2] = ((QW *)&l.matRotate)[2];
    ((float *)&l.matNew[2])[3] = 0.0f;
    ((float *)&l.matNew[1])[3] = 0.0f;
    ((float *)&l.matNew[0])[3] = 0.0f;
    SetCmPosMat(pcm, l.matNew);
}
