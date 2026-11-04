#include "sly2.h"
struct MOVTEXT { char *pstr; };
extern "C" {
char *strcat(char *, const char *);
float FFindLevel(void *);
int CMovieText_Cch(MOVTEXT *);
int FStreamPlaying(void *, int);
float TStream(void *);
void CMovieText_Trim(MOVTEXT *);
extern char B_003DD040[];
extern float g_2dded0;
extern char RO_STR_002A97F0[];
}

extern "C" void func_00227820(int *pid, MOVTEXT *ptext)
{
    if (*pid == -1) {
        return;
    }
    float level = FFindLevel(B_003DD040) - 0.5f;
    int count = CMovieText_Cch(ptext);
    int shown;
    if (level <= 0.0f || !FStreamPlaying(B_003DD040, *pid)) {
        shown = count;
    } else {
        shown = (int)((TStream(B_003DD040) / level) * (float)count);
    }
    int flag;
    if (shown < count) {
        CMovieText_Trim(ptext);
        flag = 1;
    } else {
        flag = (int)(g_2dded0 * 4.0f) & 1;
    }
    if (flag) {
        strcat(ptext->pstr, RO_STR_002A97F0);
    }
}
