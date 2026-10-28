#include "sly2.h"
struct CRef { int tagk; int n; int c; int d; void operator=(const CRef &); };
extern char RO_002A79A0[], RO_002A79A8[], RO_002A79B8[];
extern "C" {
int sprintf(char *, const char *, ...);
void func_001D8A38(CRef *, const char *, ...);
void CRef_Destruct(CRef *);
}
int FGadgetAcquired(int gadget)
{
    if (gadget == -1)
        return 0;
    CRef ref;
    ref.tagk = -1;
    char idx[0x20];
    sprintf(idx, RO_002A79A0, gadget);
    CRef result;
    func_001D8A38(&result, RO_002A79A8, RO_002A79B8, idx, 0);
    ref = result;
    CRef_Destruct(&result);
    int on = ref.n;
    CRef_Destruct(&ref);
    return on;
}
