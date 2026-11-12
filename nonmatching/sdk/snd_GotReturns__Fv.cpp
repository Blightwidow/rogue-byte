// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern unsigned *D_002C4640;
extern int D_002C4644;
extern int D_002C46B8;
extern char B_00443800[];
extern "C" void FlushCache(int);
extern "C" int sceSifCheckStatRpc(char *);
extern "C" int printf(const char *, ...);
int snd_GotReturns()
{
    FlushCache(0);
    if (D_002C4640 == 0)
        return 1;
    if (sceSifCheckStatRpc(B_00443800) != 0)
        return 0;
    unsigned *returns = D_002C4640;
    unsigned first = returns[0];
    if (first == 0xFFFFFFFFu) {
        if (returns[D_002C4644 + 1] == first) {
            D_002C4640 = 0;
            return 1;
        }
    }
    if (D_002C46B8 != 0)
        return 0;
    printf("989snd.c: Sif says RPC isn't busy, but we still don't have returns from the \n");
    return 0;
}
