struct LO { char pad[0x10]; LO *parent; char pad2[0xEC-0x14]; void *pox; };
extern "C" {
extern char B_003DD490[];
LO *func_001A5BF0(LO *);
void UpdateSwPox(void *, void *, void *, int);
void func_001F4BF8(void *);
}
void func_00204F78(LO *pso, LO *plo, int fAdd)
{
    LO *anc = func_001A5BF0(plo);
    while (anc && !anc->pox)
        anc = anc->parent;
    void *pox = pso->pox;
    if (pox != 0 && anc != 0 && anc->pox != 0)
        UpdateSwPox(B_003DD490, pox, anc->pox, fAdd ? 1 : 2);
    func_001F4BF8(pso);
}
