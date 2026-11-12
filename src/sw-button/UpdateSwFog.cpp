#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct LM { float gMin; float gMax; };
struct FOGSW {
    u8 unknown_0x0[0x3D5C];
    s32 frame;
    u8 unknown_0x3D60[0x3E10 - 0x3D60];
    VECTOR hsv;
    float scale;
    float unknown_0x3E24;
    struct { float x, y, z; } rgb;
    float alpha;
    s32 limited;
};
union VU_SCALE { QW q; VECTOR v; };
extern LM g_2bbb60;
extern "C" {
void ConvertHsvToRgb__FP6VECTORT0(VECTOR *, VECTOR *);
float GLimitLm__FP2LMf(LM *, float);
void GreyColor_1ed2d8(VECTOR *);
}
void UpdateSwFog(FOGSW *psw)
{
    VECTOR hsv;
    VECTOR rgb;
    VU_SCALE scale;
    hsv.x = psw->hsv.x;
    hsv.y = psw->hsv.y * 0.003921569f;
    hsv.z = psw->hsv.z * 0.003921569f;
    ConvertHsvToRgb__FP6VECTORT0(&hsv, &rgb);
    scale.q = VectorFromFloat(psw->scale * 0.003921569f);
    *(QW *)&rgb = VectorScaleX(*(QW *)&rgb, scale.q);
    GreyColor_1ed2d8(&rgb);
    psw->rgb = *(typeof(psw->rgb) *)&rgb;
    psw->alpha = psw->unknown_0x3E24 * 0.003921569f;
    if (psw->limited != 0)
        psw->alpha = GLimitLm__FP2LMf(&g_2bbb60, psw->alpha + 0.3f);
    psw->frame++;
}
