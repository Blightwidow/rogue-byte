extern "C" void func_0017F6B0(char *);
extern "C" void func_001815E8(char *, int);
extern "C" void TriggerRsmg(char *, int, char *, char *, int);
extern char B_003DD490[];

void func_00181598(char *arg0) {
    func_0017F6B0(arg0);
    func_001815E8(arg0, 0);
    TriggerRsmg(B_003DD490, *(int *)(arg0 + 0x200), arg0 + 0x204, arg0, 0);
}
