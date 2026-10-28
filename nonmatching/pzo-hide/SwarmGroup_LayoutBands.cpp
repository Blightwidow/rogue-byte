#include "sly2.h"
struct B8 { char b[8]; };
struct RIDER { char pad[0x2C]; B8 band; B8 outer; char pad2[0x60 - 0x3C]; RIDER *pnext; };
struct GROUP { char pad[8]; int bandMax; int alive; RIDER *pfirst; char pad2[0x20 - 0x14]; float gap; int crv; };
extern "C" float SMaxCrv(int);
struct LAY { float bandMin, bandMax; char pad[8]; float outerMin, outerMax; };
extern "C" void SwarmGroup_LayoutBands(void *pswarm, GROUP *pgroup)
{
    float sCurve = SMaxCrv(pgroup->crv);
    int alive = pgroup->alive;
    float gap = pgroup->gap;
    int riders = pgroup->bandMax;
    if (alive <= riders) riders = alive;
    float gapMax = (sCurve * 0.5f) / (float)alive;
    gap = gapMax < gap ? gapMax : gap;
    float bandEnd = (((float)riders + (float)riders) - 1.0f) * gap;
    float perBand = (sCurve - ((float)alive + (float)alive) * gap) / (float)((alive - riders) + 1);
    float step = perBand + gap + gap;
    float shift = step * (float)(riders - 1);
    float bandMin = bandEnd - shift;
    float bandMax = (bandEnd + (float)riders * perBand) - shift;
    float outerMin = bandMin - (float)riders * gap;
    float outerMax = bandMax + (float)riders * gap;
    LAY lay;
    lay.bandMin = bandMin; lay.bandMax = bandMax; lay.outerMin = outerMin; lay.outerMax = outerMax;
    for (RIDER *prider = pgroup->pfirst; prider; prider = prider->pnext) {
        prider->band = *(B8 *)&lay.bandMin;
        prider->outer = *(B8 *)&lay.outerMin;
        lay.bandMin += step; lay.bandMax += step; lay.outerMin += step; lay.outerMax += step;
    }
}
