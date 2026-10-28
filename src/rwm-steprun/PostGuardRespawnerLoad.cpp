struct ALLOCREQ { int cb; int cbAlign; };
struct PLO { char pad[0x50]; int count; void *array; };
extern "C" { extern char B_003DD490[]; void PostLoLoad(void *);
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
void *PvAllocSwImpl__Fi(void *); }
void PostGuardRespawnerLoad(PLO *plo)
{
    PostLoLoad(plo);
    int count = CploFindSwObjectsByClass(B_003DD490, 0x605, 0x38, 0, 0, 0);
    ALLOCREQ req;
    req.cb = count << 2;
    req.cbAlign = 0x10;
    plo->count = count;
    void *array = PvAllocSwImpl__Fi(&req);
    plo->array = array;
    CploFindSwObjectsByClass(B_003DD490, 0x405, 0x38, 0, plo->count, array);
}
