// SPDX-License-Identifier: GPL-3.0-or-later
struct OSTRM {
    int CbWrite(void *pv, int cb);
};
struct TFT {
    int fLeft;      // 0x00
    int fPlus;      // 0x04
    int fSpace;     // 0x08
    int fAlt;       // 0x0C
    int fZero;      // 0x10
    int fPrec;      // 0x14
    int cchWidth;   // 0x18
    int cchPrec;    // 0x1C
    int pad20[3];
    unsigned char chType;    // 0x2C
    char pad2D[3];
    int fUpper;     // 0x30
};
struct UL {
    unsigned long ul;
};
extern "C" {
int FNegTftUl__FP3TFTP2UL(TFT *ptft, UL *pul);
int UnRadixFromChConversion__Fc(unsigned char ch);
int CchAchFromUl__FPciUlUi(char *pch, int cch, unsigned long ul, unsigned radix);
void UpperizePchz__FPc(char *pchz);
int strlen(const char *);
extern unsigned short RO_002A9460, RO_002A9468, RO_002A9470, RO_002A9480;
extern char RO_002A9478[], RO_002A9488[];
}
void WriteTftUl__FP3TFTP5OSTRMUl(TFT *ptft, OSTRM *postrm, unsigned long ulValue)
{
    char ach[0x50];
    char achPrefix[0x10];
    char achPad[0x10];
    UL ul;
    int cchTotal;
    int cchLead;
    int cchTrail;
    int cchZero;
    int cchPrefix;
    int cchDigits;
    int n;

    ul.ul = ulValue;
    if (ptft->fPrec != 0 || ptft->cchPrec != 0)
        ptft->fZero = 0;
    if (ptft->fPrec != 0 && ul.ul == 0) {
        cchPrefix = 0;
        cchZero = 0;
        cchDigits = 0;
    } else {
        int fNeg = FNegTftUl__FP3TFTP2UL(ptft, &ul);
        cchZero = ptft->cchPrec;
        achPrefix[0] = 0;
        switch (ptft->chType) {
        case 'd':
        case 'i':
            if (fNeg)
                *(unsigned short *)achPrefix = RO_002A9460;
            else if (ptft->fPlus)
                *(unsigned short *)achPrefix = RO_002A9468;
            else if (ptft->fSpace)
                *(unsigned short *)achPrefix = RO_002A9470;
            cchZero -= strlen(achPrefix);
            break;
        case 'b':
            if (ptft->fAlt) {
                *(unsigned short *)achPrefix = *(unsigned short *)RO_002A9478;
                achPrefix[2] = RO_002A9478[2];
            }
            break;
        case 'o':
            if (ptft->fAlt)
                *(unsigned short *)achPrefix = RO_002A9480;
            break;
        case 'x':
            if (ptft->fAlt) {
                *(unsigned short *)achPrefix = *(unsigned short *)RO_002A9488;
                achPrefix[2] = RO_002A9488[2];
            }
            break;
        }
        cchPrefix = strlen(achPrefix);
        cchDigits = CchAchFromUl__FPciUlUi(ach, 0x40, ul.ul, UnRadixFromChConversion__Fc(ptft->chType));
        cchZero -= cchDigits;
        cchZero = cchZero >= 0 ? cchZero : 0;
    }
    ach[cchDigits] = 0;
    if (ptft->fUpper) {
        UpperizePchz__FPc(achPrefix);
        UpperizePchz__FPc(ach);
    }
    cchTotal = cchPrefix + cchZero + cchDigits;
    cchLead = 0;
    cchTrail = 0;
    if (cchTotal < ptft->cchWidth) {
        int cchPad = ptft->cchWidth - cchTotal;
        if (ptft->fLeft)
            cchTrail = cchPad;
        else if (ptft->fZero == 0)
            cchLead = cchPad;
        else if (cchDigits != 0)
            cchZero += cchPad;
        else
            cchLead = cchPad;
    }
    achPad[0] = ' ';
    n = cchLead;
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
    postrm->CbWrite(achPrefix, cchPrefix);
    achPad[0] = '0';
    n = cchZero;
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
    postrm->CbWrite(ach, cchDigits);
    achPad[0] = ' ';
    n = cchTrail;
    while (n-- > 0) {
        if (postrm->CbWrite(achPad, 1) != 1)
            break;
    }
}
