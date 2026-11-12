// SPDX-License-Identifier: GPL-3.0-or-later
#include "sw.h"
struct WIPEBLK {
    s32 wipes;
    s32 fHasTrans;
    LOADREQ trans;
    s32 pblot;
    s32 oidWipe;
};
extern "C" {
static inline int FEqualLevel(char *lhs, char *rhs) {
    if (lhs == rhs) return 1;
    if (rhs == 0) return 0;
    if (lhs == 0) return 0;
    return (*(u32 *)(rhs + 8) ^ *(u32 *)(rhs + 0x38)) == (*(u32 *)(lhs + 8) ^ *(u32 *)(lhs + 0x38));
}
LO *PloFindSwObject_thunk(void *, int, int, int);
void SetSwLoadRequest(void *, LOADREQ *);
void SetWipeWipes(WIPEBLK *, int);
extern SW B_003DD490;
extern char B_003E10D0[];
void ActivateWipe(WIPEBLK *wipe, LOADREQ *request, int oidWipe, int wipesNew) {
    switch (wipe->wipes) {
    case 2:
        SetWipeWipes(wipe, 0);
    case 0:
    default: {
        char *level = (char *)request + 4;
        int same = FEqualLevel(level, B_003E10D0);
        if (same)
            request->grf |= 2;
        else
            request->grf &= ~2;
        LO *found = PloFindSwObject_thunk(&B_003DD490, 0x405, oidWipe, 0);
        wipe->pblot = (s32)found;
        if (found == 0) {
            SetSwLoadRequest(&B_003DD490, request);
            return;
        }
        wipe->fHasTrans = 1;
        wipe->trans = *request;
        wipe->oidWipe = oidWipe;
        SetWipeWipes(wipe, wipesNew);
    }
    case 1:
    case 3:
        return;
    }
}
}
