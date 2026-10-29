extern "C" void PauseMenu_Push(char *, int, int, int, int);
extern char B_003D9ED0[];

void func_001B0688(char *arg0) {
    PauseMenu_Push(B_003D9ED0, *(int *)(arg0 + 0x8), *(int *)(arg0 + 0xC), 0, *(int *)(arg0 + 0x18));
    if (arg0 != 0) {
        *(int *)(arg0 + 0x1C) |= 2;
    }
}
