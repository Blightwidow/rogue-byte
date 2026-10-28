struct CQueueInput { virtual int CbRead(int cb, void *pv); };
struct CByteQueue {
    char *pbBuffer; int cbBuffer; int ibFill; int ibDrain; int cbFree; int cbData; int cbHeld; int cbTotal;
    int CbFill(int cbMax, CQueueInput *pinput);
};
int CByteQueue::CbFill(int cbMax, CQueueInput *pinput)
{
    int cbDone = 0;
    int cbWanted = cbMax;
    if (cbMax < 1 || cbFree < cbMax)
        cbWanted = cbFree;
    while (cbWanted != 0) {
        int cbChunk = cbBuffer - ibFill;
        if (cbWanted < cbChunk)
            cbChunk = cbWanted;
        int cbRead = pinput->CbRead(cbChunk, pbBuffer + ibFill);
        if (cbRead == 0)
            break;
        cbDone += cbRead;
        cbWanted -= cbRead;
        int ibFillNew = ibFill + cbRead;
        ibFill = ibFillNew;
        ibFill = ibFillNew % cbBuffer;
        cbData += cbRead;
        cbFree -= cbRead;
        cbTotal += cbRead;
        if (cbMax < 1)
            break;
    }
    return cbDone;
}
