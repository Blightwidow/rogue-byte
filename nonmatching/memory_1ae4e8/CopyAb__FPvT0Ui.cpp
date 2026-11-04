extern "C" void CopyAqw__FPvT0i(void *, void *, int);

void CopyAb__FPvT0Ui(void *pvDst, void *pvSrc, unsigned int cb)
{
    unsigned int grfAlign = (unsigned int)pvDst | (unsigned int)pvSrc | cb;
    if ((grfAlign & 3) != 0) {
        unsigned char *pbDst = (unsigned char *)pvDst;
        unsigned char *pbSrc = (unsigned char *)pvSrc;
        unsigned int ib = 0;
        if (cb != 0) {
            do {
                *pbDst++ = *pbSrc++;
                ib++;
            } while (ib < cb);
        }
    } else if ((grfAlign & 0xf) != 0) {
        int cw = cb >> 2;
        unsigned int *pwDst = (unsigned int *)pvDst;
        cb = cw & 3;
        unsigned int *pwSrc = (unsigned int *)pvSrc;
        int n;
        int cwBlocks = cw - cb;
        if (cb != 0) {
            n = cb;
            do {
                *pwDst++ = *pwSrc++;
                n--;
            } while (n != 0);
        }
        if (cwBlocks > 0) {
            n = 0;
            do {
                unsigned int w0 = pwSrc[0];
                n += 4;
                unsigned int w1 = pwSrc[1];
                unsigned int w2 = pwSrc[2];
                unsigned int w3 = pwSrc[3];
                pwDst[0] = w0;
                pwSrc += 4;
                pwDst[1] = w1;
                pwDst[2] = w2;
                pwDst[3] = w3;
                pwDst += 4;
            } while (n < cwBlocks);
        }
    } else {
        CopyAqw__FPvT0i(pvDst, pvSrc, cb >> 4);
    }
}
