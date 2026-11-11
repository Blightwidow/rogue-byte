/* SPDX-License-Identifier: GPL-3.0-or-later */
/* PO, a playable object: class 50 of retail's class table (0x2BAAE8), 0x180 bytes, derived from SO (include/so.h). Its vtable
   adds slots 76 to 81 and holds InitPo (7), HandlePoMessage (5), LoadPoFromBrx (14), ClonePo (41). The name follows those
   functions (source: their recovered names) and Sly 1's PO (sly1 include/po.h, CC0). A field is read by a function certain to hold
   a PO (or a class derived from it). C++ only. */
#ifndef SLY2_PO_H
#define SLY2_PO_H
#include "so.h"

struct JOY;

struct PO : SO {
    virtual int FInvulnerable(int grf); /* 76: FInvulnerablePo, FInvulnerableJt, FInvulnerableBentley, FInvulnerableMurray; UpdateGuardDamage passes the damage's flags */
    virtual void Slot77();              /* 77: func_001C3ED0 */
    virtual void OnActive();            /* 78: OnPoActive, JT_OnPoActive */
    virtual void SetPlayable();         /* 79: SetPoPlayable */
    virtual void FIsAvailable();        /* 80: func_001C41B8, JT_FIsPoAvailable */
    virtual void Slot81();              /* 81: func_001C4228 */
    /* 0x150 */ struct JOY *pjoy;      /* the controller: UpdateLookRig, which calls JT slot 99 on the object */
    u8 unknown_0x154[0x2C];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(PO, 0x180);
SLY2_OFFSET_CHECK(PO, pjoy, 0x150);
#endif
#endif
