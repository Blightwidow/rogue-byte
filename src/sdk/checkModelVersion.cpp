// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" int func_00237EA8(const char *, int);
extern "C" int sceRead(int, char *, int);
extern "C" int sceClose(int);
extern "C" int AtoiPchz(char *);
extern "C" int checkModelVersion()
{
    char buffer[0x100];
    int handle = func_00237EA8("rom0:ROMVER", 1);
    unsigned count;
    char *cursor;
    if (handle < 0)
        return -1;
    count = 0;
    cursor = buffer;
    for (; count < 0x100; count++) {
        sceRead(handle, cursor, 1);
        if (*cursor++ == 0)
            break;
    }
    sceClose(handle);
    return AtoiPchz(&buffer[count - 9]) > 0x1315670;
}
