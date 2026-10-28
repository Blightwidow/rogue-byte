struct QUEUE { int unk0; int wfmt; int unk8; int cChannel; int unk10; int pbIop; int cbBuffer; int ibWrite; int ibRead; int cbFree; int cbQueued; };
extern "C" int func_00233018();
extern "C" unsigned func_00232FC0();
extern "C" void CQueueOutputIop_Update(QUEUE *pqueue)
{
    if (pqueue->wfmt == 0x10) {
        int cbPlayed = func_00233018() * pqueue->cChannel;
        if (cbPlayed >= 0) {
            int cbBuffer = pqueue->cbBuffer;
            if (cbBuffer >= cbPlayed) {
                int ibRead = cbPlayed % cbBuffer;
                pqueue->ibRead = ibRead;
                if (ibRead == pqueue->ibWrite) {
                    pqueue->cbFree = cbBuffer;
                } else {
                    int cbFree = (ibRead - pqueue->ibWrite) + cbBuffer;
                    pqueue->cbFree = cbFree;
                    pqueue->cbFree = cbFree % cbBuffer;
                }
            }
        }
        pqueue->cbQueued = pqueue->cbBuffer - pqueue->cbFree;
    } else {
        unsigned pbPlaying = func_00232FC0();
        int pbIop = pqueue->pbIop;
        int ibWrite = pqueue->ibWrite;
        int cbBuffer = pqueue->cbBuffer;
        int t = (int)(pbPlaying & 0xffffff) - pbIop - ibWrite - 0x400; asm("" : "+r" (t)); int cbAhead = t + cbBuffer;
        pqueue->cbFree = cbAhead;
        int cbFree = cbAhead % cbBuffer;
        pqueue->cbFree = cbFree;
        int cbQueued = cbBuffer - cbFree;
        pqueue->cbQueued = cbQueued;
        int ibRead = (ibWrite - cbQueued) + cbBuffer;
        pqueue->ibRead = ibRead;
        pqueue->ibRead = ibRead % cbBuffer;
    }
}
