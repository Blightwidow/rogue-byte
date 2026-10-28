#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" int SetBlotLabelListFromRef(BASIC *, CRef *);

CRef *RefCallSetBlotLabelListFromRef(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { CRef arg; CRef ref; int aotyp[1]; } l;
    l.aotyp[0] = 0x8010;
    l.arg.tagk = -1;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 1, args, l.aotyp, &l.arg);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    SetBlotLabelListFromRef(object, &l.arg);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    CRef_Destruct(&l.arg);
    return result;
}
