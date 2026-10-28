// SPDX-License-Identifier: GPL-3.0-or-later
struct ALO;
struct ASEGA { char pad0[0x18]; ALO *paloRoot; char pad1[0x10]; ASEGA *pasegaNext; };
struct ASEG { char pad[0x50]; ASEGA *pasegaFirst; };
extern "C" ASEGA *PasegaFindAseg__FP4ASEGP3ALO(ASEG *paseg, ALO *paloRoot)
{
    volatile int frame; // forces the binary's unused 0x10-byte frame
    for (ASEGA *pasega = paseg->pasegaFirst; pasega != 0; pasega = pasega->pasegaNext) {
        if (pasega->paloRoot == paloRoot) return pasega;
    }
    return 0;
}
