#include "sly2.h"

struct SmoothParam { float a; float b; float c; };
struct RenderObject {
    char pad0[0x2D]; unsigned char grfo;
    char pad1[0x80 - 0x2E]; char globset[0xAC];
    float uFade; char pad2[4]; void *prenderOptions;
    char pad3[0x4C8 - 0x138]; int kind;
    char pad4[0xF04 - 0x4CC]; int binoUse;
    char pad5[0xF20 - 0xF08]; int binoMode;
    char pad6[0x10D4 - 0xF24]; float uFadeA; float uFadeB;
    char pad7[0x19A0 - 0x10DC]; RenderObject *ppartA; RenderObject *ppartB;
};

extern "C" {
extern unsigned int g_2ddf54;
extern float g_2dded0[];
extern const float D_FLT_002BD268;
extern const float D_FLT_002BD26C;
extern SmoothParam D_002BD270;
extern RenderObject *g_2e1e40;
void func_001F3C10(RenderObject *);
float GSmooth__FfffP3SMPPf(float, float, float, SmoothParam *, float *);
void RenderGlobset(void *, void *, void *, float, float);
}

extern "C" void RenderJt(RenderObject *pjt)
{
    if ((pjt->grfo & g_2ddf54) == 0) return;
    func_001F3C10(pjt);
    if (pjt->binoUse == 1 && pjt->binoMode != 2) return;
    float goalA;
    float goalB;
    if (pjt->kind == 2) {
        goalA = D_FLT_002BD268;
        goalB = D_FLT_002BD26C;
    } else {
        goalB = 1.0f;
        goalA = goalB;
    }
    pjt->uFadeA = GSmooth__FfffP3SMPPf(pjt->uFadeA, goalA, g_2dded0[1], &D_002BD270, 0);
    pjt->uFadeB = GSmooth__FfffP3SMPPf(pjt->uFadeB, goalB, g_2dded0[1], &D_002BD270, 0);
    if (pjt == g_2e1e40) {
        pjt->ppartA->uFade = pjt->uFadeA;
        pjt->ppartB->uFade = pjt->uFadeA;
    }
    float uFade = pjt->uFade;
    RenderGlobset(pjt->globset, 0, pjt->prenderOptions, uFade * pjt->uFadeA, uFade * pjt->uFadeB);
}
