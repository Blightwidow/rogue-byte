// SPDX-License-Identifier: GPL-3.0-or-later
struct VTE { short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct VT { char pad[0x18]; VTE slot2; };
struct LO { char pad[0xC]; VT *pvt; };
extern "C" void func_00133380(LO *plo)
{
    VTE *pentry = &plo->pvt->slot2;
    pentry->fn((char *)plo + pentry->delta, 0x6, 0, 0, 0, 0);
}
