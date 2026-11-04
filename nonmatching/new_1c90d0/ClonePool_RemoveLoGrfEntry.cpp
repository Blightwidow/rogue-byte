struct VT { char pad[0xB0]; short delta; short idx; void (*fn)(void *); };
struct LO { char pad[0xC]; VT *vt; };
struct ROOT { LO *plo; };
struct POOL { char pad[0x14]; ROOT *proot; char pad2[0xE8 - 0x18]; void *please; };
extern "C" {
void ReleaseLease(POOL *, void *);
int FFindDlEntry(void *, void *);
void RemoveDlEntry(void *, void *);
extern char B_003DD4BC[];
}

void ClonePool_RemoveLoGrfEntry(POOL *ppool)
{
    while (ppool->please != 0)
        ReleaseLease(ppool, ppool->please);
    if (FFindDlEntry(B_003DD4BC, ppool->proot) != 0) {
        LO *plo = ppool->proot->plo;
        plo->vt->fn((char *)plo + plo->vt->delta);
        RemoveDlEntry(B_003DD4BC, ppool->proot);
    }
}
