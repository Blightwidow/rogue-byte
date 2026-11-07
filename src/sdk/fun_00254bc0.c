// SPDX-License-Identifier: GPL-3.0-or-later
unsigned int func_00254BC0(int mode)
{
    unsigned int result = 0;
    switch (mode) {
    case 0:
        while (*(volatile int *)0x10002010 < 0) {
        }
        result = 0;
        break;
    case 1:
        result = *(volatile unsigned int *)0x10002010 >> 31;
        break;
    }
    return result;
}
