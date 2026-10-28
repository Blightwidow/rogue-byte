#include "sly2.h"
struct CRef { int a; int n; int c; int d; };
extern "C" {
CRef func_001D8A38(void *, const void *, int);
void CRef_Destruct(CRef *);
extern char RO_002A4DB0[];
extern unsigned B_003E1084;
void func_00143AF0(void *, int);
void GiveJtLoot(void *, int);
}
struct SVT { char pad[0x338]; short delta; short idx; void *(*fn)(void *); };
struct Jt { char pad[0xC]; SVT *vt; };
void func_00143BD8(Jt *jt)
{
    CRef ref = func_001D8A38(jt->vt->fn((char *)jt + jt->vt->delta), RO_002A4DB0, 0);
    int id = ref.n;
    CRef_Destruct(&ref);
    if (1u < (unsigned)(id + 1)) {
        if (B_003E1084 & 0x40)
            func_00143AF0(jt, id);
        else
            GiveJtLoot(jt, id);
    }
}
