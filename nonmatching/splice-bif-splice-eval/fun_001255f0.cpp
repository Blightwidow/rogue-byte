extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
void *func_001255F0(void *arg0, s32 arg1, void *arg2) {
    s32 mask = -1;
    char *node = 0;

    if (*(s32 *)arg2 != 0) {
        node = *(char **)((char *)arg2 + 4);
    }
    if (node != 0) {
        do {
            mask &= *(s32 *)(node + 0xC);
            node = *(char **)(node + 0x10);
        } while (node != 0);
    }
    *(s32 *)((char *)arg0 + 4) = mask;
    *(s32 *)arg0 = 0x15;
    return arg0;
}
}
