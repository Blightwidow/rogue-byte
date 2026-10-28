#include "sly2.h"
struct B8 { char b[8]; };
struct LM;
extern "C" LM g_2bbb60;
struct SW {
    char p0[0x3D5C]; int count; char p1[0x3E10 - 0x3D60];
    float hue, sat, val, pad; float bright; float opac; B8 rgb; int rgbz; float opacOut; int biasFlag;
};
extern "C" {
void ConvertHsvToRgb__FP6VECTORT0(VECTOR *, VECTOR *);
void GreyColor_1ed2d8(VECTOR *);
float GLimitLm__FP2LMf(LM *, float);
}
void UpdateSwFog(SW *psw)
{
    VECTOR hsv;
    VECTOR rgb;
    VECTOR spill;
    float k = 0.003921569f;
    hsv.x = psw->hue;
    hsv.y = psw->sat * k;
    hsv.z = psw->val * k;
    VECTOR *prgb = &rgb;
    ConvertHsvToRgb__FP6VECTORT0(&hsv, prgb);
    float bright = psw->bright * k;
    asm("lqc2 vf1, %0" : : "m" (rgb));
    asm("qmtc2.ni %2, vf2\n\tvmulx.xyzw vf1, vf1, vf2x\n\tsqc2 vf2, %1\n\tsqc2 vf1, %0" : "=m" (rgb), "=m" (spill) : "r" (*(int *)&bright));
    GreyColor_1ed2d8(prgb);
    psw->rgbz = *(int *)&rgb.z;
    psw->rgb = *(B8 *)&rgb;
    float opac = psw->opac * k;
    psw->opacOut = opac;
    if (psw->biasFlag != 0)
        psw->opacOut = GLimitLm__FP2LMf(&g_2bbb60, opac + 0.3f);
    psw->count = psw->count + 1;
}
