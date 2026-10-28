#include "sly2.h"
enum EYESS { EYESS_Open, EYESS_Closing, EYESS_Closed, EYESS_Opening };
struct EYES {
    char pad0[0x1C]; int cframe; char pad20[0x30]; float dtBlink; float dtOpenMin; float dtOpenMax; float pBlinkAgain;
    int oid; int eyess; float tEyess; float dtOpen; float sviframe; float gframe; float uClosed;
};
extern "C" float GRandInRange(float, float);
extern "C" float g_2dded0;
static inline float ToFloat(int value)
{
    float result;
    asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (result) : "r" (value));
    return result;
}

static inline float ToFloatAfter(int value, float before)
{
    float result;
    asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (result) : "r" (value), "f" (before));
    return result;
}

void SetEyesEyess(EYES *peyes, EYESS eyess)
{
    if (eyess == peyes->eyess)
        return;
    switch (eyess) {
    case EYESS_Open: {
        register int cframe asm("$3") = peyes->cframe;
        asm volatile("");
        float uClosed = peyes->uClosed;
        asm volatile("");
        float  twice;
        float last = ToFloatAfter(cframe - 1, twice);
        twice = ToFloat(cframe * 2);
        peyes->sviframe = twice * (1.0f - uClosed) / peyes->dtBlink;
        peyes->gframe = last * uClosed;
        float roll = GRandInRange(0.0f, 1.0f);
        if (!(roll >= peyes->pBlinkAgain))
            peyes->dtOpen = 0.0f;
        else
            peyes->dtOpen = GRandInRange(peyes->dtOpenMin, peyes->dtOpenMax);
        break;
    }
    case EYESS_Closing:
        break;
    case EYESS_Closed: {
        int  iframeLast;
        iframeLast = peyes->cframe - 1;
        if ((int)peyes->gframe != iframeLast)
            peyes->gframe = ToFloat(iframeLast);
        break;
    }
    }
    peyes->eyess = eyess;
    asm volatile("");
    peyes->tEyess = g_2dded0;
}
