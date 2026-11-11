#include "types.h"

struct EpisodeMenu {
    char pad_0x0[0x6C];
    s32 field_0x6C;
    s32 field_0x70;
};

char *PchzStringFromId(s32 *, s32);
char *strcpy(char *, const char *);
extern struct EpisodeMenu *B_003DA4D0;
extern s32 B_003DD490;

void func_001DDE58(char *text) {
    if (B_003DA4D0 != 0) {
        strcpy(text, PchzStringFromId(&B_003DD490, B_003DA4D0->field_0x6C));
    }
}
