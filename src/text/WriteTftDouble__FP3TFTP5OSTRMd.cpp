// SPDX-License-Identifier: GPL-3.0-or-later
struct OSTRM {
    int CbWrite(void *pv, int cb);
};
struct TFT {
    int fLeft;      // 0x00
    int fPlus;      // 0x04
    int fSpace;     // 0x08
    int pad0C;
    int fZero;      // 0x10
    int fPrec;      // 0x14
    int cchWidth;   // 0x18
    int cchPrec;    // 0x1C
    int pad20[3];
    unsigned char chType;    // 0x2C
    char pad2D[3];
    int fUpper;     // 0x30
};
extern "C" {
int CchAchFromDouble__FPciP3TFTd(char *pch, int cch, TFT *ptft, double d);
void UpperizePchz__FPc(char *pchz);
int strlen(const char *);
extern unsigned short RO_002A9460, RO_002A9468, RO_002A9470;
}
void WriteTftDouble__FP3TFTP5OSTRMd(TFT *ptft, OSTRM *postrm, double d)
{
    char ach[0x1C0];
    char achSign[16];
    char achPad[16];
    int cchZero = 0;
    int cchLeft;
    int cchLead;
    int n;
    int cch;
    int cchSign;
    int cchTotal;
    int fNeg;
    if (ptft->cchPrec == 0 && ptft->fPrec == 0) {
        ptft->cchPrec = 6;
    } else if (ptft->fPrec != 0 && ptft->chType == 0x67) {
        ptft->cchPrec = 1;
    }
    fNeg = d < 0.0;
    if (fNeg)
        d = 0.0 - d;
    achSign[0] = 0;
    if (fNeg)
        *(unsigned short *)achSign = RO_002A9460;
    else if (ptft->fPlus)
        *(unsigned short *)achSign = RO_002A9468;
    else if (ptft->fSpace)
        *(unsigned short *)achSign = RO_002A9470;
    cchSign = strlen(achSign);
    cch = CchAchFromDouble__FPciP3TFTd(ach, 0x1B5, ptft, d);
    ach[cch] = 0;
    if (ptft->fUpper)
        UpperizePchz__FPc(ach);
    cchTotal = cchSign + cch;
    cchLead = 0;
    cchLeft = 0;
    if (cchTotal < ptft->cchWidth) {
        int cchPad = ptft->cchWidth - cchTotal;
        if (ptft->fLeft)
            cchLeft = cchPad;
        else if (ptft->fZero && cch != 0)
            cchZero = cchPad;
        else
            cchLead = cchPad;
    }
    achPad[0] = ' ';
    n = cchLead;
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
    n = cchZero;
    postrm->CbWrite(achSign, cchSign);
    achPad[0] = '0';
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
    postrm->CbWrite(ach, cch);
    n = cchLeft;
    achPad[0] = ' ';
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
}
