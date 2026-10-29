// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" void FreeSlotheapPv(char *, char *);

extern "C" void FreeSwXaList__FP2SWP2XA(char *sw, char *xaList)
{
    char *node = xaList;
    char *nextNode;
    if (node != 0) {
        do {
            nextNode = *(char **)(node + 0xC);
            FreeSlotheapPv(sw + 0x40E8, node);
            node = nextNode;
        } while (node != 0);
    }
}
