#include "sly2.h"
struct SMP;
struct JT {
    char pad0[0x2D]; unsigned char grfo;
    char pad1[0x80 - 0x2E]; char globset[0xAC];
    float uFade; char pad2[4]; void *prenderOptions;
    char pad3[0x4C8 - 0x138]; int kind;
    char pad4[0xF04 - 0x4CC]; int binoUse;
    char pad5[0xF20 - 0xF08]; int binoMode;
    char pad6[0x10D4 - 0xF24]; float uFadeA; float uFadeB;
    char pad7[0x19A0 - 0x10DC]; JT *ppartA; JT *ppartB;
};
extern "C" unsigned g_2ddf54;
extern "C" float g_2dded0[];
extern "C" const float D_FLT_002BD268;
extern "C" const float D_FLT_002BD26C;
extern "C" SMP D_002BD270;
extern "C" JT *g_2e1e40;
extern "C" void func_001F3C10(JT *);
extern "C" float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
extern "C" void RenderGlobset(void *, void *, void *, float, float);

extern "C" void RenderJt(JT *pjt)
{
    if ((pjt->grfo & g_2ddf54) == 0) return;
    func_001F3C10(pjt);
    if (pjt->binoUse == 1 && pjt->binoMode != 2) return;
    float uGoal;
    float uGoalOther;
    if (pjt->kind == 2) {
        uGoal = D_FLT_002BD268;
        uGoalOther = D_FLT_002BD26C;
    } else {
        asm(".set noat
	lui $at, 0x3F80
	mtc1 $at, %0
	nop
	.set at" : "=f"(uGoal));
        uGoalOther = uGoal;
    }
    pjt->uFadeA = GSmooth__FfffP3SMPPf(pjt->uFadeA, uGoal, g_2dded0[1], &D_002BD270, 0);
    pjt->uFadeB = GSmooth__FfffP3SMPPf(pjt->uFadeB, uGoalOther, g_2dded0[1], &D_002BD270, 0);
    if (pjt == g_2e1e40) {
        pjt->ppartA->uFade = pjt->uFadeA;
        pjt->ppartB->uFade = pjt->uFadeA;
    }
    float uFade = pjt->uFade;
    RenderGlobset(pjt->globset, 0, pjt->prenderOptions, uFade * pjt->uFadeA, uFade * pjt->uFadeB);
}
