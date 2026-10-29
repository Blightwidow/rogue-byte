extern "C" void CRef_ConstructBasic(void *, int);
extern "C" void RefEnsureOption__FP5BASICiP4CRef(void *, int, int, void *);
extern "C" void CRef_Destruct(void *);

void func_00132E40(int arg0, int arg1) {
    char option[0x10];
    char ref[0x10];

    CRef_ConstructBasic(option, 0);
    RefEnsureOption__FP5BASICiP4CRef(ref, arg0, arg1, option);
    CRef_Destruct(ref);
    CRef_Destruct(option);
}
