#include "sly2.h"
struct SO {
    char pad0[0x40]; unsigned grfTag;
    char pad1[0x104]; unsigned long flags;
};
extern "C" int FIsLoInWorld(SO *);
extern "C" void AddAloToRenderTree(SO *);
extern "C" void RemoveAloFromRenderTree(SO *);

static inline unsigned ReadGrf(SO *pso)
{
    register unsigned tag asm("$6") = pso->grfTag;
    unsigned grf = tag;
    if (((tag ^ 1) & 1) != 0)
        grf = *(unsigned *)tag;
    return grf;
}
static inline void SetGrf(SO *pso, unsigned tag, unsigned bits)
{
    unsigned p = tag;
    asm("" : "+r" (p));
    if (((p ^ 1) & 1) != 0)
        *(unsigned *)p |= bits;
    else
        pso->grfTag = tag | bits;
}
static inline void ClearGrf(SO *pso, unsigned tag, unsigned bits)
{
    unsigned t = tag;
    asm("" : "+r" (t));
    unsigned p = tag;
    if (((t ^ 1) & 1) != 0)
        *(unsigned *)p &= ~bits;
    else
        pso->grfTag = tag & ~bits;
}

void func_001F3B28(SO *pso, int fTracked)
{
    register unsigned tag asm("$6") = pso->grfTag;
    unsigned grf = ReadGrf(pso);
    if (fTracked != 0) {
        if ((grf & 8) == 0) {
            SetGrf(pso, tag, 8);
            if ((pso->flags & 0x800000000UL) != 0 && FIsLoInWorld(pso))
                AddAloToRenderTree(pso);
        }
    } else if ((grf & 8) != 0) {
        ClearGrf(pso, tag, 8);
        RemoveAloFromRenderTree(pso);
    }
}
