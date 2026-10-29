extern "C" {
int func_001FD028(char *arg0, int arg1) {
    if (arg1 < 0 || arg1 >= *(int *)(arg0 + 0x18)) {
        return 0;
    }
    int index = ((int *)*(char **)(arg0 + 0x100))[arg1];
    return index >= 0 ? *(int *)(arg0 + 0xFC) + index * 4 : 0;
}
}
