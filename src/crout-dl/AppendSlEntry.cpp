struct SL { void *pvFirst; void *pvLast; int ibSle; };
extern "C" void AppendSlEntry(SL *psl, void *pv)
{
    if (psl->pvLast == 0) {
        psl->pvLast = pv;
        psl->pvFirst = pv;
        return;
    }
    *(void **)((char *)psl->pvLast + psl->ibSle) = pv;
    psl->pvLast = pv;
}
