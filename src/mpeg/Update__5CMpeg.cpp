struct CMpeg { char pad0[0x10C]; float tPicture; int pbBuffer; char pad1[0x118 - 0x114]; int s118; int s11c; int skipDraw; char pad2[0x23C - 0x124]; int sema; volatile int pending; };
extern "C" int CMpeg_CbDemuxed(CMpeg *, int);
extern "C" int sceMpegGetPicture(void *, int, int);
extern "C" void BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(CMpeg *);
extern "C" void DrawMpegFrame(CMpeg *);
extern "C" void FlushCache(int);
extern "C" void SignalSema(int);
extern "C" void Update__10CMpegAudio(void *);
extern float g_2ddf0c;

void Update__5CMpeg(CMpeg *pmpeg)
{
    int p;
    int q;
    if (pmpeg->pending == 1) {
        do {
            CMpeg_CbDemuxed(pmpeg, 0);
            p = pmpeg->pending;
            asm("nop");
        } while (p == 1);
    }
    int result = sceMpegGetPicture(&pmpeg->s118, *(int *)((char *)pmpeg + 0x110) + 0x285a80, 0x5cd);
    if (result >= 0) {
        if (pmpeg->skipDraw == 0) {
            pmpeg->tPicture = g_2ddf0c;
            BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(pmpeg);
            DrawMpegFrame(pmpeg);
            FlushCache(0);
        }
        if (pmpeg->pending != 0) {
            do {
                CMpeg_CbDemuxed(pmpeg, 0);
                q = pmpeg->pending;
                asm("nop");
            } while (q != 0);
        }
        SignalSema(pmpeg->sema);
        Update__10CMpegAudio((char *)pmpeg + 0x180);
    }
}
