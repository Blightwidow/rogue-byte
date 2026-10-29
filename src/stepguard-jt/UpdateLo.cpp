extern "C" float g_2dded0;

typedef void (*UpdateLoCall_1A5E28)(void *, int, int, int, int, int);

void UpdateLo(char *arg0) {
    if (*(float *)(arg0 + 0x30) <= g_2dded0) {
        char *child = *(char **)(arg0 + 0xC);
        UpdateLoCall_1A5E28 call = *(UpdateLoCall_1A5E28 *)(child + 0x1C);
        call(arg0 + *(short *)(child + 0x18), 1, 1, 0, 0, 0);
    }
}
