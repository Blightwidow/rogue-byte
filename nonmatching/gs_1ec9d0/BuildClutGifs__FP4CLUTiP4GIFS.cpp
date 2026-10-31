typedef int s32; typedef unsigned short u16;
extern "C" {
void BuildImageGifs__FiiiiiiP4GIFS(s32, s32, s32, s32, s32, s32, void *);
void BuildClutGifs__FP4CLUTiP4GIFS(char *arg0, s32 arg1, void *arg2) {
    unsigned width = *(u16 *)(arg0 + 8);
    unsigned last = width - 1;
    s32 step = width >= 0x11U ? 0x10 : 8;
    BuildImageGifs__FiiiiiiP4GIFS(arg1, 1, 0, step, (s32)((last + step) & -step) / step, *(s32 *)(arg0 + 0x10), arg2);
}
}
