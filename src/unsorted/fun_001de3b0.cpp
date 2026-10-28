/* SPDX-License-Identifier: GPL-3.0-or-later */
struct S { char pad[0x170]; unsigned count; int items[7]; };
extern "C" void func_001DE3B0(S* s, int v) { unsigned n = s->count; if (n < 7) { s->items[n] = v; s->count = n + 1; } }
