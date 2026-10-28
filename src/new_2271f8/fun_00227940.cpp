/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SUBTITLE { int pad0; int pad4; unsigned grf; };
struct GRFCHAR { unsigned grf; unsigned char ch; char pad[3]; };
struct GRFTABLE { GRFCHAR entry[16]; };
extern "C" {
extern const GRFTABLE RO_002A97F8;
extern const char RO_STR_002A9878[];
int sprintf(char *, const char *, ...);
void func_00227940(SUBTITLE *sub, char *dst);
}
void func_00227940(SUBTITLE *sub, char *dst)
{
    GRFTABLE table = RO_002A97F8;
    *dst = 0;
    for (unsigned index = 0; index < 16; index++) {
        if (sub->grf & table.entry[index].grf)
            sprintf(dst, RO_STR_002A9878, table.entry[index].ch);
    }
}
