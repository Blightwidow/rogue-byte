// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
void HideCountdownBlot(s8 *arg0) {
    s8 *obj = *(s8 **)(arg0 + 0x3BC4);

    if (obj != 0) {
        s8 *vtable = *(s8 **)(obj + 0xC);
        void (*method)(s8 *) = *(void (**)(s8 *))(vtable + 0x194);
        method(obj + *(s16 *)(vtable + 0x190));
        *(s32 *)(arg0 + 0x476C) = 0;
        return;
    }
    *(s32 *)(arg0 + 0x476C) = 0;
}

}
