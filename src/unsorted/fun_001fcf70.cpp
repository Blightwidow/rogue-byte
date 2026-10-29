extern "C" void func_001FCF70(int arg0, long arg1) {
    int *p = (int *)(int)arg1;
    p[0x70 / 4] = arg0;
    p[0x6C / 4] = 0;
}
