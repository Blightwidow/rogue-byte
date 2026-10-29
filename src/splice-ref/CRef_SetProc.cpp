extern "C" void CRef_Destruct(char *);

char *CRef_SetProc(char *arg0, int *arg1) {
    *arg1 += 1;
    CRef_Destruct(arg0);
    *(int **)(arg0 + 4) = arg1;
    *(int *)arg0 = 0x20;
    return arg0;
}
