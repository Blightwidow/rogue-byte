extern "C" void SyncVBlank__Fv(void);
extern "C" void BlendDisplayOnBufferMismatch__Fv(void);
extern "C" void EnterCritSect__FP8CRITSECT(void *);
extern "C" void LeaveCritSect__FP8CRITSECT(void *);
extern "C" void FlushCache(int);
extern "C" void sceGsSwapDBuff(void *, int);
extern "C" void sceGsSetHalfOffset(void *, int, int, short);
extern "C" void sceGsSyncPath(int, int);
extern "C" char B_002DEB80, B_002DEBE0, B_002DFB40, g_2decd0;
extern "C" int B_002DEDB4, B_002DFB5C, D_002BE594, g_2dedb0, g_2dedb8, g_2dedbc;
extern "C" void SwapGsBuffers__Fv(void)
{
    void *drawenv;
    B_002DFB5C = 1;
    SyncVBlank__Fv();
    B_002DFB5C = 0;
    g_2dedb8 = B_002DEDB4;
    if (D_002BE594 > 0) {
        B_002DEDB4 = 0;
        D_002BE594 -= 1;
    } else {
        unsigned csr = *(unsigned *)0x12001000; unsigned bit = (csr >> 13) & 1; B_002DEDB4 = bit == 0;
    }
    EnterCritSect__FP8CRITSECT(&B_002DFB40);
    if (g_2dedb0 & 1)
        drawenv = &B_002DEBE0;
    else
        drawenv = &g_2decd0;
    sceGsSetHalfOffset(drawenv, 0x800, 0x800, (short)B_002DEDB4);
    FlushCache(0);
    g_2dedb0 = g_2dedb0 + 1;
    sceGsSwapDBuff(&B_002DEB80, g_2dedb0);
    if ((unsigned)(g_2dedbc - 1) < 2U)
        BlendDisplayOnBufferMismatch__Fv();
    sceGsSyncPath(0, 0);
    LeaveCritSect__FP8CRITSECT(&B_002DFB40);
}
