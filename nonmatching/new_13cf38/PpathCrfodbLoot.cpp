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
    int id = IdCurrentLevel();
    if (id == -1) id = 0;
    char *symtab = B_003E0EA8;
    symtab += 8;
    values[0] = SymidFindSymtab(symtab, "booty");
    values[1] = SymidFindSymtab(symtab, "aoidAssembly");
    int level = *(unsigned short *)(self + 0x180);
    values[2] = level;
    args.tag = 3;
    args.data = values;
    void *result = func_002109B8(id);
    PpathConcatStack(result, &args);
}
