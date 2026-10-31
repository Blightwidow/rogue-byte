struct CQueueOutput;
struct CByteQueue {
    int pad[8];
    int CbDrain(int, CQueueOutput *);
};
struct CQueueOutputIop {
    int pad0;
    int wfmt;
    int rate;
    int cChannel;
    int pad10;
    int pbIop;
    int cbBuffer;
    int pad1C[2];
    int cbFree;
};
extern "C" void snd_InitMovieSound(int, int, int, int, int);
extern "C" void CQueueOutputIop_Update(CQueueOutputIop *);
struct CMpegAudio {
    int state;
    int pad4[11];
    CByteQueue qHeader;
    CByteQueue qData;
    CQueueOutputIop qIop;
    void Update();
};
void CMpegAudio::Update()
{
    switch (state) {
    case 2:
        qData.CbDrain(qIop.cbFree, (CQueueOutput *)&qIop);
        if (qIop.cbFree == 0) {
            if (qIop.wfmt == 0x10)
                snd_InitMovieSound(qIop.pbIop, 0x1000, 0, qIop.rate, qIop.cChannel);
            else
                snd_InitMovieSound(qIop.pbIop, qIop.cbBuffer, qIop.pbIop, 0, 0);
            state = 3;
        }
        break;
    case 3: {
        CQueueOutputIop *piop = &qIop;
        CQueueOutputIop_Update(piop);
        qData.CbDrain(qIop.cbFree, (CQueueOutput *)piop);
        break;
    }
    }
}
