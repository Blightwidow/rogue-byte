struct QUEUE { int unk0; int wfmt; int unk8; int cChannel; int cbInterleave; };
struct ALLOCREQ { int cb; int align; };
struct FRAME { int pad[4]; };
extern "C" void CStackFrame_Construct(FRAME *);
extern "C" void CStackFrame_Destructor(FRAME *, int);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned);
extern "C" void CQueueOutputIop_Deinterleave(QUEUE *pqueue, int cb, char *pb)
{
    if (pqueue->wfmt != 0x10 || pqueue->cChannel == 1)
        return;
    FRAME frame;
    CStackFrame_Construct(&frame);
    int cbBlock = pqueue->cChannel << 10;
    ALLOCREQ req;
    req.cb = cbBlock;
    req.align = 0x10;
    char *pbTemp = (char *)PvAllocStackImpl__Fi(&req);
    int cbLeft = cb;
    char *pbBlock = pb;
    if (cbLeft != 0) {
        do {
            int cbNext = cbLeft - cbBlock;
            int ichannel = 0;
            int irun = 0;
            int ibSource = 0;
            if (cbBlock > 0) {
                do {
                    CopyAb__FPvT0Ui(pbTemp + ichannel * 0x400 + irun * pqueue->cbInterleave, pbBlock + ibSource, pqueue->cbInterleave);
                    ichannel++;
                    if (pqueue->cChannel <= ichannel) {
                        irun++;
                        ichannel = 0;
                    }
                    ibSource += pqueue->cbInterleave;
                } while (ibSource < cbBlock);
            }
            CopyAb__FPvT0Ui(pbBlock, pbTemp, cbBlock);
            pbBlock += cbBlock;
            cbLeft = cbNext;
        } while (cbLeft != 0);
    }
    CStackFrame_Destructor(&frame, 2);
}
