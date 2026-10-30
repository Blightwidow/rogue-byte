#include "sly2.h"
struct FGFN;
struct CM;
extern "C" {
float tanf(float);
float sqrtf(float);
}
void BuildSimpleProjectionMatrix(float, float, float, float, float, float, MATRIX4 *);
void BuildCmFgfn(CM *, float, FGFN *);
void UpdateCmMat4(CM *);
#define F(off) (*(float *)((char *)pcm + (off)))
void RecalcCmFrustrum(CM *pcm)
{
    float yScreenRange = tanf(F(0x20) * 0.5f);
    F(0x44) = yScreenRange;
    float xScreenRange = yScreenRange * F(0x3C);
    F(0x40) = xScreenRange;
    float  rMrd;
    F(0x1C) = rMrd < 1.0f ? 1.0f : rMrd;
    rMrd = F(0x18) * (1.0f / F(0x20));
    F(0x48) = yScreenRange * sqrtf(F(0x3C) * F(0x3C) + 1.0f) * F(0x4C) + 1.0f;
    BuildSimpleProjectionMatrix(512.0f / (xScreenRange * 4096.0f), 224.0f / (yScreenRange * 4096.0f), 0.0f, 0.0f,
        F(0x4C), F(0x50), (MATRIX4 *)((char *)pcm + 0x100));
    BuildCmFgfn(pcm, 1.0f, (FGFN *)((char *)pcm + 0x250));
    UpdateCmMat4(pcm);
}
