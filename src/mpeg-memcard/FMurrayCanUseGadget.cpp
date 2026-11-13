// SPDX-License-Identifier: GPL-3.0-or-later
#include "murray.h"
extern "C" int bevy_player_p15_binoc_active(MURRAY *pmurray);
extern "C" int FJmpAllowsGadget(void *pjmp, int gadget);
extern "C" int FAttachAllowsGadget(void *pattach, int gadget);
extern "C" int func_0019EEF0(void *p, int gadget);
extern "C" int FIsBasicDerivedFrom(void *pbasic, int cls);
extern "C" int FActiveCplcy(void *);
extern "C" char B_002DE2E0[];
extern int g_2dfbc0;

// Retail: two jump tables (state 0..20, gadget-1 0..21); states 2, 0xd and 0x14 ask the part of the player that state uses whether the
// gadget is allowed, then fall into the gadget switch; state 5 answers by itself (gadget 3, or gadget 0x13 when the carried object's
// object at 0x180 derives from class 0x38). The gotos keep retail's block order.
extern "C" int FMurrayCanUseGadget(MURRAY *pmurray, int gadget)
{
    if (bevy_player_p15_binoc_active(pmurray) != 0)
        return 0;
    int allowed;
    switch (pmurray->state) {
    case 0: case 1: case 9: case 10:
        goto second;
    case 2:
        allowed = FJmpAllowsGadget(pmurray->PvJmp(), gadget);
        break;
    case 5:
        goto five;
    case 0xd:
        allowed = FAttachAllowsGadget(pmurray->PvAttach(), gadget);
        break;
    case 0x14:
        allowed = func_0019EEF0(pmurray->PvPipe(), gadget);
        break;
    default:
        return 0;
    }
    if (allowed != 0)
        goto second;
    return 0;
five:
    if (gadget == 3)
        goto one;
    if (gadget == 0x13) {
        if (FIsBasicDerivedFrom(*(void **)((char *)pmurray->ploCarried + 0x180), 0x38))
            return 1;
    }
    return 0;
second:
    switch (gadget) {
    case 1: case 2: case 0xf: case 0x10: case 0x14: case 0x15:
        goto one;
    case 3: {
        int result = 0;
        if (pmurray->fGadgetsAllowed != 0) {
            if ((g_2dfbc0 & 2) != 0)
                result = FActiveCplcy(B_002DE2E0) == 0;
        }
        return result;
    }
    case 0x16: {
        int jmps = pmurray->field_0x2C4;
        int result = 0;
        if (jmps != 0) {
            if (jmps != 0xb)
                result = jmps != -1;
        }
        return result;
    }
    default:
        return 0;
    }
one:
    return 1;
}
