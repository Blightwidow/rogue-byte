struct sceMpeg; struct sceMpegCbData;
struct CMpeg { char pad[0x174]; int cbUsed; };
extern "C" int CMpeg_CbDemuxed(CMpeg *, int);
extern "C" void *memset(void *, int, unsigned);
extern "C" void CbFill__10CByteQueueiPUc(void *, int, void *);
extern "C" void FreeDrain__10CByteQueuei(void *, int);
extern "C" void CbDrain__10CByteQueueiP12CQueueOutput(void *, int, void *);
extern "C" void Update__10CMpegAudio(void *);
extern char D_002D4220[];

int FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg(sceMpeg *, sceMpegCbData *, CMpeg *pmpeg)
{
    int work[16];

    while (pmpeg->cbUsed <= 0xfff) {
        int result = CMpeg_CbDemuxed(pmpeg, 1);
        if (result == 2) {
            memset(work, 0, 0x40);
            CbFill__10CByteQueueiPUc((char *)pmpeg + 0x160, 0x40 - (pmpeg->cbUsed % 0x20), work);
            break;
        }
        if (result == 1)
            Update__10CMpegAudio((char *)pmpeg + 0x180);
    }
    work[0] = (int)D_002D4220;
    FreeDrain__10CByteQueuei((char *)pmpeg + 0x160, 0);
    CbDrain__10CByteQueueiP12CQueueOutput((char *)pmpeg + 0x160, 0, work);
    return 1;
}
