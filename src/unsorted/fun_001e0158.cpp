/* SPDX-License-Identifier: GPL-3.0-or-later */
struct T { int kind; };
struct U { char pad[0x18]; int v18; char pad2[0x14]; T* t; };
struct O { char pad[0x68]; U* u; };
extern "C" void func_001E0158(O* o, int v) { U* u = o->u; if (u) { if (u->t->kind == 9) u->v18 = v; } }
