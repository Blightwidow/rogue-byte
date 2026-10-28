// SPDX-License-Identifier: GPL-3.0-or-later
struct BARRIER { char pad[0xE8]; int pphys; };
extern "C" char B_003DD490;
extern "C" void PostSoLoad(BARRIER *);
extern "C" void RecalcSwOxfFilterForObject(char *, BARRIER *);
extern "C" void PostBarrierLoad(BARRIER *pbarrier)
{
    PostSoLoad(pbarrier);
    if (pbarrier->pphys != 0)
        RecalcSwOxfFilterForObject(&B_003DD490, pbarrier);
}
