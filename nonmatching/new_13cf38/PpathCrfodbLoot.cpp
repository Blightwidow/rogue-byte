#include "sly2.h"
struct SymArgs { int tag; short *data; };
extern char B_003E0EA8[];
extern "C" int IdCurrentLevel(void);
extern "C" int SymidFindSymtab(void *, const char *);
extern "C" void *func_002109B8(int);
extern "C" int PpathConcatStack(void *, SymArgs *);
extern "C" void PpathCrfodbLoot(char *self)
{
    short values[3];
    SymArgs args;
    int id = 0;
    asm("" : "+r" (id));
    int level = IdCurrentLevel();
    if (~level) id = level;
    char *symtab = B_003E0EA8;
    asm("" : "+r" (symtab));
    values[0] = SymidFindSymtab(symtab, "booty");
    values[1] = SymidFindSymtab(symtab, "aoidAssembly");
    symtab += 8;
    values[2] = *(unsigned short *)(self + 0x180);
    int three = 3;
    args.tag = three;
    args.data = values;
    void *result = func_002109B8(id);
    PpathConcatStack(result, &args);
}
