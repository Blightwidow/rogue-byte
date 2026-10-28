struct SL { void *pvFirst; void *pvLast; int ibSle; };
extern "C" void PrependSlEntry(SL *psl, void *pv)
{
    void **slot = (void **)((char *)pv + psl->ibSle);
    if (psl->pvFirst == 0) {
        psl->pvLast = pv;
        psl->pvFirst = pv;
        return;
    }
    *slot = psl->pvFirst;
    psl->pvFirst = pv;
}
