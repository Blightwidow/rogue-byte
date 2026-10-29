struct CRef_132D88 { int tagk; int value; };
extern "C" void CRef_Destruct(void *);
extern "C" void RefEnsureOption__FP5BASICiP4CRef(void *, void *, int, CRef_132D88 *);

void EnsureOptionInt_132d88(void *arg0, int arg1, int arg2) {
    CRef_132D88 obj;
    CRef_132D88 result;
    obj.tagk = 0x15;
    obj.value = arg2;
    RefEnsureOption__FP5BASICiP4CRef(&result, arg0, arg1, &obj);
    CRef_Destruct(&result);
    CRef_Destruct(&obj);
}
