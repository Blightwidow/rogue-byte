extern "C" void func_001A6E80(char *obj, int on)
{
    if (on != 0) {
        int word = *(int *)(obj + 0x40);
        if ((word ^ 1) & 1) {
            *(int *)word = *(int *)word | 8;
            return;
        }
        *(int *)(obj + 0x40) = word | 8;
        return;
    }
    int word = *(int *)(obj + 0x40);
    if ((word ^ 1) & 1) {
        *(int *)word = *(int *)word & ~8;
        return;
    }
    *(int *)(obj + 0x40) = word & ~8;
}
