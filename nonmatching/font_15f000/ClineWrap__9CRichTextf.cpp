// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRichText { unsigned char *pchStart; unsigned char *pchCur; void *pfont; };
extern unsigned char RO_002AA6A1[];
extern "C" void Reset__9CRichText(CRichText *);
extern "C" int ChNext__9CRichText(CRichText *);
extern "C" float DxFromCh__8CFontBrxc(void *, int);
extern "C" int ClineWrap__9CRichTextf(CRichText *prich, float dxWrap)
{
    int cline = 1;
    float dx = 0.0f;
    int ch;
    Reset__9CRichText(prich);
    while ((ch = ChNext__9CRichText(prich)) != 0) {
        if (ch == '\n') {
            cline++;
            dx = 0.0f;
        } else {
            dx += DxFromCh__8CFontBrxc(prich->pfont, ch);
        }
        if (dxWrap != 0.0f && dx > dxWrap) {
            unsigned char *pch = prich->pchCur - 1;
            unsigned char *start = prich->pchStart;
            if (pch >= start && *pch != '\n') {
                while (pch >= start && *pch != '\n') {
                    if (*pch == ' ' || *pch == '\t') {
                        if ((RO_002AA6A1[pch[1]] & 0x10) == 0) {
                            cline++;
                            prich->pchCur = pch + 1;
                            dx = 0.0f;
                            *pch = '\n';
                            break;
                        }
                    }
                    pch--;
                }
            }
            if (dx != 0.0f && *prich->pchCur != 0) {
                *prich->pchCur = '\n';
                cline++;
                dx = 0.0f;
            }
        }
    }
    return cline;
}
