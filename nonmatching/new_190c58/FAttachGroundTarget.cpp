#include "sly2.h"
struct TARGET { void *plo; void *pmember; float dist; char pad[0x30 - 0xC]; };
struct SW { char pad[0x4678]; int ctarget; int pad2; TARGET atarget[1]; };
struct ATTACH { void *pjt; };
extern SW B_003DD490;
extern void *g_2e1e40;
extern float D_FLT_002BF660;
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void StartAttach(ATTACH *, int, void *, void *);
}
int FAttachGroundTarget(ATTACH *pattach)
{
    int itarget = 0;
    int ctarget = B_003DD490.ctarget;
    TARGET *pnext = B_003DD490.atarget;
    for (; itarget < ctarget; itarget++, pnext++) {
        TARGET *ptarget = pnext;
        if (D_FLT_002BF660 < ptarget->dist)
            break;
        void *plo = ptarget->plo;
        int kind;
        if (FIsBasicDerivedFrom(plo, 0x13) || FIsBasicDerivedFrom(plo, 0xB)) {
            kind = pattach->pjt == g_2e1e40 ? 6 : 5;
        } else if (FIsBasicDerivedFrom(plo, 0x1B)) {
            kind = 8;
        } else if (FIsBasicDerivedFrom(plo, 0xC) || FIsBasicDerivedFrom(plo, 0x22)) {
            kind = 0;
        } else if (FIsBasicDerivedFrom(plo, 0x26)) {
            kind = *(int *)((char *)ptarget->plo + 0x10C);
        } else if (FIsBasicDerivedFrom(plo, 0x23)) {
            kind = 7;
        } else {
            kind = -1;
        }
        if (kind != -1) {
            StartAttach(pattach, kind, plo, ptarget->pmember);
            return 1;
        }
    }
    return 0;
}
