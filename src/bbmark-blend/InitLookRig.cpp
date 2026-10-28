#include "sly2.h"
struct LOOKRIG { void *pjt; int state; char pad0[0x18]; QW vecLook; float zStart; char pad1[4]; char recs[6 * 0x1C]; };
void EnsureAsegBlendDynamic(void *, int, int, void *, int, int *, int *, void *);
void InitLookRig(float gUnused, float zStart, LOOKRIG *plookrig, void *pjt, QW vecLook)
{
    plookrig->pjt = pjt;
    plookrig->vecLook = vecLook;
    plookrig->zStart = zStart;
    plookrig->state = -1;
    for (unsigned irec = 0; irec < 6; irec++) {
        char *prec = plookrig->recs + irec * 0x1C;
        EnsureAsegBlendDynamic(plookrig->pjt, 0xC, 2, prec, 0, 0, 0, prec + 0x18);
    }
}
