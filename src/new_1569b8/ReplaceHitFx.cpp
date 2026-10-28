// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT0 { char pad[8]; short delta; short index; void (*fn)(void *); };
struct VT1 { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct HITFX { char pad[0xC]; VT0 *vt; };
struct HITFX1 { char pad[0xC]; VT1 *vt; };
struct HITFXPARMS;
extern "C" void HitFx_Remove(HITFX *);
extern "C" void PhitfxSpawn_156548(HITFXPARMS *, QW, void *, HITFX **);
void ReplaceHitFx(HITFXPARMS *parms, QW pos, void *owner, HITFX **slot)
{
    if (*slot) {
        HitFx_Remove(*slot);
        HITFX1 *held = (HITFX1 *)*slot;
        held->vt->fn((char *)held + held->vt->delta);
        *slot = 0;
    }
    if (parms) {
        PhitfxSpawn_156548(parms, pos, owner, slot);
        HITFX *held = *slot;
        held->vt->fn((char *)held + held->vt->delta);
    }
}
