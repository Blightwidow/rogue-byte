struct ALLOCREQ1B2AA0 { int cb; int cbAlign; };
struct QueueIop1B2AA0 { char pad0[4]; int wfmt; char pad8[4]; int cchan; int cbChunk; };
extern "C" {
int CStackFrame_Construct(char *);
void CStackFrame_Destructor(char *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ1B2AA0 *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
void CQueueOutputIop_Deinterleave(QueueIop1B2AA0 *queue, int cbTotal, char *pb)
{
    char frame[0x10];
    ALLOCREQ1B2AA0 req;
    int wfmt = queue->wfmt;
    if (wfmt == 0x10 && queue->cchan != 1) {
        CStackFrame_Construct(frame);
        char *pbCur = pb;
        int cbBlock = queue->cchan << 10;
        req.cb = cbBlock;
        ALLOCREQ1B2AA0 *preq = &req;
        preq->cbAlign = wfmt;
        char *pbTemp = (char *)PvAllocStackImpl__Fi(preq);
        int cbLeft = cbTotal;
        while (cbLeft != 0) {
            {
                int ichan = 0;
                int ichanBlock = 0;
                int ib = 0;
                while (ib < cbBlock) {
                    int cbChunk = queue->cbChunk;
                    int ioff = ichan << 10;
                    ichan++;
                    CopyAb__FPvT0Ui(pbTemp + (ioff + ichanBlock * cbChunk), pbCur + ib, cbChunk);
                    if (!(ichan < queue->cchan)) {
                        ichanBlock++;
                        ichan = 0;
                    }
                    ib += queue->cbChunk;
                }
                char *pbDest = pbCur;
                CopyAb__FPvT0Ui(pbDest, pbTemp, cbBlock);
                pbCur += cbBlock;
            }
            cbLeft -= cbBlock;
        }
        CStackFrame_Destructor(frame, 2);
    }
}
}
