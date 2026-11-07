// SPDX-License-Identifier: GPL-3.0-or-later
extern int memcmp(const void *, const void *, unsigned int);
extern char B_0044BDA8[];
extern char D_002C49E4[];
extern char *D_002C4A90;
int func_00237DE0(void) {
    char *expected = D_002C49E4;
    char *current = B_0044BDA8;
    int differs = 0;
    if (memcmp(current, expected, 4) != 0 && memcmp(current, D_002C4A90, 4) != 0) {
        differs = memcmp(expected, D_002C4A90, 4) != 0;
    }
    return differs;
}
