struct SIFDMA { void *src; char *dst; int size; int attr; };
struct QUEUE { int unk0; int wfmt; int unk8; int cchannel; int unk10; char *pbIop; int unk18; int ibWrite; char pad[0x2C - 0x20]; int cbTotal; };
extern "C" void FlushCache(int);
extern "C" unsigned sceSifSetDma(SIFDMA *, int);
extern "C" int sceSifDmaStat(unsigned);
extern "C" void func_00232FE8(int, int);

int CQueueOutputIop_SendToIop(QUEUE *self, int cb, void *pbSource)
{
    int ibDestination = 0;
    if (self->wfmt != 0x10)
        ibDestination = self->ibWrite;
    SIFDMA dma;
    dma.src = pbSource;
    dma.dst = self->pbIop + ibDestination;
    dma.size = cb;
    dma.attr = 0;
    FlushCache(0);
    unsigned id = sceSifSetDma(&dma, 1);
    int st;
    do {
        st = sceSifDmaStat(id);
        asm("nop");
        asm("nop");
    } while (st >= 0);
    if (self->wfmt == 0x10) {
        int cbTotal = self->cbTotal;
        int cchannel = self->cchannel;
        int iblock = cbTotal / 1024;
        int iround = iblock / cchannel;
        int ichannel = iblock % cchannel;
        func_00232FE8(cb, (iround % 4) * 0x400 + ichannel * 0x1000);
    }
    return cb;
}
