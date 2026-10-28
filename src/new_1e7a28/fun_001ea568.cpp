// SPDX-License-Identifier: GPL-3.0-or-later
struct PALETTE { int id; unsigned char kind; char pad5[3]; unsigned short cword; char pad0A[2]; unsigned *pdata; int cqw; char pad14[12]; };
struct MATERIAL { char pad0[4]; unsigned char kind; char pad5[0xF]; int pdata; char pad18[0x10]; };
extern "C" int B_003DCFF8;
extern "C" PALETTE *B_003DCFFC;
extern "C" int B_003DCFF0;
extern "C" MATERIAL *B_003DCFF4;
extern "C" void FilterColorRgba8_1ed278(unsigned *);

extern "C" void func_001EA568(int dpv)
{
    for (int ipalette = 0; ipalette < B_003DCFF8; ipalette++) {
        PALETTE *ppalette = &B_003DCFFC[ipalette];
        if (ppalette->kind == 1) {
            ppalette->pdata = (unsigned *)(dpv + (int)ppalette->pdata);
            for (unsigned *pdwColor = ppalette->pdata; pdwColor < ppalette->pdata + ppalette->cword; pdwColor++)
                FilterColorRgba8_1ed278(pdwColor);
        }
    }
    if (B_003DCFF0 > 0) {
        int cmaterial = B_003DCFF0;
        MATERIAL *pmaterial = B_003DCFF4;
        do {
            cmaterial--;
            if (pmaterial->kind == 1)
                pmaterial->pdata = dpv + pmaterial->pdata;
            pmaterial++;
        } while (cmaterial != 0);
    }
}
