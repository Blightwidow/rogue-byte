extern "C" void InitSo(char *);
extern "C" void func_001B4438(char *obj) {
    InitSo(obj);
    *(long *)(obj + 0x148) &= ~(1L << 35);
}
