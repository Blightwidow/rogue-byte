// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct TFT {
    int fLeft;      // 0x00
    int fPlus;      // 0x04
    int fSpace;     // 0x08
    int fAlt;       // 0x0C
    int fZero;      // 0x10
    int fNoPrec;    // 0x14
    int cchWidth;   // 0x18
    int cchPrec;    // 0x1C
    int cbArg;      // 0x20
    int cVecElem;   // 0x24
    int cVecRow;    // 0x28
    char chType;    // 0x2C
    char pad2D[3];
    int fUpper;     // 0x30
};
extern unsigned char RO_002AA6A1[];
int CchParsePchzInt(char *, int *);
int CchParsePchzTft(char *pchz, TFT *ptft, char **ppvaArg)
{
    int state = 0;
    unsigned char *pch = (unsigned char *)pchz;
    int next;

    memset(ptft, 0, 0x34);
    if (*pch != 0) {
        for (;;) {
            int advance = 0;
            next = state;
            switch (state) {
            case 0: {
                int ch = *pch;
                if (ch != '%') {
                    next = 6;
                } else {
                    int chNext = pch[1];
                    next = 1;
                    if (chNext == ch) {
                        ptft->chType = chNext;
                        next = 6;
                        advance = 2;
                    } else {
                        advance = 1;
                    }
                }
                break;
            }
            case 1:
                switch (*pch) {
                case '-':
                    ptft->fLeft = 1;
                    advance = 1;
                    break;
                case '+':
                    ptft->fPlus = 1;
                    advance = 1;
                    break;
                case ' ':
                    ptft->fSpace = 1;
                    advance = 1;
                    break;
                case '#':
                    ptft->fAlt = 1;
                    advance = 1;
                    break;
                case '0':
                    ptft->fZero = 1;
                    advance = 1;
                    break;
                default:
                    next = 2;
                    break;
                }
                break;
            case 2:
                if (*pch == '*') {
                    int *pnArg = (int *)*ppvaArg;
                    int width;
                    *ppvaArg = (char *)(pnArg + 2);
                    width = *pnArg;
                    ptft->cchWidth = width;
                    if (width < 0) {
                        width = (width < 0) ? -width : width;
                        ptft->fLeft = 1;
                        ptft->cchWidth = width;
                    }
                    advance = 1;
                } else {
                    advance = CchParsePchzInt((char *)pch, &ptft->cchWidth);
                }
                if (pch[advance] == '.') {
                    next = 3;
                    advance++;
                } else {
                    next = 4;
                }
                break;
            case 3:
                if (*pch == '*') {
                    int *pnArg = (int *)*ppvaArg;
                    int prec;
                    *ppvaArg = (char *)(pnArg + 2);
                    prec = *pnArg;
                    advance = 1;
                    prec = (prec < 0) ? -prec : prec;
                    ptft->cchPrec = prec;
                } else {
                    advance = CchParsePchzInt((char *)pch, &ptft->cchPrec);
                }
                ptft->fNoPrec = ptft->cchPrec == 0;
                next = 4;
                break;
            case 4: {
                switch (*pch) {
                case 'h':
                    ptft->cbArg = 1;
                    advance = 1;
                    break;
                case 'l':
                    advance = 1;
                    if (pch[1] != 'l') {
                        ptft->cbArg = 2;
                        break;
                    }
                case 'L':
                case 'q':
                    ptft->cbArg = 2;
                    advance++;
                    break;
                case 'M':
                case 'V':
                case 'm':
                case 'v': {
                    int kind = 3;
                    int row = 1;
                    int ch;
                    int lower;
                    if (RO_002AA6A1[*pch] & 1)
                        kind = 4;
                    ptft->cVecElem = kind;
                    ch = *pch;
                    lower = (RO_002AA6A1[ch] & 1) ? ch + 0x20 : ch;
                    if (lower ^ 'v')
                        row = kind;
                    ptft->cVecRow = row;
                    advance = 1;
                    break;
                }
                default:
                    break;
                }
                next = 5;
                break;
            }
            case 5:
                if (*pch != '%') {
                    int ch = *pch;
                    int ch2;
                    int lower;
                    ptft->fUpper = RO_002AA6A1[ch] & 1;
                    ch2 = *pch;
                    lower = (RO_002AA6A1[ch2] & 1) ? ch2 + 0x20 : ch2;
                    ptft->chType = lower;
                }
                advance = 1;
                next = 6;
                break;
            default:
                return pch - (unsigned char *)pchz;
            }
            pch += advance;
            state = next;
            if (*pch == 0 || next == 6)
                break;
        }
    }
    return pch - (unsigned char *)pchz;
}
