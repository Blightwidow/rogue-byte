#include "sly2.h"
struct SLOTHEAP;
struct CRef { int tagk; void *pv; };
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);
extern "C" SLOTHEAP B_00452188, B_004521A0, B_004521B8, B_004521D0, B_004521E8;
struct RC { int a[32]; };

extern "C" void SetTag__4CRef4TAGK(CRef *pref, int tagk)
{
    pref->tagk = tagk;
    switch (tagk) {
    case 26: {
        int *block = (int *)PvAllocSlotheapImpl(&B_00452188);
        block[4] = 0;
        pref->pv = block;
        block[4] = block[4] + 1;
        break;
    }
    case 27: {
        int *block = (int *)PvAllocSlotheapImpl(&B_004521A0);
        block[16] = 0;
        pref->pv = block;
        block[16] = block[16] + 1;
        break;
    }
    case 28: {
        int *block = (int *)PvAllocSlotheapImpl(&B_004521B8);
        block[4] = 0;
        pref->pv = block;
        block[4] = block[4] + 1;
        break;
    }
    case 29: {
        int *block = (int *)PvAllocSlotheapImpl(&B_004521D0);
        block[2] = 0;
        pref->pv = block;
        block[2] = block[2] + 1;
        break;
    }
    case 30: {
        int *block = (int *)PvAllocSlotheapImpl(&B_004521E8);
        block[3] = 0;
        pref->pv = block;
        block[3] = block[3] + 1;
        break;
    }
    case 31: case 32: case 33: case 34: case 35:
    default:
        pref->pv = 0;
        break;
    }
}
