extern "C" void *PjsgeAllocJsg(void *, int, int);

struct JSGREC_1E15B0 { char pad[0x10]; int nAt10; int nAt14; };

extern "C" void func_001E15B0(void *pJsg, int nAt10, int nAt14)
{
    struct JSGREC_1E15B0 *pRec = (struct JSGREC_1E15B0 *)PjsgeAllocJsg(pJsg, 0x43, 0);
    pRec->nAt10 = nAt10;
    pRec->nAt14 = nAt14;
}
