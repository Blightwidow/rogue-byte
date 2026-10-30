#include "sly2.h"
struct Aim {
    unsigned char p0[0x10]; struct Aim *pparent; int unk14; int oid; char p1[0x7C - 0x1C]; int oidA; int oidB; int oidLabel;
    char p2[0x90 - 0x88]; QW vecRest; void *pxfA; void *pxfB; char p3[0xAC - 0xA8]; void *pguard; char animref[0x10]; void *pused;
};
extern "C" {
void PostLoLoad(Aim *);
int FIsBasicDerivedFrom(void *, int);
void BindAnimref(void *);
void *func_001F4C58(void *, int, int);
float *PeaFindAsegLabel(void *, int);
void PredictAsegEffect(void *, void *, void *, void *, float, float, void *, int);
}
void PostGuardAimLoad(Aim *paim)
{
    PostLoLoad(paim);
    void *pguard = paim->pparent;
    while (pguard != 0 && !FIsBasicDerivedFrom(pguard, 0x38))
        pguard = ((Aim *)pguard)->pparent;
    paim->pguard = pguard;
    char *panim;
    panim = paim->animref;
    BindAnimref(panim);
    if (paim->oid != 0x2CC)
        paim->pused = panim;
    if (paim->oidA != -1) {
        QW out[4];
        paim->pxfA = func_001F4C58(paim->pguard, paim->oidA, 6);
        paim->pxfB = func_001F4C58(paim->pguard, paim->oidB, 6);
        void * paseg;
        PredictAsegEffect(paseg, paim->pguard, paim->pxfB, *(void **)((char *)paim->pxfA + 0xA0), *PeaFindAsegLabel(paseg, paim->oidLabel), 1.0f, out, 0);
        paseg = *(void **)(panim + 4);
        paim->vecRest = out[3];
    }
}
