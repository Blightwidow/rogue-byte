#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct SUB { int a; int b; int c; void *vptr; };
struct GUARD { int f0; int f4; int f8; void *vptr; char pad0[0x70]; CRef ref; char pad1[0x174 - 0x90]; int f174; char pad2[0xDB0 - 0x178]; char jumper[0x70]; SUB sub; };
extern "C" char D_002D9978[], D_002CB1F0[], D_002DA568[], D_002DA9D0[];
extern "C" int __4CRef(CRef *);
extern "C" int InitJumper(void *);

extern "C" GUARD *ConstructGuard(GUARD *pguard)
{
    void *vptrSub = D_002CB1F0;
    pguard->f0 = 0;
    pguard->f4 = 0;
    pguard->vptr = D_002D9978;
    __4CRef(&pguard->ref);
    pguard->f174 = 0;
    pguard->vptr = D_002DA568;
    InitJumper(pguard->jumper);
    SUB *psub = &pguard->sub;
    psub->vptr = vptrSub;
    pguard->sub.a = 0;
    pguard->sub.b = 0;
    psub->vptr = D_002DA9D0;
    return pguard;
}
