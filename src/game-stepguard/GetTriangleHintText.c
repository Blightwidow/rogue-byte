#include "types.h"

char *PchzStringFromId(s32 *, s32);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
extern s32 B_003DD490;

void GetTriangleHintText(char *text) {
    strcpy(text, PchzStringFromId(&B_003DD490, 0x40));
    strcat(text, " : &2T&.");
}
