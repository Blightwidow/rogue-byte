#include "sly2.h"
struct LM;
typedef int QW __attribute__((mode(TI)));
extern "C" int B_003E12C8;
extern "C" LM g_2bbb60;
extern "C" float D_FLT_002C3690, D_FLT_002C3694, D_FLT_002C3698;
extern "C" float PowF_245b58(float, float);
extern "C" float GLimitLm__FP2LMf(LM *, float);
extern "C" int ConvertHsvToRgb__FP6VECTORT0(VECTOR *, VECTOR *);

void GreyColor_1ed2d8(VECTOR *prgb)
{
    float hsv[4];
    float weights[4] __attribute__((aligned(16)));
    if (B_003E12C8) {
        int bits;
        float *wp = weights;
        weights[0] = 0.3f;
        wp[1] = 0.6f;
        wp[2] = 0.1f;
        float h0 = D_FLT_002C3690;
        float h1 = D_FLT_002C3694;
        int fence;
        asm("lqc2 vf1, 0(%1)\n\tlqc2 vf2, %2" : "=r"(fence) : "r"(prgb), "m"(*(QW *)weights));
        asm("vmul.xyz vf1, vf1, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tqmfc2.ni %0, vf1" : "=r"(bits) : "r"(fence));
        float lum = *(float *)&bits;
        hsv[0] = h0;
        hsv[1] = h1;
        hsv[2] = GLimitLm__FP2LMf(&g_2bbb60, PowF_245b58(lum, D_FLT_002C3698));
        ConvertHsvToRgb__FP6VECTORT0((VECTOR *)hsv, prgb);
    }
}
