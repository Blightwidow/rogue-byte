// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct TARGET { char pad[0x128]; int stage; };
struct SW { char pad[0x4774]; TARGET *target; };
extern SW B_003DD490;
extern "C" char *PchzStringFromId(SW *, int);
extern "C" char *strcpy(char *, const char *);
extern "C" void func_0015DA88(char *dest, int flag)
{
    TARGET *target = B_003DD490.target;
    if (target == 0)
        return;
    int stage;
    if (flag != 0)
        stage = target->stage - 1;
    else
        stage = target->stage;
    switch (stage) {
    case 1: case 3: case 5: case 7: case 9: case 11: case 13: case 15:
        strcpy(dest, PchzStringFromId(&B_003DD490, 0x77));
        break;
    case 2: case 4: case 6: case 8: case 10: case 12: case 14: case 16:
        strcpy(dest, PchzStringFromId(&B_003DD490, 0x78));
        break;
    }
}
