extern "C" void *RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(void *, int, void *, void *, void **);
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(void *pret, int carg, void *a2, void *a3, ...)
{
    void *apv[32];
    char *ap = (char *)__builtin_next_arg(a3) - 32;
    for (int i = 0; i < carg; i++) {
        ap += 8;
        apv[i] = *(void **)(ap - 8);
    }
    RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(pret, carg, a2, a3, apv);
    return pret;
}
