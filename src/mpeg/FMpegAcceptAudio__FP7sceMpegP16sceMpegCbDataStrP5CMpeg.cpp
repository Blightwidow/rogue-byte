struct CMpegAudio { int x; int FAccept(int, unsigned char *); };
struct CMpeg { char pad[0x180]; CMpegAudio audio; };
struct sceMpeg;
struct sceMpegCbDataStr { int a, b; unsigned char *data; int size; };
extern "C" int FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg(sceMpeg *, sceMpegCbDataStr *cb, CMpeg *mpeg) {
    return mpeg->audio.FAccept(cb->size, cb->data);
}
