#include "sly2.h"
#include "vu0inline.h"
struct M3 { QW row[3]; };
struct EMITDV { float acc[3]; float pad0; QW axis; float swCurl; float damp; };
extern const MATRIX4 RO_002A2D30;
extern float g_2dded0[2];
extern "C" void LoadRotateMatrixRad(M3 *, QW, float);
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
extern "C" MATRIX4 __ml__FRC7MATRIX4G8VU_FLOAT(const MATRIX4 &, QW);
static inline QW MakeVUF(int value) { QW result; result = value; return result; }

extern "C" MATRIX4 *CalculateEmitdvMatrix(MATRIX4 *result, EMITDV *emitdv)
{
    MATRIX4 damp = RO_002A2D30;
    float swCurl = emitdv->swCurl;
    float damping = emitdv->damp;
    damp.mat[0][0] = damping;
    damp.mat[1][1] = damping;
    damp.mat[2][2] = damping;
    damp.mat[3][0] = emitdv->acc[0];
    damp.mat[3][1] = emitdv->acc[1];
    damp.mat[3][2] = emitdv->acc[2];
    MATRIX4 rotate = RO_002A2D30;
    if (swCurl != 0.0f) {
        M3 curl;
        LoadRotateMatrixRad(&curl, emitdv->axis, swCurl * g_2dded0[1]);
        rotate.row[0] = curl.row[0];
        rotate.row[1] = curl.row[1];
        rotate.row[2] = curl.row[2];
    }
    MATRIX4 scaled = __ml__FRC7MATRIX4G8VU_FLOAT(rotate * damp, MakeVUF(*(int *)&g_2dded0[1]));
    for (int i = 0; i < 4; i++) {
        result->row[i] = VectorAdd(rotate.row[i], scaled.row[i]);
    }
    return result;
}
