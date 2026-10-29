// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" char *PjsgeAllocJsg(int, int, int);

extern "C" void AddSeqRecordWaitForButton(int first, int arg1, int arg2)
{
    char *record = PjsgeAllocJsg(first, 0x42, 0);
    if (arg1 == -1) {
        arg1 = 0x40;
    }
    *(int *)(record + 0x14) = arg2;
    *(int *)(record + 0x10) = arg1;
}
