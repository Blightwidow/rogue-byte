/* SPDX-License-Identifier: GPL-3.0-or-later */
#define FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
extern "C" {
extern float g_2ddf0c;
void JobMenu_InitPage(char *menu) {
    FIELD(menu, int *, 0x40) = -1;
    FIELD(menu, float *, 0x44) = g_2ddf0c;
    FIELD(menu, int *, 0x11C) = -1;
    FIELD(menu, int *, 0x120) = -1;
    FIELD(menu, int *, 0x124) = -1;
}
}
