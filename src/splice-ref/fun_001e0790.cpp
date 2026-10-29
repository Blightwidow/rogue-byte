extern "C" void *PjsgeAllocJsg(void *, int, int);

struct JSGREC_1E0790 { char pad[0x10]; int nAt10; int nAt14; };

extern "C" void func_001E0790(void *pJsg, int nAt10, int nAt14)
{
    struct JSGREC_1E0790 *pRec = (struct JSGREC_1E0790 *)PjsgeAllocJsg(pJsg, 0x15, 1);
    pRec->nAt10 = nAt10;
    pRec->nAt14 = nAt14;
}
