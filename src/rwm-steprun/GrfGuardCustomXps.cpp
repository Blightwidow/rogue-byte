#include "sly2.h"
struct VT { char pad[0x60]; short delta; short index; int (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct GUARD { char pad0[0x2C0]; unsigned long grfsgs; char pad1[0xFD0 - 0x2C8]; OBJ *pobj; };
extern "C" unsigned long GrfsgsFromSgs(int);
extern "C" int func_002040F8(GUARD *);

int GrfGuardCustomXps(GUARD *pguard)
{
    if (pguard->grfsgs & GrfsgsFromSgs(0x14))
        return 1;
    unsigned long mask = GrfsgsFromSgs(0x12) | GrfsgsFromSgs(0x13) | GrfsgsFromSgs(0x16);
    if (pguard->grfsgs & mask)
        return 0;
    OBJ *pobj = pguard->pobj;
    if (pobj != 0)
        return pobj->vptr->fn((char *)pobj + pobj->vptr->delta);
    return func_002040F8(pguard);
}
