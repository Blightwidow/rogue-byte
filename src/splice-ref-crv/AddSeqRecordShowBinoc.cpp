extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
void *PjsgeAllocJsg(void *, int, int);

void AddSeqRecordShowBinoc(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *record = (char *)PjsgeAllocJsg(arg0, 0x3B, arg4);

    *(s32 *)(record + 0x10) = arg1;
    *(s32 *)(record + 0x14) = arg2;
    *(s32 *)(record + 0x18) = arg3;
}
}
