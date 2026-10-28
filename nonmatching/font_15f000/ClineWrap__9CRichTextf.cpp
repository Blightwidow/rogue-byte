#include "sly2.h"
struct CRichText { unsigned char *pchStart; unsigned char *pchCur; void *pfont; };
extern unsigned char RO_002AA6A1[];
extern "C" void Reset__9CRichText(CRichText *);
extern "C" int ChNext__9CRichText(CRichText *);
extern "C" float DxFromCh__8CFontBrxc(void *, int);
extern "C" int ClineWrap__9CRichTextf(CRichText *prich, float dxWrap)
{
    float dx = 0.0f;
    int cline = 1;
    int ch;
    Reset__9CRichText(prich);
    while ((ch = ChNext__9CRichText(prich)) != 0) {
        if (ch == '\n') {
            dx = 0.0f;
            cline++;
        } else {
            dx += DxFromCh__8CFontBrxc(prich->pfont, ch);
        }
        if (dxWrap != 0.0f && dxWrap < dx) {
        unsigned char *pch = prich->pchCur - 1;
        if (pch >= prich->pchStart && *pch != '\n') {
            for (;;) {
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
                if (pch < prich->pchStart || *pch == '\n')
                    break;
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
