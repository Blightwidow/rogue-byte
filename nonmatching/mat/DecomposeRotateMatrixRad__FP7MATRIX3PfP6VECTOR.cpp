#include "sly2.h"
static inline float SqrtHazard(float value)
{
    float result;
    asm("nop\n\tnop\n\tsqrt.s %0, %1" : "=&f" (result) : "f" (value));
    return result;
}
extern "C" {
float acosf(float);
float fabsf(float);
extern VECTOR g_2a2da0;
}
extern "C" void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(MATRIX3 *pmat, float *prad, VECTOR *pnormal)
{
    float *ag = &pmat->mat[0][0];
    float cosine = ((ag[0] + ag[5] + ag[10]) - 1.0f) * 0.5f;
    if (0.999999f < cosine) {
        *prad = 0.0f;
        *pnormal = g_2a2da0;
        return;
    }
    float *normal = &pnormal->x;
    float remaining = 1.0f;
    float denominator = remaining - cosine;
    for (int axis = 0; axis < 2; axis++) {
        float square = fabsf((ag[5 * axis] - cosine) / denominator);
        if (remaining < square)
            square = remaining;
        else if (square < 0.0f)
            square = 0.0f;
        normal[axis] = SqrtHazard(square);
        remaining -= square;
    }
    pnormal->z = SqrtHazard(remaining);
    if (cosine < -0.9999f) {
        *prad = 3.1415927f;
        float x = pnormal->x;
        float y = pnormal->y;
        float z = pnormal->z;
        if (y < x && z < x) {
            if (ag[1] < 0.0f)
                pnormal->y = -y;
            if (ag[2] < 0.0f)
                pnormal->z = -pnormal->z;
        } else if (x <= y && z < y) {
            if (ag[4] < 0.0f)
                pnormal->x = -x;
            if (ag[6] < 0.0f)
                pnormal->z = -pnormal->z;
        } else {
            if (ag[8] < 0.0f)
                pnormal->x = -x;
            if (ag[9] < 0.0f)
                pnormal->y = -pnormal->y;
        }
        return;
    }
    *prad = acosf(cosine);
    if (ag[4] > ag[1])
        pnormal->z = -pnormal->z;
    if (ag[8] < ag[2])
        pnormal->y = -pnormal->y;
    if (ag[9] > ag[6])
        pnormal->x = -pnormal->x;
}
