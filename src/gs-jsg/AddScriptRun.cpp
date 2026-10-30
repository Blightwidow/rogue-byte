extern "C" {
char *PcmdAllocScript(int, int, int);
void AddScriptRun(int arg0, int arg1, int arg2, int arg3) {
    char *command = (char *)PcmdAllocScript(arg0, 6, arg1);
    *(int *)(command + 8) = arg2;
    *(int *)(command + 0xC) = arg3;
}
}
