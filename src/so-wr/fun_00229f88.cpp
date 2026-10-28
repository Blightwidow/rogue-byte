struct LO { char pad[0x40]; unsigned grf; };
struct SO { char pad[0x16C]; LO *a; LO *b; LO *c; };
void PostSoLoad(SO *);
static inline void ClearGrf(LO *plo, unsigned mask)
{
    unsigned g = plo->grf;
    if (((g ^ 1) & 1) != 0)
        *(unsigned *)g &= ~mask;
    else
        plo->grf = g & ~mask;
}
void func_00229F88(SO *pso)
{
    PostSoLoad(pso);
    if (pso->a) ClearGrf(pso->a, 8);
    if (pso->b) ClearGrf(pso->b, 8);
    if (pso->c) ClearGrf(pso->c, 8);
}
