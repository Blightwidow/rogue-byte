// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" void FlushCache(int);
extern "C" void sceGsSetHalfOffset(void *, int, int, short);
extern "C" void sceGsPutDrawEnv(void *);
extern "C" char B_002DEBD0, B_002DEBE0, B_002DECC0, g_2decd0;
extern "C" int B_002DEDB4, B_002DFB60, g_2dedb0, g_2dedbc;
extern "C" void RestoreGsBuffers__Fv(void)
{
    void *drawenv;
    if (g_2dedbc == 3)
        g_2dedbc = 2;
    if (B_002DFB60 != 0) {
        B_002DFB60 = 0;
        unsigned csr = *(unsigned *)0x12001000; unsigned bit = (csr >> 13) & 1; B_002DEDB4 = bit == 0;
        if (g_2dedb0 & 1)
            drawenv = &g_2decd0;
        else
            drawenv = &B_002DEBE0;
        sceGsSetHalfOffset(drawenv, 0x800, 0x800, (short)B_002DEDB4);
        FlushCache(0);
        if (g_2dedb0 & 1)
            drawenv = &B_002DECC0;
        else
            drawenv = &B_002DEBD0;
        sceGsPutDrawEnv(drawenv);
    }
}
