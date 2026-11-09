#include "cref.h"
struct Raw8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef*, int, CRef*, const void*, ...);
extern "C" void CRef_Destruct(CRef*);
extern "C" void SetTag__4CRef4TAGK(CRef*, int);
extern "C" CRef *CRef_CopyConstruct(CRef*, CRef*);
extern "C" const Raw8 RO_002A3B98;
extern "C" void func_00170DA0(void*, int, int);
extern "C" CRef* F106538(CRef* result, void* self, int count, CRef* args)
{
    Raw8 types;
    CRef ref;
    int a;
    int b;
    types = RO_002A3B98;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, &types, &a, &b);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_00170DA0(self, a, b);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
