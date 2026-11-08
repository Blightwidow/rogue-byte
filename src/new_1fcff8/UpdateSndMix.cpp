#include "sly2.h"
struct AMB { char pad0[0x50]; unsigned short grf; unsigned short cplay; };
struct SMP { float a, b, c; };
struct SNDMIX {
    char pad0[0x5C];
    int fForce;
    int fOff;
    int imix;
    char pad68[0x108 - 0x68];
    float aw[3];
    SMP asmp[3];
    char pad138[0x204 - 0x138];
    union {
        int camb;
        AMB *apamb[8];
    };
};
struct JT { char pad0[0x4C8]; int f4C8; char pad4CC[0x10C8 - 0x4CC]; int f10C8; char pad10CC[0x10EC - 0x10CC]; int jts; };
extern char B_003DD490[];
extern float g_2ddf10;
extern "C" {
JT *PpoSwFocus(char *);
int FIsBasicDerivedFrom(void *, int);
}
float GSmooth(float, float, float, SMP *, float *);
void SetAmbSlotVolume(AMB *, int, float);
static inline int FAmbActive(AMB *pamb)
{
    return pamb->cplay != 0 || (pamb->grf & 1) != 0;
}
// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float SqrtF(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=&f"(result) : "f" (value));
    return result;
}

void UpdateSndMix(SNDMIX *psm)
{
    psm->imix = 1;
    if (psm->fForce != 0) {
        psm->imix = 2;
    } else if (psm->fOff != 0) {
        psm->imix = 0;
    } else if (PpoSwFocus(B_003DD490) != 0 && FIsBasicDerivedFrom(PpoSwFocus(B_003DD490), 0x34) != 0) {
        JT *pjt = PpoSwFocus(B_003DD490);
        int jts = pjt->jts;
        if (jts == 3) {
            psm->imix = 0;
        } else if (jts == 4) {
            psm->imix = 2;
        } else if (pjt->f10C8 != -1) {
            psm->imix = 0;
        } else {
            int x = pjt->f4C8;
            if (x >= 0 && (x < 3 || x == 0xD))
                psm->imix = 0;
        }
    }
    AMB *pamb = psm->camb > 0 ? *(AMB **)((char *)psm + psm->camb * 4 + 0x204) : 0;
    if (pamb == 0 || FAmbActive(pamb)) {
        psm->aw[psm->imix] = 1.0f;
    } else {
        psm->aw[psm->imix] = GSmooth(psm->aw[psm->imix], 1.0f, g_2ddf10, &psm->asmp[psm->imix], 0);
    }
    float w2 = psm->aw[psm->imix] * psm->aw[psm->imix];
    float sum = 0.0f;
    for (int i = 0; i < 3; i++) {
        if (i != psm->imix)
            sum += psm->aw[i] * psm->aw[i];
    }
    if (sum < 0.0001f) {
        for (int i = 0; i < 3; i++)
            psm->aw[i] = i == psm->imix ? 1.0f : 0.0f;
    } else {
        float scale = SqrtF((1.0f - w2) / sum);
        for (int i = 0; i < 3; i++) {
            if (i != psm->imix)
                psm->aw[i] *= scale;
        }
    }
    if (pamb != 0) {
        SetAmbSlotVolume(pamb, 0, psm->aw[0]);
        SetAmbSlotVolume(pamb, 1, psm->aw[1]);
        SetAmbSlotVolume(pamb, 2, psm->aw[2]);
    }
}
