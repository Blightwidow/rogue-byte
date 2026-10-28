// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CMD { int type; char pad[0xC]; int value; char pad2[8]; int value2; };
int GoalBrain_FCmdEqual(CMD *a, CMD *b)
{
    int type = a->type;
    if (type != b->type)
        return 0;
    switch (type) {
    case 9:
    case 10:
    case 11:
        return a->value2 == b->value2;
    case 4:
        return a->value == b->value;
    case 5:
        return a->value == b->value;
    case 3:
        return a->value == b->value;
    case 13:
        return a->value == b->value;
    case 2:
        return a->value == b->value;
    case 14:
        return a->value == b->value;
    case 18:
        return a->value == b->value;
    case 6:
        return a->value == b->value;
    default:
        return 1;
    }
}
