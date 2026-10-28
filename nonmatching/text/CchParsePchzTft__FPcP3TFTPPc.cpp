#include "sly2.h"
struct TFT { int fMinus, fPlus, fSpace, fAlt, fZero, fNoPrec, cchWidth, cchPrec, size, kind, kind2, flag30; char chConv; };
extern unsigned char RO_002AA6A1[];
int CchParsePchzInt(char *, int *);
int CchParsePchzTft(char *pchz, TFT *ptft, char **ppvaArg)
{
    memset(ptft, 0, 0x34);
    int state = 0;
    unsigned char *pch = (unsigned char *)pchz;
    if (*pch != 0) {
        do {
            int next = state;
            int advance = 0;
            switch (state) {
            case 0:
                if (*pch != '%') {
                    next = 6;
                } else if (pch[1] == '%') {
                    *(char *)((char *)ptft + 0x2C) = pch[1];
                    next = 6;
                    advance = 2;
                } else {
                    next = 1;
                    advance = 1;
                }
                break;
            case 1:
                switch (*pch) {
                case '-': *(int *)((char *)ptft + 0) = 1; advance = 1; break;
                case '+': *(int *)((char *)ptft + 4) = 1; advance = 1; break;
                case ' ': *(int *)((char *)ptft + 8) = 1; advance = 1; break;
                case '#': *(int *)((char *)ptft + 0xC) = 1; advance = 1; break;
                case '0': *(int *)((char *)ptft + 0x10) = 1; advance = 1; break;
                default: next = 2; break;
                }
                break;
            case 2:
                next = 4;
                if (*pch == '*') {
                    char *arg = *ppvaArg;
                    *ppvaArg = arg + 8;
                    int width = *(int *)arg;
                    *(int *)((char *)ptft + 0x18) = width;
                    if (width < 0) {
                        *(int *)((char *)ptft + 0) = 1;
                        *(int *)((char *)ptft + 0x18) = -width;
                    }
                    advance = 1;
                } else {
                    advance = CchParsePchzInt((char *)pch, (int *)((char *)ptft + 0x18));
                }
                if (pch[advance] == '.') {
                    next = 3;
                    advance++;
                }
                break;
            case 3:
                next = 4;
                if (*pch == '*') {
                    char *arg = *ppvaArg;
                    advance = 1;
                    *ppvaArg = arg + 8;
                    int prec = *(int *)arg;
                    if (prec < 0) prec = -prec;
                    *(int *)((char *)ptft + 0x1C) = prec;
                } else {
                    advance = CchParsePchzInt((char *)pch, (int *)((char *)ptft + 0x1C));
                }
                *(int *)((char *)ptft + 0x14) = *(int *)((char *)ptft + 0x1C) == 0;
                break;
            case 4: {
                int ch = *pch;
                switch (ch) {
                case 'h':
                    advance = 1;
                    *(int *)((char *)ptft + 0x20) = 1;
                    break;
                case 'l':
                    advance = 1;
                    if (pch[1] == 'l') {
                        advance = 2;
                    }
                    *(int *)((char *)ptft + 0x20) = 2;
                    break;
                case 'L': case 'q':
                    advance = 1;
                    *(int *)((char *)ptft + 0x20) = 2;
                    break;
                case 'M': case 'V': case 'm': case 'v': {
                    int kind = (RO_002AA6A1[ch] & 1) ? 4 : 3;
                    advance = 1;
                    *(int *)((char *)ptft + 0x24) = kind;
                    int lower = *pch;
                    if (RO_002AA6A1[lower] & 1) lower += 0x20;
                    *(int *)((char *)ptft + 0x28) = (lower != 'v') ? kind : 1;
                    next = 5;
                    break;
                }
                default:
                    next = 5;
                    break;
                }
                break;
            }
            case 5:
                if (*pch != '%') {
                    int ch = *pch;
                    *(int *)((char *)ptft + 0x30) = RO_002AA6A1[ch] & 1;
                    int lower = *pch;
                    if (RO_002AA6A1[lower] & 1) lower += 0x20;
                    *(char *)((char *)ptft + 0x2C) = lower;
                }
                advance = 1;
                next = 6;
                break;
            default:
                goto done;
            }
            pch += advance;
            state = next;
            if (*pch == 0) break;
        } while (state != 6);
    }
done:
    return (char *)pch - pchz;
}
