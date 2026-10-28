// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DMAS { int a0; unsigned ab; int a8; unsigned pb; };
extern "C" void EndDmaCnt__4DMAS(DMAS *);
extern "C" void func_001574A0(DMAS *);
extern "C" void Clear__4DMAS(DMAS *);
extern "C" void *PvAllocCopyImpl(void *, int, void *, int);
void DMAS_DetachCopy(DMAS *dmas, void *alloc, int *pcqw, unsigned *ppqw, void **ppvCopy)
{
    EndDmaCnt__4DMAS(dmas);
    func_001574A0(dmas);
    unsigned cqw = (dmas->pb - dmas->ab) >> 4;
    if (pcqw) *pcqw = cqw;
    if (ppqw) *ppqw = dmas->ab;
    if (ppvCopy) *ppvCopy = PvAllocCopyImpl(alloc, cqw << 4, (void *)dmas->ab, 4);
    Clear__4DMAS(dmas);
}
