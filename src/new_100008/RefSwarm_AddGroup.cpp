#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };

struct Raw16 { B8 x; B8 y; };
extern "C" void Swarm_AddGroup(BASIC *, int, int, int, float);
extern "C" const Raw16 RO_002A40B8;

CRef RefSwarm_AddGroup(BASIC *object, int count, CRef *args)
{
    Raw16 types;
    int a;
    int b;
    int c;
    float d;
    types = RO_002A40B8;
    RefSetArgsFromSplice(4, args, &types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    Swarm_AddGroup(object, a, b, c, d);
    return ref;
}
