// SPDX-License-Identifier: GPL-3.0-or-later
struct CRITSECT;
void EnterCritSect(CRITSECT *);
void LeaveCritSect(CRITSECT *);
struct QW { char b[16]; };
extern "C" void FlushCache(int);
extern "C" void sceGsPutDrawEnv(void *);
extern "C" void func_00241728(int, QW *);
extern "C" void func_002417F0(int, int, int);
extern "C" char B_002DEBD0, B_002DECC0, B_002DFB40;
extern "C" int g_2de598, g_2dedb0;
void BlastAqwGifsBothFrames(QW *pqw)
{
    int i = 0;
    EnterCritSect((CRITSECT *)&B_002DFB40);
    FlushCache(0);
    do {
        void *drawenv;
        if ((i + g_2dedb0) & 1)
            drawenv = &B_002DEBD0;
        else
            drawenv = &B_002DECC0;
        i++;
        sceGsPutDrawEnv(drawenv);
        func_00241728(g_2de598, pqw);
    } while (i < 2);
    func_002417F0(g_2de598, 0, 0);
    LeaveCritSect((CRITSECT *)&B_002DFB40);
}
