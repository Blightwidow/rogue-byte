#include "sly2.h"
struct RECON { char pad[0x30]; int count; int targets[16]; char pad2[0xA4 - 0x74]; void *a4; void *a8; void *ac; void *b0; };
struct HOLD { void *p; };
extern "C" char B_003DD490[];
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" int CploFindSwObjectsByClass(void *, int, int, void *, int, int *);
extern "C" void HideReconLinks(RECON *);
void func_00201DC8(RECON *r)
{
    if (FIsBasicDerivedFrom(((HOLD *)r->a8)->p, 0x35)) {
        r->ac = PloFindSwObject_thunk(B_003DD490, 0x405, 0x362, 0);
        r->b0 = PloFindSwObject_thunk(B_003DD490, 0x405, 0x365, 0);
    }
    r->a4 = PloFindSwObject_thunk(B_003DD490, 0x405, 0x602, 0);
    r->count = CploFindSwObjectsByClass(B_003DD490, 0x405, 0x2E, 0, 0x10, r->targets);
    HideReconLinks(r);
}
