// SPDX-License-Identifier: GPL-3.0-or-later
extern void func_00254488(void);
extern void func_002544C0(unsigned int, unsigned int);
void func_00254628(unsigned int arg0)
{
    unsigned int remainder;
    func_00254488();
    remainder = -(*(volatile unsigned int *)0x10002020 & 7) & 7;
    if (remainder != 0) {
        func_002544C0(arg0, remainder);
    }
}
