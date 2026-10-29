// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef short s16; typedef int s32; typedef unsigned int u32;
extern "C" {
void RetractAsega(s8 *);

void RetractAsegaHandle(s8 **arg0) {
    if (*arg0 != 0) {
        s8 *handle = *arg0;
        s8 *vtable;

        RetractAsega(handle);
        vtable = *(s8 **)((*arg0) + 0xC);
        void (*method)(s8 *) = *(void (**)(s8 *))(vtable + 0x14);
        method((*arg0) + *(s16 *)(vtable + 0x10));
        *arg0 = 0;
    }
}

}
