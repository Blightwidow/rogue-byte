// SPDX-License-Identifier: GPL-3.0-or-later
struct BLOT_2137F0 { char pad[0xA4]; int nDepth; char pad2[0xB4 - 0xA8]; BLOT_2137F0 *pblotNext; };
extern BLOT_2137F0 *B_003E1060;
extern "C" int FBlotObscured(BLOT_2137F0 *pblot)
{
    int unused[4];  // dead local: retail's 16-byte frame has no stores
    for (BLOT_2137F0 *pblotOther = B_003E1060; pblotOther != 0; pblotOther = pblotOther->pblotNext) {
        if (pblot->nDepth < pblotOther->nDepth)
            return 1;
    }
    return 0;
}
