#include "sly2.h"
struct SO;
extern "C" {
int ClsgClipEdgeToObject(SO *, QW, QW, int, void *);
int ClsgMergeAlsg(int count, void *a, int countNew, void *b, int max, void *dest, int flag);
int ClsgClipEdgeToObjects(QW pos0, QW pos1, int cgeom, SO **apgeom, int clsgMax, char *alsg)
{
    int clsg = 0;
    for (int igeom = 0; igeom < cgeom; igeom++) {
        char *alsgNew = alsg + clsg * 0x60;
        int clsgNew = ClsgClipEdgeToObject(apgeom[igeom], pos0, pos1, clsgMax - clsg, alsgNew);
        if (clsgNew)
            clsg = ClsgMergeAlsg(clsg, alsg, clsgNew, alsgNew, clsgMax, alsg, 0);
    }
    return clsg;
}
}
