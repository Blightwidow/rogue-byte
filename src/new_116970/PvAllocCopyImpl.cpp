extern "C" {
void CopyAb__FPvT0Ui(void *, int, int);
void *PvAllocCopyImpl(char *arg0, int arg1, int arg2, int arg3) {
    char *vtable = *(char **)arg0;
    void *result = (*(void *(**)(char *, int, int))(vtable + 0xC))(arg0 + *(short *)(vtable + 8), arg1, arg3);
    CopyAb__FPvT0Ui(result, arg2, arg1);
    return result;
}
}
