struct ROOT { char pad[0x28]; unsigned long grfo; };
struct LO;
struct VT { char pad0[0x170]; short delta; short idx; void (*pfn)(LO *, int); };
struct LO { char pad0[0xC]; VT *pvt; LO *pparent; ROOT **proot; };
extern "C" char B_003DD490[];
extern "C" void ReinsertSwRoot(char *, ROOT **);
void SetLoGrfzon(LO *plo, int grf)
{
    ROOT **proot = plo->proot;
    if ((((*proot)->grfo >> 60) & 1) == 1)
        ReinsertSwRoot(B_003DD490, proot);
    plo->pvt->pfn((LO *)((char *)plo + plo->pvt->delta), grf);
    for (LO *p = plo->pparent; p != 0; p = p->pparent)
        ((unsigned char *)p)[0x2D] |= grf;
}
