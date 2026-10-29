#include "sly2.h"
struct SW;
struct LO { char pad0[0x18]; int oid; char pad1[0x16C - 0x1C]; int coid; int aoid[1]; };
extern "C" LO *PloFindSwObject_thunk(SW *, int, int, LO *);
extern "C" int CploFindSwObjectsByClass(SW *, int, int, LO *, int, LO **);
extern "C" LO *PloFindSpawn(SW *psw, int oidSpawn, int oidBasis)
{
    LO *aploSpawn[32];
    LO *ploBasis = 0;
    int found = 5;
    if (oidBasis != -1) {
        ploBasis = PloFindSwObject_thunk(psw, 5, oidBasis, 0);
        if (ploBasis)
            found = 1;
    }
    int cploSpawn = CploFindSwObjectsByClass(psw, found, 0x2A, ploBasis, 0x20, aploSpawn);
    found = 0;
    for (int iploSpawn = 0; iploSpawn < cploSpawn; iploSpawn++) {
        LO *ploSpawn = aploSpawn[iploSpawn];
        if (ploSpawn->oid == oidSpawn) {
            found = (int)ploSpawn;
            continue;
        }
        int coid = ploSpawn->coid;
        for (int ioid = 0; ioid < coid; ioid++) {
            if (*(unsigned long *)((char *)ploSpawn + 0x170 + ioid * 4) == oidSpawn) {
                found = (int)ploSpawn;
                break;
            }
        }
    }
    return (LO *)found;
}
