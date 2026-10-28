#include "sly2.h"
struct ENT { unsigned nHash; const char *pchz; int symid; ENT *next; };
struct SYMTAB { ENT *bucket[53]; int cfree; ENT *ents; };
extern "C" unsigned NHashPchz(const char *);
void AddSymtabEntry(SYMTAB *t, const char *pchz, int symid)
{
    unsigned h = NHashPchz(pchz);
    ENT **b = &t->bucket[h % 53u];
    int c = t->cfree;
    t->cfree = c - 1;
    ENT *e = &t->ents[c - 1];
    e->pchz = pchz;
    e->symid = symid;
    e->nHash = h;
    e->next = *b;
    *b = e;
}
