// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" void *func_00125640(char *out, int unused, int *source)
{
    int flags = 0;
    int *node = 0;
    if (source[0] != 0) {
        node = (int *)source[1];
    }
    if (node != 0) {
        do {
            flags |= node[3];
            node = (int *)node[4];
        } while (node != 0);
    }
    ((int *)out)[1] = flags;
    ((int *)out)[0] = 0x15;
    return out;
}
