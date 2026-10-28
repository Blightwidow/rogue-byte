/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CByteQueue { void Init(int, void *); };
struct CMpegAudio { void Init(); };
struct CMpeg {
    char pad0[0x10C]; int s10C; char *pbBuffer; int pbas; char sdk[0x160 - 0x118];
    CByteQueue queue; char pad1[0x180 - 0x160 - 1]; CMpegAudio audio;
};
extern "C" {
extern int B_002E1E54;
extern int g_2dedbc;
int CMpeg_CbDemuxed(CMpeg *, int);
int sceMpegInit();
void sceMpegCreate(void *, int, int);
void sceMpegAddStrCallback(void *, int, int, void *, CMpeg *);
void sceMpegAddCallback(void *, int, void *, CMpeg *);
void FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg();
void FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg();
void FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg();
void FMpegBackground();
void func_001B3508();
}
void CMpeg_Start(CMpeg *mpeg, int pbas)
{
    mpeg->pbas = pbas;
    mpeg->s10C = 0;
    void *sdk = mpeg->sdk;
    mpeg->queue.Init(0x40000, (void *)((int)(mpeg->pbBuffer + 0x245A80) | 0x20000000));
    mpeg->audio.Init();
    sceMpegInit();
    sceMpegCreate(sdk, (int)(mpeg->pbBuffer + 0x98000), 0x1ADA60);
    sceMpegAddStrCallback(sdk, 0, 0, (void *)FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg, mpeg);
    sceMpegAddStrCallback(sdk, 2, 0, (void *)FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg, mpeg);
    sceMpegAddStrCallback(sdk, 3, 0, (void *)FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg, mpeg);
    sceMpegAddStrCallback(sdk, 2, B_002E1E54 + 1, (void *)FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg, mpeg);
    sceMpegAddStrCallback(sdk, 3, B_002E1E54 + 1, (void *)FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg, mpeg);
    sceMpegAddCallback(sdk, 1, (void *)FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg, mpeg);
    sceMpegAddCallback(sdk, 4, (void *)FMpegBackground, mpeg);
    sceMpegAddCallback(sdk, 0, (void *)func_001B3508, mpeg);
    int done;
    do {
        done = CMpeg_CbDemuxed(mpeg, 1);
        asm("nop");
        asm("nop");
    } while (done == 0);
    g_2dedbc = 0;
}
