struct ALLOCREQ { int size; int align; };
struct NODE { char pad[0x124]; int index; };
struct ITEM { char pad[0x124]; NODE *pnode; int flag; };
struct ADJ { int count; int *aitem; };
struct PZG { char pad[0x10]; int cnode; char pad2[8]; ADJ *aadj; int citem; ITEM **aitem; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
static inline void *PvAllocStackClear(ALLOCREQ *preq, int cb)
{
    preq->size = cb;
    preq->align = 0x10;
    return PvAllocStackClearImpl__Fi(preq);
}
static inline void *PvAllocSw(ALLOCREQ *preq, int cb)
{
    preq->align = 0x10;
    preq->size = cb;
    return PvAllocSwImpl__Fi(preq);
}
extern "C" void BuildPzgraphAdjacency(PZG *pzg)
{
    char frame[16];
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    int *acount = (int *)PvAllocStackClear(&req, pzg->cnode * 4);
    for (int i = 0; i < pzg->citem; i++) {
        ITEM *item = pzg->aitem[i];
        if (item->pnode != 0 && item->flag != 0)
            acount[item->pnode->index]++;
    }
    pzg->aadj = (ADJ *)PvAllocSw(&req, pzg->cnode * 8);
    for (int j = 0; j < pzg->cnode; j++) {
        ADJ *adj = &pzg->aadj[j];
        adj->count = 0;
        adj->aitem = (int *)PvAllocSw(&req, acount[j] * 4);
    }
    for (int k = 0; k < pzg->citem; k++) {
        ITEM *item = pzg->aitem[k];
        if (item->pnode != 0 && item->flag != 0) {
            ADJ *adj = &pzg->aadj[item->pnode->index];
            int n = adj->count;
            adj->aitem[n] = k;
            adj->count = n + 1;
        }
    }
    CStackFrame_Destructor(frame, 2);
}
