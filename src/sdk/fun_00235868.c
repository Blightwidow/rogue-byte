// SPDX-License-Identifier: GPL-3.0-or-later
extern void func_00235780(int ch);
void func_00235868(int ch) {
    if (ch == 10) {
        func_00235780(13);
        func_00235780(10);
        return;
    }
    func_00235780(ch);
}
