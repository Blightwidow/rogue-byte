#include "sly2.h"
struct SAVEDATA { char b[0x5408]; };
struct REC { short symid; short pad; unsigned short ib; char pad2[4]; };
struct SAVEVARS { int crec; REC *arec; char symtab[1]; };
extern SAVEDATA B_003D4A60;
extern "C" const char RO_STR_002A78F8[];
extern "C" int SymidFindSymtab(void *, const char *);
void SnapshotSaveData(SAVEVARS *vars, SAVEDATA *data)
{
    *data = B_003D4A60;
    const char *name = RO_STR_002A78F8;
    void *symtab = vars->symtab;
    int symid = SymidFindSymtab(symtab, name);
    if (symid == -1)
        return;
    for (int index = 0; index < vars->crec; index++) {
        REC *record = (REC *)((char *)vars->arec + index * 10);
        if (record->symid == symid)
            ((char *)data)[record->ib] = 1;
    }
}
