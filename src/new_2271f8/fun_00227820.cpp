/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SUBTITLE { int sid; };
struct CMovieText { char *text; };
extern "C" {
extern char B_003DD040[];
extern float g_2dded0;
extern const char RO_STR_002A97F0[];
float FFindLevel(void *, int);
int CMovieText_Cch(CMovieText *);
void CMovieText_Trim(CMovieText *, int);
int FStreamPlaying(void *, int);
float TStream(void *);
char *strcat(char *, const char *);
void func_00227820(SUBTITLE *sub, CMovieText *text);
}
void func_00227820(SUBTITLE *sub, CMovieText *text)
{
    if (sub->sid == -1) return;
    float dt = FFindLevel(B_003DD040, sub->sid) - 0.5f;
    int cch = CMovieText_Cch(text);
    int show;
    float zero;
    asm("mtc1 $0, %0\n\tnop" : "=f" (zero));
    if (dt <= zero || FStreamPlaying(B_003DD040, sub->sid) == 0) {
        show = cch;
    } else {
        float t = TStream(B_003DD040);
        float fcch;
        asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (fcch) : "r" (cch));
        show = (int)((t / dt) * fcch);
    }
    int append;
    if (show < cch) {
        CMovieText_Trim(text, show);
        append = 1;
    } else {
        append = (int)(g_2dded0 * 4.0f) & 1;
    }
    if (append != 0) strcat(text->text, RO_STR_002A97F0);
}
