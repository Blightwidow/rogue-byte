// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
unsigned int func_002413E0(unsigned int address) {
    if ((address >> 28) == 7) {
        address &= 0x0FFFFFFF;
        address |= 0x80000000;
    }
    return address;
}
}
