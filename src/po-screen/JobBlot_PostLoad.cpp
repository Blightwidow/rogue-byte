#include "sly2.h"
struct SW { char pad[0x4640]; int flag; };
extern SW B_003DD490;
struct BLOT;
struct JOBENT { int oid; void *plo; };
extern "C" void PostBlotLoad(BLOT *);
extern "C" void *PloFindSwObject_thunk(SW *, int, int, int);

struct BLOT {
    char pad0[0x110];
    int countB;
    JOBENT entriesB[1];
    char pad1[0x194 - 0x11C];
    int countA;
    JOBENT entriesA[1];
};

void JobBlot_PostLoad(BLOT *blot)
{
    int index = 0;
    PostBlotLoad(blot);
    for (; index < blot->countA; index++) {
        void *found = PloFindSwObject_thunk(&B_003DD490, 5, blot->entriesA[index].oid, 0);
        if (found)
            blot->entriesA[index].plo = found;
    }
    for (index = 0; index < blot->countB; index++) {
        void *found = PloFindSwObject_thunk(&B_003DD490, 5, blot->entriesB[index].oid, 0);
        if (found)
            blot->entriesB[index].plo = found;
    }
}
