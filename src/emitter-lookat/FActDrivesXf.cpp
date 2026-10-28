// SPDX-License-Identifier: GPL-3.0-or-later
struct LOOKAT;
struct LOOKATOWNER { char pad[0x90]; LOOKAT *plookatFirst; };
struct LOOKAT { int lookatk; char pad0[4]; LOOKATOWNER *powner; char pad1[0x10]; LOOKAT *plookatFwd; };
extern "C" int FActDrivesXf(LOOKAT *plookat)
{
    LOOKAT *plookatFirst = plookat->powner->plookatFirst;
    if (plookatFirst == plookat) return 1;
    if (plookatFirst != 0 && plookatFirst->lookatk == 5 && plookatFirst->plookatFwd == plookat) return 1;
    return 0;
}
