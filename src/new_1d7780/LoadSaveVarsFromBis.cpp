#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct SAVEVARS { int crec; void *arec; char symtab[1]; };
extern char g_2dd590[];
extern char B_003D4A60[];
extern "C" {
unsigned U16Read__18CBinaryInputStream(Bis *);
void InitSymtab(void *, int);
void func_00118380(Bis *, char **, char *, int);
void AddSymtabEntry(void *, char *, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void CBinaryInputStream_Read_thunk(Bis *, int, void *);
void ValidateSaveData(SAVEVARS *, char *);
}

void LoadSaveVarsFromBis(SAVEVARS *vars, Bis *bis)
{
    int count = U16Read__18CBinaryInputStream(bis);
    InitSymtab(vars->symtab, count);
    for (int index = 0; index < count; index++) {
        int symid = U16Read__18CBinaryInputStream(bis);
        char *name;
        func_00118380(bis, &name, g_2dd590, 0x2D);
        AddSymtabEntry(vars->symtab, name, symid);
    }
    int records = U16Read__18CBinaryInputStream(bis);
    vars->crec = records;
    ALLOCREQ req;
    req.cb = records * 10;
    req.cbAlign = 0x10;
    vars->arec = PvAllocSwImpl__Fi(&req);
    CBinaryInputStream_Read_thunk(bis, records * 10, vars->arec);
    ValidateSaveData(vars, B_003D4A60);
}
