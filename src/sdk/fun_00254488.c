// SPDX-License-Identifier: GPL-3.0-or-later
extern void func_00251E60(int);
void func_00254488(int arg0)
{
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000) {
        func_00251E60(arg0);
    }
}
