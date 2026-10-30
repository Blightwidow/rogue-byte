/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct SLOT { int sfxid; float sStart; float sFull; float uVolume; };
struct PROXY { char pad[0xE4]; int csnd; void *asnd; void *aref; int cslot; SLOT *aslot; };
extern "C" void PostLoLoad(PROXY *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" int func_001FE990(void *, int);
extern "C" void AddAmbSlotSource(void *, int, float, PROXY *, float *);
struct BANK { char pad[0x228]; void *pmgr; };
extern "C" BANK B_003DD040;

extern "C" void CloneProxy__FP5PROXYT0(PROXY *pproxy, PROXY *pproxySource)
{
    PostLoLoad(pproxy);
    ALLOCREQ allocreq;
    allocreq.cb = pproxy->csnd << 2;
    allocreq.cbAlign = 0x10;
    pproxy->aref = PvAllocSwClearImpl__Fi(&allocreq);
    void *pmgr = B_003DD040.pmgr;
    if (pmgr != 0) {
        for (int islot = 0; islot < pproxy->cslot; islot++) {
            SLOT *pslot = &pproxy->aslot[islot];
            int index = func_001FE990(&B_003DD040, pslot->sfxid);
            AddAmbSlotSource(pmgr, index, pslot->uVolume, pproxy, &pslot->sStart);
        }
    }
}
