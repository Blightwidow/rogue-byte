// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
typedef int QW __attribute__((mode(TI)));

extern "C" {
s32 PcgtPointInCgSafe(void *arg0, s32 arg1, QW point);
QW PosClosestOnCgt(s32 cgt, QW point);

s32 FFindClosestPointInCg(char *arg0, QW point, QW *arg2) {
    s32 found;

    found = PcgtPointInCgSafe(arg0, *(s32 *)(arg0 + 0x14), point);
    if (found == 0) {
        return 0;
    }
    *arg2 = PosClosestOnCgt(found, point);
    return 1;
}
}
