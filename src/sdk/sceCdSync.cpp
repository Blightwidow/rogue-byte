// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern int D_002C6750;
extern int D_002C6774;
extern char D_002C7910[];
extern "C" void func_00236960(const char *);
extern "C" void func_00235518(int);
extern "C" int sceSifCheckStatRpc(char *);
extern "C" int sceCdSync(int mode)
{
    if (mode == 0) {
        if (D_002C6750 > 0)
            func_00236960("N cmd wait\n");
        while (D_002C6774 != 0 || sceSifCheckStatRpc(D_002C7910) != 0)
            func_00235518(0xFA0);
        return 0;
    }
    if (D_002C6774 != 0 || sceSifCheckStatRpc(D_002C7910) != 0)
        return 1;
    return 0;
}
