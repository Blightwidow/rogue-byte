/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CMOVIETEXT {
    char *pchzStart;
    char *pchCur;
    void *pfont;
    char pad[0x74 - 0xC];
    float dx;
    char pad2[0x88 - 0x78];
    float gScale;
};
extern "C" {
extern const unsigned char RO_002AA6A1[];
void CMovieText_Reset(CMOVIETEXT *, void *);
int CMovieText_ChNext(CMOVIETEXT *);
float DxFromFontCh(void *, unsigned char);
}

extern "C" int CMovieText_ClineWrap(CMOVIETEXT *ptext)
{
    float dxLine = 0.0f;
    int cline = 1;
    const unsigned char *pbTable = RO_002AA6A1;
    CMovieText_Reset(ptext, 0);
    int ch;
    while ((ch = CMovieText_ChNext(ptext)) != 0) {
        if (ch == '\n') {
            dxLine = 0.0f;
            cline++;
        } else {
            dxLine = dxLine + DxFromFontCh(ptext->pfont, (unsigned char)ch) * ptext->gScale;
        }
        if (ptext->dx == 0.0f || dxLine <= ptext->dx)
            continue;
        char *pchSearch = ptext->pchCur - 1;
        if (pchSearch >= ptext->pchzStart && *pchSearch != '\n') {
            for (;;) {
                if (*pchSearch == ' ' || *pchSearch == '\t') {
                    unsigned char bNext = (unsigned char)pchSearch[1];
                    if ((pbTable[bNext] & 0x10) == 0) {
                        cline++;
                        ptext->pchCur = pchSearch + 1;
                        dxLine = 0.0f;
                        *pchSearch = '\n';
                        break;
                    }
                }
                pchSearch--;
                if (pchSearch < ptext->pchzStart || *pchSearch == '\n')
                    break;
            }
        }
        if (dxLine != 0.0f && *ptext->pchCur != 0) {
            *ptext->pchCur = '\n';
            cline++;
            dxLine = 0.0f;
        }
    }
    return cline;
}
