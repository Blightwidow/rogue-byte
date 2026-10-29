extern "C" {
/* 0x1B3388: FMpegAcceptVideo: accept when the queue at +0x170 has room for the chunk size at +0xC; fill it from +0x8 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
s32 CbFill__10CByteQueueiPUc(void *, u32, u8 *);
s32 FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg(s32 arg0, void *arg1, void *arg2) {
    u32 size = *(u32 *)((char *)arg1 + 0xC);
    if (*(u32 *)((char *)arg2 + 0x170) < size) {
        return 0;
    }
    CbFill__10CByteQueueiPUc((char *)arg2 + 0x160, size, *(u8 **)((char *)arg1 + 8));
    return 1;
}
}
