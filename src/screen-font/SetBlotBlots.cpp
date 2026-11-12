#include "sly2.h"
#include "sw.h"
struct CLOCKS { char pad[0x3C]; float dtScaled; };
struct BLOT {
    char pad0[0x58];
    int state;
    float dtState;
    int tagState;
    char pad1[0xC];
    int labelPlay0;
    int labelPlay1;
    int labelPlay2;
    char pad2[0x28];
    int cframe;
    char pad3[8];
    int fSlowsClock;
};
extern SW B_003DD490;
extern CLOCKS g_2dded0;
extern int g_2dd318;
extern int g_2be538;
extern "C" {
void SetClockRate(void *, int, float);
void PrepareBlotMovie(BLOT *);
void ReleaseBlotMovie(BLOT *);
void StopBlotLabel(BLOT *);
void PlayBlotLabel(BLOT *, int);
void SetBlotBlots(BLOT *pblot, int state)
{
    if (pblot->state == state)
        return;
    if (pblot->cframe >= 0x10) {
        if (pblot->state < 2 && state >= 2)
            B_003DD490.cblotActive++;
        else if (state < 2 && pblot->state >= 2)
            B_003DD490.cblotActive--;
    }
    if (pblot->fSlowsClock) {
        if (pblot->state < 2 && state >= 2) {
            if (++g_2dd318 == 1)
                SetClockRate(&g_2dded0, 7, 0.0f);
        } else if (state < 2 && pblot->state >= 2) {
            if (--g_2dd318 == 0)
                SetClockRate(&g_2dded0, 7, 1.0f);
        }
    }
    if (pblot->state == 0)
        PrepareBlotMovie(pblot);
    pblot->state = state;
    pblot->dtState = g_2dded0.dtScaled;
    pblot->tagState = g_2be538;
    switch (state) {
    case 0:
        ReleaseBlotMovie(pblot);
        break;
    case 1:
        StopBlotLabel(pblot);
        break;
    case 2:
        PlayBlotLabel(pblot, pblot->labelPlay0);
        break;
    case 3:
        PlayBlotLabel(pblot, pblot->labelPlay1);
        break;
    case 4:
        PlayBlotLabel(pblot, pblot->labelPlay2);
        break;
    }
}
}
