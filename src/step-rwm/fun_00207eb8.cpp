struct ANIMREF { int a; int oid; int c; int n; };
extern "C" void ResetAnimref(void *, void *);
void func_00207EB8(void *pguard, unsigned grf, int oid, int n, ANIMREF *aanimref)
{
    unsigned mask = 1;
    int i = 0x19;
    do {
        unsigned bit = grf & mask;
        i--;
        mask <<= 1;
        if (bit != 0) {
            ResetAnimref(aanimref, pguard);
            aanimref->oid = oid;
            aanimref->n = n;
        }
        aanimref++;
    } while (i >= 0);
}
