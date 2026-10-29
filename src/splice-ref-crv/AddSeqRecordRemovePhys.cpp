/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" char *PjsgeAllocJsg(void *pool, int kind, int flag);
extern "C" void AddSeqRecordRemovePhys(void *pool, int arg1, int arg2) {
    char *record = PjsgeAllocJsg(pool, 0x31, 1);
    *(int *)(record + 0x10) = arg1;
    *(int *)(record + 0x14) = arg2;
}
