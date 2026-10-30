#include "sly2.h"
struct M4 { QW row[4]; };
struct M3 { QW row[3]; };
struct VUF { QW q; };
static inline VUF MakeVUF(int value) { VUF result; result.q = value; return result; }
struct EMITDV { float acc[3]; float pad0; QW axis; float swCurl; float damp; };
extern const M4 RO_002A2D30;
extern float g_2dded0[2];
extern "C" void LoadRotateMatrixRad(M3 *, QW, float);
extern "C" M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
extern "C" M4 __ml__FRC7MATRIX4G8VU_FLOAT(const M4 &, VUF);
extern "C" M4 *CalculateEmitdvMatrix(M4 *result, EMITDV *emitdv)
{
    M4 damp = RO_002A2D30;
    float swCurl = emitdv->swCurl;
    float damping = emitdv->damp;
    ((float *)&damp)[0] = damping;
    ((float *)&damp)[5] = damping;
    ((float *)&damp)[10] = damping;
    ((float *)&damp)[12] = emitdv->acc[0];
    ((float *)&damp)[13] = emitdv->acc[1];
    ((float *)&damp)[14] = emitdv->acc[2];
    M4 rotate = RO_002A2D30;
    if (swCurl != 0.0f) {
        M3 curl;
        LoadRotateMatrixRad(&curl, emitdv->axis, swCurl * g_2dded0[1]);
        rotate.row[0] = curl.row[0];
        rotate.row[1] = curl.row[1];
        rotate.row[2] = curl.row[2];
    }
    M4 scaled;
    scaled = __ml__FRC7MATRIX4G8VU_FLOAT(__ml__FRC7MATRIX4T0(rotate, damp), MakeVUF(*(unsigned char *)&g_2dded0[1]));
    for (int i = 0; i < 4; i++) {
        asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m" (result->row[i]) : "m" (rotate.row[i]), "m" (scaled.row[i]));
    }
    return result;
}
