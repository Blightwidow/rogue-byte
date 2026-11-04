#include "sly2.h"
struct LO { char pad0[0x24]; LO *next; unsigned long flags; char pad1[0x34]; LO *child; };
int FIsBasicDerivedFrom(void *, int);
extern "C" void func_0013F990(LO *plo, int nLayer)
{
    unsigned long bits = (unsigned long)(nLayer & 0xf) << 0x30;
    plo->flags = (plo->flags & 0xfff0ffffffffffffUL) | bits;
    if (FIsBasicDerivedFrom(plo, 0x30)) {
        for (LO *ploChild = plo->child; ploChild != 0; ploChild = ploChild->next)
            func_0013F990(ploChild, nLayer);
    }
}
