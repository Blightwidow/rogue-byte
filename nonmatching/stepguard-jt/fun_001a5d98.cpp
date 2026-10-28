struct LO;
struct DCB { void (*pfn)(LO *, void *); void *pv; DCB *pdcbNext; };
struct LO { char pad[0x34]; DCB *pdcb; };
void func_001A5D98(LO *plo)
{
    DCB *apdcb[32];
    int i = 0;
    DCB *pdcb = plo->pdcb;
    if (pdcb) {
        do {
            apdcb[i++] = pdcb;
            pdcb = pdcb->pdcbNext;
        } while (pdcb);
        for (i--; i >= 0; i--)
            apdcb[i]->pfn(plo, apdcb[i]->pv);
    }
}
