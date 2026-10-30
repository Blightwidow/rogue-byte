extern "C" void CopyAqw__FPvT0i(void *, void *, int);

void CopyAb__FPvT0Ui(void *pvDst, void *pvSrc, unsigned int cb)
{
    unsigned int grfAlign = (unsigned int)pvDst | (unsigned int)pvSrc | cb;
    if ((grfAlign & 3) != 0) {
        unsigned char *pbDst = (unsigned char *)pvDst;
        unsigned char *pbSrc = (unsigned char *)pvSrc;
        for (unsigned int ib = 0; ib < cb; ib++)
            *pbDst++ = *pbSrc++;
    } else if ((grfAlign & 0xf) != 0) {
        unsigned int *pwDst = (unsigned int *)pvDst;
        unsigned int *pwSrc = (unsigned int *)pvSrc;
        unsigned int cw = cb >> 2;
        cb = cw & 3;
        int cwBlocks = cw - cb;
        int n = cb;
        while (n != 0) {
            *pwDst++ = *pwSrc++;
            n--;
        }
        for (n = 0; n < cwBlocks; n += 4) {
            unsigned int w0 = pwSrc[0];
            unsigned int w1 = pwSrc[1];
            unsigned int w2 = pwSrc[2];
            unsigned int w3 = pwSrc[3];
            pwDst[0] = w0;
            pwDst[1] = w1;
            pwDst[2] = w2;
            pwDst[3] = w3;
            pwDst += 4;
            pwSrc += 4;
        }
    } else {
        CopyAqw__FPvT0i(pvDst, pvSrc, cb >> 4);
    }
}
