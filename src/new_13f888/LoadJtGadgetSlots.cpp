#include "jt.h"
struct CRef { int tagk; int n; int p2; int p3; };
extern "C" const char RO_002A4D50[];
extern "C" const char RO_002A4D58[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" void func_001D8A38(CRef *, const char *, const char *, const char *, int);
extern "C" void CRef_Destruct(CRef *);

void LoadJtGadgetSlots(JT *jt)
{
    GADGETSLOT *aslot = jt->aslot;
    for (int index = 0; index < 3; index++) {
        char name[16];
        sprintf(name, RO_002A4D50, index);
        CRef ref;
        func_001D8A38(&ref, jt->Slot103(), RO_002A4D58, name, 0);
        aslot[index].gadget = ref.n;
        CRef_Destruct(&ref);
    }
    jt->Slot105();
}
