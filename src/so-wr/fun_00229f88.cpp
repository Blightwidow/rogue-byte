#include "so.h"

struct SOWATCH : SO {
    /* 0x150 */ u8 unknown_0x150[0x1C];
    /* 0x16C */ LO *a;
    /* 0x170 */ LO *b;
    /* 0x174 */ LO *c;
};

void PostSoLoad(SOWATCH *);
static inline void ClearGrf(LO *plo, unsigned mask)
{
    unsigned g = plo->grfSw;
    if (((g ^ 1) & 1) != 0)
        *(unsigned *)g &= ~mask;
    else
        plo->grfSw = g & ~mask;
}
void func_00229F88(SOWATCH *pso)
{
    PostSoLoad(pso);
    if (pso->a) ClearGrf(pso->a, 8);
    if (pso->b) ClearGrf(pso->b, 8);
    if (pso->c) ClearGrf(pso->c, 8);
}
