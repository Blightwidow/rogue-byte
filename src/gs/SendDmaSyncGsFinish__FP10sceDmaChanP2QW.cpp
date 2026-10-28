// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRITSECT;
struct sceDmaChan;
extern CRITSECT B_002DFB40;
extern int B_002DFB50;
extern int B_002DFB54;
void EnterCritSect__FP8CRITSECT(CRITSECT *);
void LeaveCritSect__FP8CRITSECT(CRITSECT *);
extern "C" int sceGsGetIMR(void);
extern "C" void sceGsPutIMR(int);
extern "C" void FlushCache(int);
extern "C" void func_00241728(sceDmaChan *, QW *);
extern "C" void WaitSema(int);
void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(sceDmaChan *chan, QW *packet)
{
    EnterCritSect__FP8CRITSECT(&B_002DFB40);
    B_002DFB54 = 1;
    *(volatile unsigned long *)0x12001000 |= 2;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    FlushCache(0);
    func_00241728(chan, packet);
    WaitSema(B_002DFB50);
    LeaveCritSect__FP8CRITSECT(&B_002DFB40);
}
