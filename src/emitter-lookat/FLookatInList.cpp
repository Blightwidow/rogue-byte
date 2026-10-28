// SPDX-License-Identifier: GPL-3.0-or-later
struct LOOKAT;
struct LOOKATOWNER { char pad[0x90]; LOOKAT *plookatFirst; };
struct LOOKAT { int lookatk; char pad0[4]; LOOKATOWNER *powner; char pad1[4]; LOOKAT *plookatNext; };
extern "C" int FLookatInList(LOOKAT *plookat)
{
    for (LOOKAT *plookatCur = plookat->powner->plookatFirst; plookatCur != 0; plookatCur = plookatCur->plookatNext) {
        if (plookatCur == plookat) return 1;
    }
    return 0;
}
