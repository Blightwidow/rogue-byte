/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW;
struct LEVELBLK { char b[0x40]; };
struct TRANS { unsigned grf; LEVELBLK level; int oidSpawn; int oidSpawnParent; };
extern char B_00443740[];
void ActivateWipe(char *, TRANS *, int, int);
void SetSwLoadRequest(SW *, TRANS *);
void RequestTransition(SW *sw, void *level, int oidSpawn, int oidSpawnParent, unsigned grf, int oidWipe)
{
    char *current = (char *)sw + 0x3C40;
    TRANS trans;
    trans.level = *(LEVELBLK *)(level ? level : current);
    char *alevel = trans.level.b;
    trans.oidSpawn = oidSpawn;
    trans.oidSpawnParent = oidSpawnParent;
    trans.grf = grf;
    int same;
    if (alevel == current)
        same = 1;
    else if (current == 0)
        same = 0;
    else {
        unsigned x = *(unsigned *)(alevel + 8) ^ *(unsigned *)(alevel + 0x38);
        unsigned y = *(unsigned *)(current + 8) ^ *(unsigned *)(current + 0x38);
        same = x == y;
    }
    if (same) trans.grf |= 2;
    if (oidWipe != -1)
        ActivateWipe(B_00443740, &trans, oidWipe, 1);
    else
        SetSwLoadRequest(sw, &trans);
}
