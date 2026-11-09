struct CRef { int tagk; int pad[3]; };
struct JSG;
struct JSGE { char pad[0x10]; int coid; int aoid[4]; };
extern "C" void func_002013D8(CRef *, CRef *, int, int, unsigned *, int *);
extern "C" JSGE *PjsgeAllocJsg(JSG *, int, int);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void *CopyAb__FPvT0Ui(void *, void *, unsigned);
extern "C" void AddSeqRecordSync(JSG *pjsg, CRef *prefOids)
{
    int aoid[8];
    CRef refResult;
    unsigned coid;
    func_002013D8(&refResult, prefOids, 6, 8, &coid, aoid);
    JSGE *pjsge = PjsgeAllocJsg(pjsg, 3, 0);
    if (coid > 4)
        coid = 4;
    unsigned n = coid;
    pjsge->coid = n;
    CopyAb__FPvT0Ui(&pjsge->aoid[0], aoid, n << 2);
    CRef_Destruct(&refResult);
}
