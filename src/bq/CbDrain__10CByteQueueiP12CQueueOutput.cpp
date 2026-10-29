struct CQueueOutput { virtual int CbWrite(int cb, void *pv); virtual int FHold(); };
struct CByteQueue {
    char *pbBuffer; int cbBuffer; int ibFill; int ibDrain; int cbFree; int cbData; int cbHeld; int cbTotal;
    int CbDrain(int cbMax, CQueueOutput *poutput);
};
int CByteQueue::CbDrain(int cbMax, CQueueOutput *poutput)
{
    int cbDone = 0;
    int cbWanted = cbMax;
    if (cbMax < 1 || cbData < cbMax)
        cbWanted = cbData;
    while (cbWanted != 0) {
        int cbChunk = cbBuffer - ibDrain;
        if (cbWanted < cbChunk)
            cbChunk = cbWanted;
        int cbWritten = poutput->CbWrite(cbChunk, ibDrain + pbBuffer);
        if (cbWritten == 0)
            break;
        int ibDrainNew = ibDrain + cbWritten;
        ibDrain = ibDrainNew;
        ibDrain = ibDrainNew % cbBuffer;
        cbData -= cbWritten;
        if (poutput->FHold() != 0)
            cbHeld += cbWritten;
        else
            cbFree += cbWritten;
        cbWanted -= cbWritten;
        cbDone += cbWritten;
        if (cbMax < 1)
            break;
    }
    return cbDone;
}
