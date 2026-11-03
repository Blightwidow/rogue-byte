// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct B8 { char b[8]; };
struct B12 { B8 xy; int z; };
struct LM;
extern "C" LM g_2bbb60;
struct SW {
    char p0[0x3D5C]; int count; char p1[0x3E10 - 0x3D60];
    float hue, sat, val, pad; float bright; float opac; B12 rgb; float opacOut; int biasFlag;
};
extern "C" {
void ConvertHsvToRgb__FP6VECTORT0(VECTOR *, VECTOR *);
void GreyColor_1ed2d8(VECTOR *);
float GLimitLm__FP2LMf(LM *, float);
}
/* a float broadcast into a VU0 register; retail keeps a stack copy it never reads */
static inline QW VuFloat(float f)
{
    QW q;
    asm("qmtc2.ni %1, %0" : "=j"(q) : "r"(f));
    VECTOR copy;
    *(QW *)&copy = q;
    return q;
}

void UpdateSwFog(SW *psw)
{
    VECTOR hsv;
    VECTOR rgb;
    float k = 0.003921569f;
    hsv.x = psw->hue;
    hsv.y = psw->sat * k;
    hsv.z = psw->val * k;
    VECTOR *prgb = &rgb;
    ConvertHsvToRgb__FP6VECTORT0(&hsv, prgb);
    QW color = *(QW *)&rgb;
    QW scale = VuFloat(psw->bright * k);
    QW scaled;
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(scaled) : "j"(color), "j"(scale));
    *(QW *)&rgb = scaled;
    GreyColor_1ed2d8(prgb);
    psw->rgb = *(B12 *)&rgb;
    float opac = psw->opac * k;
    psw->opacOut = opac;
    if (psw->biasFlag != 0)
        psw->opacOut = GLimitLm__FP2LMf(&g_2bbb60, opac + 0.3f);
    psw->count = psw->count + 1;
}
