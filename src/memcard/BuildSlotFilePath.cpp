// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" int sprintf(char *, const char *, ...);

extern "C" void BuildSlotFilePath(int first, int second, char *buffer)
{
    int offset = second - 0x24;
    int slotIndex = (offset - first) * (int)0xCF5E7729;
    slotIndex = (slotIndex >> 2) + 1;
    sprintf(buffer, "/%s/%s%d", "BASCUS-97316YAOTWTD!", "save", slotIndex);
}
