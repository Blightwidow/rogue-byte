#include "types.h"

s32 NPercentCompleteSaveData(s32 *, s32 *);
int sprintf(char *, const char *, ...);
extern s32 B_003D4A60;
extern s32 B_003E0EA8;

void GetPercentCompleteText(char *text) {
    sprintf(text, "%d%%", NPercentCompleteSaveData(&B_003E0EA8, &B_003D4A60));
}
