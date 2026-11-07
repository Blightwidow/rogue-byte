struct SAVEPATH { int csym; short *asym; };
extern "C" {
int IdCurrentLevel(void);
short SymidFindSymtab(void *, const char *);
void *func_002109B8(int);
SAVEPATH *PpathConcatStack(void *, SAVEPATH *);
extern char B_003E0EA8[];
extern const char RO_002A7790[];
}
static inline void *SymtabOfSave(char *save) { return save + 8; }

SAVEPATH *PpathVaultFlag()
{
    int idLevel = IdCurrentLevel();
    if (idLevel == -1)
        return 0;
    SAVEPATH path;
    short asym[2];
    asym[0] = SymidFindSymtab(SymtabOfSave(B_003E0EA8), RO_002A7790);
    path.csym = 1;
    path.asym = asym;
    return PpathConcatStack(func_002109B8(idLevel), &path);
}
