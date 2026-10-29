struct EnsureOptionArg_132C78 {
    int type;
    float value;
};

extern "C" void RefEnsureOption__FP5BASICiP4CRef(void *, char *, int, void *);
extern "C" void CRef_Destruct(void *);

void EnsureOptionFloat(char *arg0, int arg1, float fparg0) {
    EnsureOptionArg_132C78 option;
    char ref[0x10];

    option.type = 0x16;
    option.value = fparg0;
    RefEnsureOption__FP5BASICiP4CRef(ref, arg0, arg1, &option);
    CRef_Destruct(ref);
    CRef_Destruct(&option);
}
