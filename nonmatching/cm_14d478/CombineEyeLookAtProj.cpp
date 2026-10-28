#include "sly2.h"
struct M4 { QW row[4]; };
struct FM4 { float r[4][4]; };
extern "C" {
void InvertMatrix4Affine(M4 *, const M4 *);
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
}
extern "C" void CombineEyeLookAtProj(const FM4 *eye, const M4 *proj, M4 *out)
{
    FM4 basis;
    M4 inverse;
    memset(&basis, 0, sizeof(basis));
    basis.r[0][0] = 1.0f;
    basis.r[1][1] = 1.0f;
    basis.r[2][2] = 1.0f;
    basis.r[3][3] = 1.0f;
    for (int i = 0; i < 3; i++) {
        basis.r[0][i] = -eye->r[1][i];
        basis.r[1][i] = -eye->r[2][i];
        basis.r[2][i] = eye->r[0][i];
        basis.r[3][i] = eye->r[3][i];
    }
    InvertMatrix4Affine(&inverse, (const M4 *)&basis);
    M4 combined = __ml__FRC7MATRIX4T0(*proj, inverse);
    *out = combined;
}
