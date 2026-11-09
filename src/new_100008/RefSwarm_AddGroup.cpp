#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);

struct Raw16 { B8 x; B8 y; };
extern "C" void Swarm_AddGroup(BASIC *, int, int, int, float);
extern "C" const Raw16 RO_002A40B8;

CRef *RefSwarm_AddGroup(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw16 types;
    CRef ref;
    int a;
    int b;
    int c;
    float d;
    types = RO_002A40B8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, &types, &a, &b, &c, &d);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    Swarm_AddGroup(object, a, b, c, d);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
