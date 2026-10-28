#include "sly2.h"
struct AVT { char pad[0x18]; short delta; short index; void (*fn)(void *, void *); };
struct ALLOC { AVT *vt; };
struct ENTRY { char pad[0xC]; ENTRY *next; };
struct HASHTABLE { int cBucket; ENTRY **pab; int c; ALLOC *palloc; };
static inline void Free(ALLOC *p, void *pv) { p->vt->fn((char *)p + p->vt->delta, pv); }

extern "C" void HashTable_Clear(HASHTABLE *pht)
{
    for (int ibucket = 0; ibucket < pht->cBucket; ibucket++) {
        ENTRY *pentry = pht->pab[ibucket];
        while (pentry != 0) {
            ENTRY *pentryNext = pentry->next;
            Free(pht->palloc, pentry);
            pentry = pentryNext;
        }
    }
    memset(pht->pab, 0, pht->cBucket << 2);
    pht->c = 0;
    Free(pht->palloc, pht->pab);
    pht->cBucket = 0;
    pht->pab = 0;
}
