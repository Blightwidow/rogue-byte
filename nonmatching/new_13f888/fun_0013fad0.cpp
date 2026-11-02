extern "C" {
int IdCurrentLevel();
int func_0013FAD0(int count, short *ids) {
    int id = IdCurrentLevel();
    int index = 0;
    if (id == -1) goto found;
    goto test;
next:
    index++;
test:
    if (index < count) {
        if (*ids++ != id) goto next;
    } else
        return 0;
found:
    return 1;
}
}
