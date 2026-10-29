// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef short s16; typedef int s32;
extern "C" {
void func_00259BB0(s8 **arg0, s8 *arg1) {
    s8 *vtable;

    if (arg1 != 0) {
        vtable = *(s8 **)(arg1 + 0xC);
        void (*method)(s8 *) = *(void (**)(s8 *))(vtable + 0xC);
        method(arg1 + *(s16 *)(vtable + 8));
    }
    *arg0 = arg1;
}

}
