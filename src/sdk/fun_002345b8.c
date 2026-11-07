// SPDX-License-Identifier: GPL-3.0-or-later
extern unsigned char RO_002AA6A1[];
int func_002345B8(int index) {
    return (RO_002AA6A1[index] & 1) ? index + 0x20 : index;
}
