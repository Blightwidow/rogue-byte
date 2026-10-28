struct CRef { int tagk; int n; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct SLOTHEAP;
struct SW;
struct CFrame { void *PrefFindBinding(unsigned, int); };
extern "C" {
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
extern SW B_003DD490;
extern int RO_0027A1D8[];
extern int RO_0027A10C[];
extern float g_2dded0;
void RefSetArgListFromPvs(CRef *, int, int *, void *);
CPair **BuildScriptCall(CPair **, void *, unsigned, CRef *);
void *AddSwTimedCall(float, SW *, void *, CPair *);
void EvalScriptCall(void *, CPair *, CFrame *, CRef *);
}
extern "C" void PostScriptMessage(CFrame **pobject, unsigned oid, long fQueue, int cArg, void *pvArgs, CRef *prefResult)
{
    CFrame *pframe = *pobject;
    if (pframe == 0)
        return;
    if (pframe->PrefFindBinding(oid, 1) == 0)
        return;
    CRef refArgs;
    RefSetArgListFromPvs(&refArgs, cArg, &RO_0027A10C[RO_0027A1D8[oid]], pvArgs);
    CPair *ppairCall;
    BuildScriptCall(&ppairCall, pobject, oid, &refArgs);
    if (fQueue != 0)
        AddSwTimedCall(g_2dded0, &B_003DD490, pobject, ppairCall);
    else
        EvalScriptCall(pobject, ppairCall, *pobject, prefResult);
    CPair *ppair = ppairCall;
    if (ppair != 0) {
        if (--ppair->cref == 0) {
            CPairPtr_Destructor(&ppair->next, 2);
            CRef_Destruct(&ppair->ref);
            UnlinkPairNode(ppair);
            FreeSlotheapPv(&B_004520A8, ppair);
        }
    }
    CRef_Destruct(&refArgs);
}
