#include "sly2.h"
void *memset(void *, int, unsigned int);
void BuildSimpleProjectionMatrix(float xScale, float yScale, float xCenter, float yCenter, float nearClip, float farClip, MATRIX4 *matrix)
{
    float *out = (float *)matrix;
    memset(matrix, 0, 0x40);
    float depth = (nearClip + farClip) / (nearClip - farClip);
    out[11] = 1.0f;
    out[5] = yScale;
    out[8] = xCenter;
    out[0] = xScale;
    out[9] = yCenter;
    out[10] = depth;
    out[14] = nearClip * (1.0f - depth);
}
