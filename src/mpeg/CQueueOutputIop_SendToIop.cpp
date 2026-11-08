// SPDX-License-Identifier: GPL-3.0-or-later
struct SIFDMA { void *src; char *dst; int size; int attr; };
struct QUEUE {
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
extern "C" void FlushCache(int);
extern "C" unsigned int sceSifSetDma(SIFDMA *, int);
extern "C" int sceSifDmaStat(unsigned int);
extern "C" void func_00232FE8(int, int);

// 0x1B2DB8. Retail's wait loop holds two nops between `jal sceSifDmaStat` (and its delay slot) and `bgez`: that is the assembler's
// short-loop padding (ps2eeas pads the backward loop), not source; a plain do/while gives them. The ADPCM tail's registers
// (cbTotal in $a1, -1 in $t0, quotient in $v0) come from `iround` holding `iblock / cChannel % 4` as one user variable: with the
// modulo applied at the use instead, local-alloc ties the subtraction to the quotient and every register shifts.
int CQueueOutputIop_SendToIop(QUEUE *queue, int cb, void *pbSource)
{
    int ibDestination = 0;
    if (queue->wfmt != 0x10)
        ibDestination = queue->ibWrite;
    SIFDMA dma;
    dma.src = pbSource;
    dma.dst = queue->pbIop + ibDestination;
    dma.size = cb;
    dma.attr = 0;
    FlushCache(0);
    unsigned int id = sceSifSetDma(&dma, 1);
    int status;
    do {
        status = sceSifDmaStat(id);
    } while (status >= 0);
    if (queue->wfmt == 0x10) {
        int iblock = queue->cbTotal / 1024;
        int cChannel = queue->cChannel;
        int iround = iblock / cChannel % 4;
        int ichannel = iblock % cChannel;
        func_00232FE8(cb, iround * 0x400 + ichannel * 0x1000);
    }
    return cb;
}
