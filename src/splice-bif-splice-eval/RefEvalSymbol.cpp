extern "C" void FFindBinding__6CFrameUiiP4CRef(char *, unsigned int, int, char *);
extern "C" void CRef_CopyConstruct(char *, char *);
extern "C" void CRef_Destruct(char *);

char *RefEvalSymbol(char *arg0, char *arg1, char *arg2) {
    char sp[0x10];

    *(int *)sp = -1;
    FFindBinding__6CFrameUiiP4CRef(arg2, *(unsigned int *)(arg1 + 0xC), 1, sp);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
