struct SAVEPATH { int csym; short *asym; };
extern "C" {
int IdCurrentLevel(void);
int sprintf(char *, const char *, ...);
short SymidFindSymtab(void *, const char *);
void *func_002109B8(int);
SAVEPATH *PpathConcatStack(void *, SAVEPATH *);
extern char B_003E0EA8[];
extern const char RO_002A7768[];
extern const char RO_002A7788[];
}

static inline char *SymtabAddr() { char *p = B_003E0EA8; asm("" : "+r"(p)); return p + 8; }
SAVEPATH *PpathClueFlag(int idClue)
{
    int idLevel = IdCurrentLevel();
    if (idLevel == -1)
        return 0;
    SAVEPATH path;
    short asym[2];
    char buf[16];
    sprintf(buf, RO_002A7768, idClue);
    asym[0] = SymidFindSymtab(SymtabAddr(), RO_002A7788);
    asym[1] = idClue;
    path.csym = 2;
    path.asym = asym;
    return PpathConcatStack(func_002109B8(idLevel), &path);
}
