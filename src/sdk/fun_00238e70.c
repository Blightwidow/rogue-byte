// SPDX-License-Identifier: GPL-3.0-or-later
extern int memcmp(const void *, const void *, unsigned int);
extern char B_0044C268[];
extern char D_002C49E4[];
extern char *D_002C4A9C;
int func_00238E70(void) {
    char *expected = D_002C49E4;
    char *current = B_0044C268;
    int differs = 0;
    if (memcmp(current, expected, 4) != 0 && memcmp(current, D_002C4A9C, 4) != 0) {
        differs = memcmp(expected, D_002C4A9C, 4) != 0;
    }
    return differs;
}
