// SPDX-License-Identifier: GPL-3.0-or-later
typedef struct Entry {
    int first;
    int second;
    int third;
} Entry;
extern Entry* B_0044EDE4;
extern Entry* B_0044EDEC;
void func_0023AE20(int index) {
    if (index < 0) {
        B_0044EDE4[index & 0x7FFFFFFF].first = 0;
    } else {
        B_0044EDEC[index].first = 0;
    }
}
