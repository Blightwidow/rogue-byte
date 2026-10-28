struct BAS { char pad[0x1C]; int cbEnd; int pbBase; int ibCur; int fMore; };
struct CMpeg { char pad0[0x114]; BAS *pbas; int s118[(0x170 - 0x118) / 4]; int limit170; char pad1[0x1E0 - 0x174]; int limit1E0; };
extern "C" void FlushCache(int);
extern "C" int SceMpegDemuxPss(void *, int, int);
extern "C" void Spool__18CBinaryAsyncStream(BAS *);
extern "C" void Skip__18CBinaryAsyncStreami(BAS *, int);

int CMpeg_CbDemuxed(CMpeg *pmpeg, int fBlock)
{
    int cb = pmpeg->pbas->cbEnd - pmpeg->pbas->ibCur;
    if (cb == 0) {
        do {
            if (pmpeg->pbas->fMore == 0)
                return 2;
            Spool__18CBinaryAsyncStream(pmpeg->pbas);
            cb = pmpeg->pbas->cbEnd - pmpeg->pbas->ibCur;
            if (cb != 0)
                goto demux;
        } while (fBlock != 0);
        return 0;
    }
demux:
    FlushCache(0);
    int consumed = SceMpegDemuxPss(pmpeg->s118, pmpeg->pbas->pbBase + pmpeg->pbas->ibCur, cb);
    Skip__18CBinaryAsyncStreami(pmpeg->pbas, consumed);
    if (consumed != 0)
        return 0;
    if (pmpeg->limit170 >= cb) {
        if (pmpeg->limit1E0 >= cb)
            return 2;
    }
    return 1;
}
