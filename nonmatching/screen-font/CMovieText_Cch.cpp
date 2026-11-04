// SPDX-License-Identifier: GPL-3.0-or-later
struct CMovieText_215E30;
extern "C" {
void CMovieText_Reset(CMovieText_215E30 *, int);
int CMovieText_ChNext(CMovieText_215E30 *);
}

extern "C" int CMovieText_Cch(CMovieText_215E30 *ptext)
{
    int cChars = 0;
    CMovieText_Reset(ptext, 0);
    while (CMovieText_ChNext(ptext) != 0) {
        cChars++;
    }
    return cChars;
}
