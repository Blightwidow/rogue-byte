extern "C" {
extern float g_2dded0;
int FPausedEmitter__FP7EMITTER(char *emitter) {
    if (g_2dded0 < *(float *)(emitter + 0x148)) return 1;
    int state = *(int *)(emitter + 0xF0);
    if (state < 2) {
        if (state >= 0) {
            if (*(int *)(emitter + 0xF4) == 0) return 1;
        }
    }
    return 0;
}
}
