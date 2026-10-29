extern "C" {
int func_0019B0A8(char *arg0, char *arg1) {
    if (*(long *)(arg1 + 0x10) & (0x8000L << 33)) {
        return 0;
    }
    char *target = *(char **)(*(char **)(arg1 + 4) + 0xEC);
    if (*(long *)(target + 0x70) & 4) {
        return 0;
    }
    for (int index = 0; index < *(int *)arg0; index++) {
        if (target == ((char **)*(char **)(arg0 + 4))[index]) {
            return 0;
        }
    }
    return 1;
}
}
