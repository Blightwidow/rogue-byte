// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

struct ALLOCREQ_1BC088 { int cb; int cbAlign; };
extern "C" void LoadCrvFromBrx(void *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ_1BC088 *);

extern "C" void Obstacle_LoadFromBrx(char *obstacle)
{
    ALLOCREQ_1BC088 allocreq;
    LoadCrvFromBrx(obstacle);
    allocreq.cb = (*(int *)(obstacle + 0xE8) * 0x10) - 0x10;
    allocreq.cbAlign = 0x10;
    *(void **)(obstacle + 0x1EC) = PvAllocSwClearImpl__Fi(&allocreq);
}
