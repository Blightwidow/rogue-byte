char *RefOpLength(char *arg0, int unused_a1, char *arg2) {
    int count;
    char *node;

    count = 0;
    if (*(int *)arg2 == 0x1F) {
        node = *(char **)(arg2 + 4);
        if (node != 0) {
            do {
                node = *(char **)(node + 0x10);
                count += 1;
            } while (node != 0);
        }
    }
    *(int *)(arg0 + 4) = count;
    *(int *)arg0 = 0x15;
    return arg0;
}
