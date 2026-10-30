// SPDX-License-Identifier: GPL-3.0-or-later
struct CMovieText { int unk0; int unk4; void *pfont; char pad[0x88 - 0xC]; float scale; };
extern "C" void CMovieText_Reset(CMovieText *, int);
extern "C" int CMovieText_ChNext(CMovieText *);
extern "C" float DxFromFontCh(void *, int);
extern "C" float CMovieText_Dx(CMovieText *ptext)
{
    float dx = 0.0f;
    CMovieText_Reset(ptext, 0);
    int ch;
    while ((ch = CMovieText_ChNext(ptext)) != 0)
        dx += DxFromFontCh(ptext->pfont, ch) * ptext->scale;
    return dx;
}
