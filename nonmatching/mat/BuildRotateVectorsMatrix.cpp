// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
// Draft: assembler wall (sqc2/qmfc2 in branch and jal delay slots plus ps2eeas hazard nops).
// Behaviour: builds the rotation taking vec1 onto vec2 (axis = normalised vec1 x vec2, or a perpendicular of vec1
// when they are parallel; cos = clamp(vec1.vec2 / (|vec1||vec2|), +-1), sin = sqrt(1 - cos^2)); identity when
// either vector is shorter than 0.0001. Returns pmat.
extern "C" QW GetPerpendicularVector(QW);
extern "C" void LoadRotateMatrixSinCos(MATRIX3 *, QW, QW, QW);
extern "C" float GLimitAbs__Fff(float, float);
static inline float Lane0(QW q)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); // lane x
    return f;
}
static inline QW Lane0Q(float f)
{
    QW q;
    asm("mfc1 %0, %1" : "=r"(q) : "f"(f)); // lane x
    return q;
}
static inline QW Length(QW vec)
{
    QW len;
    asm("qmtc2.ni %1, vf4\n\tvmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\t"
        "vmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tqmfc2.ni %0, vf2" : "=r"(len) : "r"(vec));
    return len;
}
static inline QW Cross(QW a, QW b)
{
    QW c;
    asm("qmtc2.ni %1, vf4\n\tqmtc2.ni %2, vf5\n\tvopmula.xyz ACC, vf4, vf5\n\tvopmsub.xyz vf3, vf5, vf4\n\tqmfc2.ni %0, vf3" : "=r"(c) : "r"(a), "r"(b));
    return c;
}
static inline QW Scale(QW vec, QW len)
{
    QW out;
    asm("qmtc2.ni %1, vf3\n\tqmtc2.ni %2, vf1\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf3, Q\n\tqmfc2.ni %0, vf3" : "=r"(out) : "r"(vec), "r"(len));
    return out;
}
static inline float Dot(QW a, QW b)
{
    QW d;
    asm("qmtc2.ni %1, vf4\n\tqmtc2.ni %2, vf5\n\tvmul.xyz vf1, vf4, vf5\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\t"
        "vmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r"(d) : "r"(a), "r"(b));
    return Lane0(d);
}
extern "C" MATRIX3 *BuildRotateVectorsMatrix(MATRIX3 *pmat, QW vec1, QW vec2)
{
    QW len1 = Length(vec1);
    QW len2 = Length(vec2);
    if (Lane0(len1) < 0.0001f || Lane0(len2) < 0.0001f) {
        memset(pmat, 0, sizeof(MATRIX3));
        pmat->mat[0][0] = 1.0f;
        pmat->mat[2][2] = 1.0f;
        pmat->mat[1][1] = 1.0f;
        return pmat;
    }
    QW axis = Cross(vec1, vec2);
    QW lenAxis = Length(axis);
    if (Lane0(lenAxis) > 1e-8f)
        axis = Scale(axis, lenAxis);
    else
        axis = GetPerpendicularVector(vec1);
    float gCos = GLimitAbs__Fff(Dot(vec1, vec2) / (Lane0(len1) * Lane0(len2)), 1.0f);
    float gSin = __builtin_sqrtf(1.0f - gCos * gCos);
    MATRIX3 mat;
    LoadRotateMatrixSinCos(&mat, Lane0Q(gSin), Lane0Q(gCos), axis);
    memcpy(pmat, &mat, sizeof(MATRIX3));
    return pmat;
}
