struct CRef { int tagk; int n; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct SLOTHEAP;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(CPair **, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CRef_SetSymid(CRef *, unsigned);
void CRef_SetBasic(CRef *, void *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
extern "C" CPair **BuildScriptCall(CPair **ppairOut, void *pbasic, unsigned oid, CRef *prefArgs)
{
    CPair *handle;
    PairHandle_Init(&handle, PpairNew());
    bevy_splice_value_list_ref(&handle->ref, PpairNew());
    CPair *list = (CPair *)handle->ref.n;
    CRef_SetSymid(&list->ref, oid);
    CPair *created = PpairNew();
    PairHandle_Assign(&list->next, created);
    CPair *object = list->next;
    CRef_SetBasic(&object->ref, pbasic);
    if (prefArgs != 0 && prefArgs->tagk != 0)
        PairHandle_Assign(&object->next, (CPair *)prefArgs->n);
    PairHandle_Init(ppairOut, handle);
    CPair *ppair = handle;
    if (ppair != 0) {
        if (--ppair->cref == 0) {
            CPairPtr_Destructor(&ppair->next, 2);
            CRef_Destruct(&ppair->ref);
            UnlinkPairNode(ppair);
            FreeSlotheapPv(&B_004520A8, ppair);
        }
    }
    return ppairOut;
}
