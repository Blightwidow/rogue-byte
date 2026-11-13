// SPDX-License-Identifier: GPL-3.0-or-later
// The IOP output queue; field names as in CQueueOutputIop_SendToIop (src/mpeg/CQueueOutputIop_SendToIop.cpp).
struct QUEUE_1B2BE0 {
    int unk0;
    int wfmt;
    int unk8;
    int cChannel;
    int unk10;
    char *pbIop;
    int cbBuffer;
    int ibWrite;
    int ibRead;
    int cbFree;
    int cbQueued;
    int cbTotal;
};
extern "C" {
void CQueueOutputIop_Deinterleave(QUEUE_1B2BE0 *queue, int cbTotal, char *pb);
int CQueueOutputIop_SendToIop(QUEUE_1B2BE0 *queue, int cb, char *pbSource);

int CQueueOutputIop_CbWrite(QUEUE_1B2BE0 *queue, int cbRequest, char *pb)
{
    int cbWritten = 0;
    int cbLeft = cbRequest;
    if (cbLeft <= 0 || queue->cbFree < cbLeft)
        cbLeft = queue->cbFree;
    if (queue->wfmt == 0x10) {
        cbLeft &= -(queue->cChannel << 10);
        CQueueOutputIop_Deinterleave(queue, cbLeft, pb);
    } else {
        cbLeft &= ~0x3FF;
    }
    while (cbLeft != 0) {
        int cbRoom = queue->cbBuffer - queue->ibWrite;
        int cb;
        if (cbLeft < cbRoom)
            cb = cbLeft;
        else
            cb = cbRoom;
        char *pbSource = pb + cbWritten;
        if (queue->wfmt == 0x10) {
            cb = 0x400;
            int iround = (queue->cbTotal / 1024 / queue->cChannel) % 4;
            if (iround == 0) {
                pbSource[1] = 6;
                pbSource[0x11] = 2;
            } else if (iround == 3) {
                pbSource[0x3F1] = iround;
            }
        }
        int cbSent = CQueueOutputIop_SendToIop(queue, cb, pbSource);
        cbLeft -= cbSent;
        if (cbSent == 0)
            break;
        cbWritten += cbSent;
        int ibWrite = queue->ibWrite + cbSent;
        queue->ibWrite = ibWrite;
        queue->ibWrite = ibWrite % queue->cbBuffer;
        queue->cbQueued += cbSent;
        queue->cbFree -= cbSent;
        queue->cbTotal += cbSent;
        if (cbRequest <= 0)
            break;
    }
    return cbWritten;
}
}
