#include "sly2.h"
struct PLOVT { short delta; short index; void (*fn)(void *); };
struct PLO { char pad0[0x54]; int unk54; char pad58[8]; float unk60; float unk64; char pad68[4]; int unk6c; };
struct PLOV { char pad[0xC]; PLOVT *vt; };
struct LEVEL { char pad[0x3E60]; PLO *plo; };
extern "C" PLO *PloNew(int, int, int, int);

void func_0020E338(LEVEL *plevel)
{
    plevel->plo = PloNew(0x74, 0, -1, -1);
    plevel->plo->unk60 = 0.1f;
    plevel->plo->unk64 = 0.25f;
    plevel->plo->unk54 = 0x80200000;
    plevel->plo->unk6c = 1;
    PLOV *pplo = (PLOV *)plevel->plo;
    PLOVT *vt = pplo->vt;
    vt[9].fn((char *)pplo + vt[9].delta);
}
