#include "sly2.h"
struct ANIM { int kind; int pv; int pad0; int n; };
struct DIR { int a; int p0[11]; int b; int p1[11]; int c; int p2[11]; int d; };
struct STEPGUARD;
struct CRef;
extern "C" int GrfsgsFromRef(CRef *);
extern "C" ANIM *PguardanimEnsure(STEPGUARD *, int);
extern "C" DIR *func_0020CA00(int);
extern "C" void func_0020C7D8(DIR *);

void func_00207C48(STEPGUARD *guard, CRef *ref, int a, int b, int c, int d)
{
    ANIM *anim = PguardanimEnsure(guard, GrfsgsFromRef(ref));
    anim->kind = 3;
    DIR *dir = func_0020CA00(0xD0);
    anim->pv = (int)dir;
    func_0020C7D8(dir);
    ((DIR *)anim->pv)->a = a;
    ((DIR *)anim->pv)->b = b;
    ((DIR *)anim->pv)->c = c;
    ((DIR *)anim->pv)->d = d;
    anim->n = 8;
}
