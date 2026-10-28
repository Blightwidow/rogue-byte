// SPDX-License-Identifier: GPL-3.0-or-later
struct BARRIER { char pad[0x148]; unsigned long grfso; };
extern "C" void InitSo(BARRIER *);
extern "C" void InitBarrier(BARRIER *pbarrier)
{
    InitSo(pbarrier);
    pbarrier->grfso |= 0x400000000UL;
}
