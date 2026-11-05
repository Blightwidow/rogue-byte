// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
extern int D_002C6710[];
int sceDmaGetChan(unsigned int index) {
    if (index < 10U) {
        return D_002C6710[index];
    }
    return 0;
}
}
