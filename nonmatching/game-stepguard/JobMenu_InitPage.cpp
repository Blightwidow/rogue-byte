/* SPDX-License-Identifier: GPL-3.0-or-later */
extern float g_2ddf0c;
struct JobMenu { char pad0[0x40]; int a40; float f44; char pad1[0xD4]; int a11C; int a120; int a124; };
extern "C" void JobMenu_InitPage(JobMenu* menu) { menu->a40 = -1; menu->a124 = -1; menu->f44 = g_2ddf0c; menu->a11C = -1; menu->a120 = -1; }
