extern "C" {
int func_002325E0(int, int, int *);
int snd_GetMasterVolume(int value) {
    return func_002325E0(0xA, 4, &value);
}
}
