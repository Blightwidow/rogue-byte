/* SPDX-License-Identifier: GPL-3.0-or-later */
extern "C" void Menu_SetDialog(void*, int, int);
extern "C" void Menu_ClearDialog(void* menu) { Menu_SetDialog(menu, -1, -1); }
