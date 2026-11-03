struct ALLOCREQ { int size; int align; };
struct NODE { char pad[0x124]; int index; };
struct ITEM { char pad[0x124]; NODE *pnode; int flag; };
struct ADJ { int count; int *aitem; };
struct PZG { char pad[0x10]; int cnode; char pad2[8]; ADJ *aadj; int citem; ITEM **aitem; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" void BuildPzgraphAdjacency(PZG *pzg)
{
    char frame[16];
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    preq->size = pzg->cnode * 4;
    preq->align = 0x10;
    int *acount = (int *)PvAllocStackClearImpl__Fi(preq);
    for (int i = 0; i < pzg->citem; i++) {
        ITEM *item = pzg->aitem[i];
        if (item->pnode != 0 && item->flag != 0)
            acount[item->pnode->index]++;
    }
    preq->align = 0x10;
    preq->size = pzg->cnode * 8;
    pzg->aadj = (ADJ *)PvAllocSwImpl__Fi(preq);
    int *pcount = acount;
    for (int j = 0; j < pzg->cnode; j++) {
        ADJ *adj = &pzg->aadj[j];
        adj->count = 0;
        preq->align = 0x10;
        preq->size = *pcount++ * 4;
        adj->aitem = (int *)PvAllocSwImpl__Fi(preq);
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
