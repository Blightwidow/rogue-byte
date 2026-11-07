// SPDX-License-Identifier: GPL-3.0-or-later
extern void func_002398C8(void);
extern void _Exit(int);
void exit(int status) {
    func_002398C8();
    _Exit(status);
}
