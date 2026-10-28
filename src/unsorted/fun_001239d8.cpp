struct CRef { int tagk; int n; };
extern "C" CRef *func_001239D8(CRef *prefReturn, int carg, CRef *aref)
{
    int rem = aref[0].n % aref[1].n;
    prefReturn->tagk = 0x15;
    prefReturn->n = rem;
    return prefReturn;
}
