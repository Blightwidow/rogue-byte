// SPDX-License-Identifier: GPL-3.0-or-later
struct OSTRM {
    int pad00[4];
    int cchWritten;  // 0x10
    int CbWrite(void *pv, int cb);
};
struct TFT {
    int pad00[7];
    int cchPrec;    // 0x1C
    int cbArg;      // 0x20
    int cVecElem;   // 0x24
    int cVecRow;    // 0x28
    unsigned char chType;    // 0x2C
};
extern "C" {
void WriteTftDouble__FP3TFTP5OSTRMd(TFT *ptft, OSTRM *postrm, double d);
void WriteTftPchz__FP3TFTP5OSTRMPc(TFT *ptft, OSTRM *postrm, char *pchz);
void WriteTftUl__FP3TFTP5OSTRMUl(TFT *ptft, OSTRM *postrm, unsigned long ul);
int strlen(const char *);
extern char RO_002A9500[], RO_002A9508[], RO_002A9510[], RO_002A9518[], RO_002A9520[];
}
void WriteTft__FP3TFTP5OSTRMPPcPci(TFT *ptft, OSTRM *postrm, char **ppchArg, char *pchFmt, int cchFmt)
{
    unsigned long ul;
    switch (ptft->chType) {
    case '%':
        postrm->CbWrite(&ptft->chType, 1);
        return;
    case 'c': {
        signed char ach[16];
        char *pch = *ppchArg;
        *ppchArg = pch + 8;
        int ch = *(unsigned char *)pch;
        ach[0] = ch;
        postrm->CbWrite(ach, 1);
        return;
    }
    case 's': {
        char *pch = *ppchArg;
        *ppchArg = pch + 8;
        WriteTftPchz__FP3TFTP5OSTRMPc(ptft, postrm, *(char **)pch);
        return;
    }
    case 'p':
        ptft->cchPrec = 8;
        ptft->chType = 'x';
        ptft->cbArg = 0;
    case 'b': case 'd': case 'i': case 'o': case 'u': case 'x':
        switch (ptft->cbArg) {
        case 0: case 1: { char *pch = *ppchArg; *ppchArg = pch + 8; ul = *(unsigned *)pch; break; }
        case 2: { char *pch = *ppchArg; *ppchArg = pch + 8; ul = *(unsigned long *)pch; break; }
        }
        WriteTftUl__FP3TFTP5OSTRMUl(ptft, postrm, ul);
        return;
    case 'e': case 'f': case 'g':
        if (ptft->cVecElem != 0) {
            const char *pszBracket = RO_002A9500;
            char *pchArg = *ppchArg;
            const char *pszRow = RO_002A9508;
            const char *pszOpen = RO_002A9510;
            *ppchArg = pchArg + 8;
            const char *pszSep = RO_002A9518;
            const char *pszClose = RO_002A9520;
            float *pflt = *(float **)pchArg;
            if (ptft->cVecRow >= 2) {
                postrm->CbWrite((void *)pszBracket, strlen(pszBracket));
            }
            for (int iRow = 0; iRow < ptft->cVecRow; ) {
                int iNext;
                if (iRow != 0)
                    postrm->CbWrite((void *)pszRow, strlen(pszRow));
                iNext = iRow + 1;
                postrm->CbWrite((void *)pszOpen, strlen(pszOpen));
                for (int iElem = 0; iElem < ptft->cVecElem; iElem++) {
                    if (iElem != 0)
                        postrm->CbWrite((void *)pszSep, strlen(pszSep));
                    WriteTftDouble__FP3TFTP5OSTRMd(ptft, postrm, (double)*pflt++);
                }
                postrm->CbWrite((void *)pszClose, strlen(pszClose));
                iRow = iNext;
            }
            if (ptft->cVecRow >= 2) {
                postrm->CbWrite((void *)pszBracket, strlen(pszBracket));
            }
        } else {
            char *pch = *ppchArg;
            *ppchArg = pch + 8;
            WriteTftDouble__FP3TFTP5OSTRMd(ptft, postrm, *(double *)pch);
        }
        return;
    case 'n':
        switch (ptft->cbArg) {
        case 0: { char *pch = *ppchArg; *ppchArg = pch + 8; **(int **)pch = postrm->cchWritten; break; }
        case 1: { char *pch = *ppchArg; *ppchArg = pch + 8; short *ps = *(short **)pch; int n = postrm->cchWritten; *ps = n; break; }
        case 2: { char *pch = *ppchArg; *ppchArg = pch + 8; **(long **)pch = postrm->cchWritten; break; }
        }
        return;
    default:
        postrm->CbWrite(pchFmt, cchFmt);
        return;
    }
}
