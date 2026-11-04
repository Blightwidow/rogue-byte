extern "C" float g_2ddf0c;
extern "C" void CMpeg_CbDemuxed(void *, int);
extern "C" int sceMpegGetPicture(void *, int, int);
extern "C" void BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(void *);
extern "C" void DrawMpegFrame(void *);
extern "C" void FlushCache(int);
extern "C" void SignalSema(int);
extern "C" void Update__10CMpegAudio(void *);

void Update__5CMpeg(char *self)
{
    if (*(int *)(self + 0x240) == 1) {
        do {
            CMpeg_CbDemuxed(self, 0);
        } while (*(int *)(self + 0x240) == 1);
    }
    int picture = sceMpegGetPicture(self + 0x118, *(int *)(self + 0x110) + 0x285A80, 0x5CD);
    if (picture < 0)
        return;
    if (*(int *)(self + 0x120) == 0) {
        *(float *)(self + 0x10C) = g_2ddf0c;
        BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(self);
        DrawMpegFrame(self);
        FlushCache(0);
    }
    if (*(int *)(self + 0x240) != 0) {
        do {
            CMpeg_CbDemuxed(self, 0);
        } while (*(int *)(self + 0x240) != 0);
    }
    SignalSema(*(int *)(self + 0x23C));
    Update__10CMpegAudio(self + 0x180);
}
