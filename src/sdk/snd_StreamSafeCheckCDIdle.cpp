extern "C" {
int func_002325E0(int, int, int *);
int snd_StreamSafeCheckCDIdle(int value) {
    return func_002325E0(0x36, 4, &value);
}
}
