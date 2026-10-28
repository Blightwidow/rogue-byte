struct CRef { int tagk; int pad[3]; CRef &operator=(const CRef &); };
extern "C" void func_002013D8(CRef *, CRef *, int, int, int *, int *);
extern "C" CRef *CRef_Destruct(CRef *);

void SetGuardRefLists(char *guard, CRef *candidates, CRef *blockers)
{
    CRef holder;
    CRef result;
    holder.tagk = -1;
    func_002013D8(&result, candidates, 0x2002, 4, (int *)(guard + 0xF94), (int *)(guard + 0xF98));
    holder = result;
    CRef_Destruct(&result);
    func_002013D8(&result, blockers, 0x2002, 4, (int *)(guard + 0xFA8), (int *)(guard + 0xFAC));
    holder = result;
    CRef_Destruct(&result);
    CRef_Destruct(&holder);
}
