// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct CBinaryInputStream;
struct WARP { char pad0[0x144]; int desc; int cdesc; int *adesc; };
extern "C" void LoadVolumeFromBrx(WARP *, CBinaryInputStream *);
extern "C" void func_00228250(CBinaryInputStream *, int *);
extern "C" unsigned U8Read__18CBinaryInputStream(CBinaryInputStream *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" void LoadWarpFromBrx(WARP *warp, CBinaryInputStream *bis)
{
    int index;
    LoadVolumeFromBrx(warp, bis);
    func_00228250(bis, &warp->desc);
    int count = U8Read__18CBinaryInputStream(bis);
    ALLOCREQ req;
    req.cb = count << 2;
    req.cbAlign = 0x10;
    warp->cdesc = count;
    warp->adesc = (int *)PvAllocSwImpl__Fi(&req);
    for (index = 0; index < warp->cdesc; index++)
        func_00228250(bis, &warp->adesc[index]);
}
