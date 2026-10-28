#include "sly2.h"
struct SYMENTRY { int nHash; const char *pchz; int symid; SYMENTRY *next; };
struct SYMTAB { SYMENTRY *aentry[0x35]; };
extern "C" {
int NHashPchz(const char *);
int StricmpPchz(const char *, const char *);
}
extern "C" int SymidFindSymtab(SYMTAB *psymtab, const char *pchz)
{
    int nHash = NHashPchz(pchz);
    for (SYMENTRY *entry = psymtab->aentry[(unsigned)nHash % 0x35]; entry != 0; entry = entry->next) {
        if (entry->nHash == nHash && StricmpPchz(entry->pchz, pchz) == 0)
            return entry->symid;
    }
    return -1;
}
