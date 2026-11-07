// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
int func_00239450(void);
void func_002394A0(void);
void func_00239AC0(unsigned);
void func_00239CD8(int);
int func_0023A1D0(void);
int func_00239C40(void) {
    int wasEnabled = func_00239450();
    unsigned status = *(volatile unsigned*)0x10001010;
    if (status & 0x80) {
        if (wasEnabled) {
            func_002394A0();
        }
        return 1;
    }
    func_00239AC0((status & 0xFFFFF3FF) | 0x80);
    func_00239CD8(func_0023A1D0());
    if (wasEnabled) {
        func_002394A0();
    }
    return 0;
}
}
