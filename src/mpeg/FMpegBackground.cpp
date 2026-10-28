struct CMpegAudio { void Update(); };
extern "C" void CMpeg_CbDemuxed(void *, int);
extern "C" int FMpegBackground(int a0, int a1, char *mpeg)
{
    CMpeg_CbDemuxed(mpeg, 0);
    ((CMpegAudio *)(mpeg + 0x180))->Update();
    return 1;
}
