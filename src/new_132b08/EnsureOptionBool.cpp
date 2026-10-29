struct EnsureOptionBool_132BC8 {
    int type;
    int value;
};

extern "C" void RefEnsureOption__FP5BASICiP4CRef(void *, int, int, void *);
extern "C" void CRef_Destruct(void *);

void EnsureOptionBool(int arg0, int arg1, int arg2) {
    EnsureOptionBool_132BC8 option;
    char ref[0x10];

    option.type = 0x17;
    option.value = arg2 != 0;
    RefEnsureOption__FP5BASICiP4CRef(ref, arg0, arg1, &option);
    CRef_Destruct(ref);
    CRef_Destruct(&option);
}
