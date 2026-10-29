/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" int func_001CB770(char *self, int value) {
    int count = *(int *)(self + 0x3F04);
    int index = 0;
    if (count > 0) {
        char *entry = *(char **)(self + 0x3F08) + 0x10;
        do {
            if (*(int *)entry == value) {
                return index;
            }
            index += 1;
            entry += 0x6C;
        } while (index < count);
    }
    return -1;
}
