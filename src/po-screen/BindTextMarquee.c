#include "types.h"

char *PchzStringFromId(s32 *, s32);
char *strcpy(char *, char *);
extern s32 B_003DA0D8;
extern s32 B_003DD490;

void BindTextMarquee(char *arg0) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, B_003DA0D8));
}
