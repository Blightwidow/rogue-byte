struct CByteQueue {
    int pad[4];
    int cbFree;
    int pad2[3];
    int CbFill(int, unsigned char *);
};
struct CQueueOutputIop { int pad[4]; };
extern "C" int CQueueOutputIop_FInit(CQueueOutputIop *, void *);
struct CMpegAudio {
    int state;
    int idStream;
    char header[0x28];
    CByteQueue qHeader;
    CByteQueue qData;
    CQueueOutputIop qIop;
    int FAccept(int, unsigned char *);
};
int CMpegAudio::FAccept(int cb, unsigned char *pb)
{
    if (state == 0)
        return 0;
    unsigned int idChannel = pb[3];
    if (idStream == -1)
        idStream = idChannel;
    if (idStream != (int)idChannel)
        return 1;
    cb -= 4;
    pb += 4;
    if (state == 1) {
        int cbTaken = qHeader.CbFill(cb, pb);
        cb -= cbTaken;
        pb += cbTaken;
        if (qHeader.cbFree > 0)
            return 1;
        if (CQueueOutputIop_FInit(&qIop, header) != 0)
            state = 2;
        else
            state = 0;
    }
    if (qData.cbFree >= cb) {
        qData.CbFill(cb, pb);
        return 1;
    }
    return 0;
}
