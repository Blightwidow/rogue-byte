#include "sly2.h"
struct ARENA { int a, b, c, d; };
struct STRENT { int sid; char *pch; };
struct STRTAB { int count; STRENT *entries; int size; int mem; };
struct SW { char pad[0x4640]; int flag; };
extern SW B_003DD490;
extern "C" int InitArena(ARENA *, int, int);
extern "C" char *PchzStringFromId(SW *, int);
extern "C" char *PchzAllocCopyImpl(ARENA *, char *, int);
extern "C" unsigned strlen(const char *);

void ResolveStringTable(STRTAB *table)
{
    if (B_003DD490.flag != 0) {
        ARENA arena;
        int index = 0;
        InitArena(&arena, table->size, table->mem);
        for (; index < table->count; index++) {
            STRENT *entry = &table->entries[index];
            entry->pch = PchzStringFromId(&B_003DD490, entry->sid);
            if (strlen(entry->pch) != 0)
                entry->pch = PchzAllocCopyImpl(&arena, entry->pch, 4);
            else
                entry->pch = 0;
        }
    }
}
