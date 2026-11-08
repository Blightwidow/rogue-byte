#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct SAVEPATH { int csym; unsigned short *asymid; };
extern "C" {
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int SymidFindSymtab(void *, const char *);
int AtoiPchz(const char *);
extern char B_003E0EA8[];
}

// The symbol table sits 8 bytes into the save data; the same accessor as in
// PpathVaultFlag and PpathClueFlag.
static inline void *SymtabOfSave(char *save) { return save + 8; }

// Retail walks a null-terminated list of names passed in 8-byte argument
// slots (variadic, so `args` steps by 8 and is reset from a saved copy for
// the second pass). Before the lookup loop retail keeps the full address of
// B_003E0EA8 in $s4 and adds 8 at each call: the address comes through the
// SymtabOfSave inline, not a folded `B_003E0EA8 + 8` constant (which leaves
// only %hi hoisted and %lo+8 in the loop).
extern "C" void BuildSavePath(const char *first, char *args, SAVEPATH *path)
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
            int symid = SymidFindSymtab(SymtabOfSave(B_003E0EA8), name);
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
