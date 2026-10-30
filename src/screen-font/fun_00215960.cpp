extern "C" {
void PrependSlEntry(char *, char *);
void func_002185F8(int, int, int, char *);
void func_00215960(char *arg0, char *arg1, int arg2) {
    switch (*(int *)(arg0 + 4)) {
    case 4:
        func_002185F8(*(int *)(*(char **)(arg0 + 8) + 0x84) + *(int *)(arg0 + 0x10) * 0x30, *(int *)(arg1 + 0x58), *(unsigned char *)(arg1 + 0x61), arg0);
        return;
    case 1:
    case 3:
    case 6:
    case 7:
        *(unsigned char *)(arg1 + 0x61) = arg2;
        PrependSlEntry(*(char **)(arg0 + 8) + 0xFC, arg1);
    default:
        return;
    }
}
}
