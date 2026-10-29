extern "C" void func_001FCF88(int arg0, long arg1) {
    char *target = (char *)(int)arg1;
    *(int *)(target + 0xA4) = arg0;
    *(int *)(target + 0xA0) = 0;
}
