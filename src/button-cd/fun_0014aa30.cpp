// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LM { float gMin; float gMax; };
struct CM;
struct CRV_14AA30 { char pad[0xF0]; float *ag; QW *apos; };
struct ENTRY_14AA30 { int n0; int n4; int fActive; };
struct PATH_14AA30 { char pad[0x50]; int n50; int c; ENTRY_14AA30 *a; CRV_14AA30 *pcrv; };
struct OBJ_14AA30 { char pad[0x38]; PATH_14AA30 *ppath; };
extern "C" {
void *PpoSwFocusBase(void *);
QW PosLoWorld(void *);
void FindCrvClosestPointAll(void *, QW, void *, QW *, void *, void *, float *);
QW ConvertCmWorldToScreen(CM *, QW);
}
int FCheckLm(LM *, float);
extern "C" char B_003DD490[];
extern "C" CM B_002DDF40;
extern "C" LM D_002BD480;
extern "C" LM D_002BD488;
extern "C" LM D_002BD490;
extern "C" LM D_002BD498;
extern "C" LM D_002BD4A0;
// sqrt.s as the game's math header writes it (asm volatile, precedent SetSlotSoSmp / 220D40)
static inline float SqrtfAsm(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=f" (result) : "f" (value));
    return result;
}
static inline float GFracLm(LM *plm, float g)
{
    if (plm->gMin == plm->gMax)
        return 0.0f;
    return (g - plm->gMin) / (plm->gMax - plm->gMin);
}
extern "C" int func_0014AA30(OBJ_14AA30 *pobj)
{
    VECTOR posScreen;
    float s;
    int iBest = -1;
    float gBest = -1.0f;
    void *ppo = PpoSwFocusBase(B_003DD490);
    PATH_14AA30 *ppath = pobj->ppath;
    FindCrvClosestPointAll(ppath->pcrv, PosLoWorld(ppo), 0, 0, 0, 0, &s);
    for (int i = 0; i < pobj->ppath->c; i++) {
        ENTRY_14AA30 *pentry = &pobj->ppath->a[i];
        if (pentry->fActive == 0)
            continue;
        float ds = s - pobj->ppath->pcrv->ag[i];
        if (pobj->ppath->n50 == 1)
            ds = -ds;
        float gDist;
        if (FCheckLm(&D_002BD480, ds))
            gDist = GFracLm(&D_002BD480, ds);
        else if (FCheckLm(&D_002BD488, ds))
            gDist = 1.0f - GFracLm(&D_002BD488, ds);
        else
            gDist = 0.0f;
        *(QW *)&posScreen = ConvertCmWorldToScreen(&B_002DDF40, pobj->ppath->pcrv->apos[i]);
        float gDepth;
        if (FCheckLm(&D_002BD490, posScreen.z))
            gDepth = GFracLm(&D_002BD490, posScreen.z);
        else if (FCheckLm(&D_002BD498, posScreen.z))
            gDepth = 1.0f - GFracLm(&D_002BD498, posScreen.z);
        else
            gDepth = 0.0f;
        float gCenter;
        ds = SqrtfAsm(posScreen.x * posScreen.x + posScreen.y * posScreen.y);
        if (FCheckLm(&D_002BD4A0, ds))
            gCenter = 1.0f - GFracLm(&D_002BD4A0, ds);
        else
            gCenter = 0.0f;
        float g = gDist * 0.5f + gDepth * 0.15f + gCenter * 0.35f;
        if (gBest < g) {
            gBest = g;
            iBest = i;
        }
    }
    return iBest;
}
