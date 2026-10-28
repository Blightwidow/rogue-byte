#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct SAVEPATH { int csym; unsigned short *asymid; };
struct SAVEVARS { char pad[8]; char symtab[1]; };
extern SAVEVARS B_003E0EA8;
extern "C" {
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int SymidFindSymtab(void *, const char *);
int AtoiPchz(const char *);
void BuildSavePath(const char *first, char *args, SAVEPATH *path)
{
    char *saved = args;
    const char *name;
    path->csym = 0;
    path->asymid = 0;
    if (first != 0) {
        do {
            path->csym++;
            args += 8;
            name = *(const char **)(args - 8);
        } while (name != 0);
    }
    if (path->csym == 0)
        return;
    ALLOCREQ request;
    request.cb = path->csym << 1;
    request.cbAlign = 0x10;
    path->asymid = (unsigned short *)PvAllocStackImpl__Fi(&request);
    name = first;
    args = saved;
    int index = 0;
    if (name != 0) {
        do {
            int symid = SymidFindSymtab(B_003E0EA8.symtab, name);
            if (symid == -1)
                path->asymid[index] = AtoiPchz(name);
            else
                path->asymid[index] = symid;
            args += 8;
            name = *(const char **)(args - 8);
            index++;
        } while (name != 0);
    }
}
}
