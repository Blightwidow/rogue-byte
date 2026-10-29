// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32; typedef int s128 __attribute__((mode(TI)));
extern "C" {
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);

s32 func_001EC6D0(s8 *arg0, s32 arg1, s32 arg2, s8 *arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *entry = *(s8 **)(arg0 + 0x20) + (arg1 << 3);
    *(s128 *)sp = *(s128 *)(*(s8 **)(entry + 4) + 0x30);
    AddVifUnpack__4VIFS3UPKiPvi(arg3, 0xC, 1, sp, arg2);
    return 1;
}

}
