struct SM;
struct ALO;
struct Alo { char pad[0x2A0]; int refs[6]; };
extern "C" int func_001FD0C0(void *, int);
extern "C" SM *PloFindSwObject_thunk(void *, int, int, void *);
SM *PsmaFindSm__FP2SMP3ALO(SM *, ALO *);
extern "C" void PsmaApplySmInternal_thunk(SM *, ALO *, int, int, SM **);
extern "C" char B_003DD490;
extern "C" char B_003DD040;

void RetainAloSmKinds(Alo *alo, unsigned grf)
{
    int *refs = alo->refs;
    for (int kind = 0; kind < 6; kind++) {
        unsigned bit;
        if ((unsigned)kind >= 6u)
            bit = 0;
        else
            bit = 1u << kind;
        if ((grf & bit) == 0)
            continue;
        if (++refs[kind] >= 2)
            continue;
        int oid = func_001FD0C0(&B_003DD040, kind);
        SM *sm = PloFindSwObject_thunk(&B_003DD490, 4, oid, alo);
        if (sm == 0)
            continue;
        SM *sma = PsmaFindSm__FP2SMP3ALO(sm, (ALO *)alo);
        if (sma == 0)
            PsmaApplySmInternal_thunk(sm, (ALO *)alo, -1, 9, &sma);
    }
}
