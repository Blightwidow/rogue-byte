#include "sly2.h"
struct SO { char pad[0x70]; int count; char *first; };
extern "C" {
int ClsgClipEdgeToBsp(char *first, char *end, QW from, QW to, int max, void *out);
int ClsgMergeAlsg(int count, void *a, int countNew, void *b, int max, void *dest, int flag);
}
extern "C" int FFindCmClearInterval(float duMin, int cpso, SO **apso, QW posFrom, QW posTo, float *puFrom, float *puTo)
{
    char lsg[0x1800];
    int clsg = 0;
    for (int ipso = 0; ipso < cpso; ipso++) {
        SO *pso = apso[ipso];
        char *first = pso->first;
        int clsgNew = ClsgClipEdgeToBsp(first, first + pso->count * 12, posFrom, posTo, 0x40 - clsg, lsg + clsg * 0x60);
        if (clsgNew)
            clsg = ClsgMergeAlsg(clsg, lsg, clsgNew, lsg + clsg * 0x60, 0x40, lsg, 0);
    }
    int ilsg = 0;
    for (;; ilsg++) {
        if (clsg < ilsg)
            return 0;
        float uFrom = ilsg > 0 ? *(float *)(lsg + (ilsg - 1) * 0x60 + 0x44) : 0.0f;
        float uTo = ilsg < clsg ? *(float *)(lsg + ilsg * 0x60 + 0x40) : 1.0f;
        if (duMin < uTo - uFrom) {
            if (puFrom)
                *puFrom = uFrom;
            if (puTo)
                *puTo = uTo;
            return 1;
        }
    }
}
