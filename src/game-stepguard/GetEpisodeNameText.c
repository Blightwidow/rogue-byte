#include "types.h"

s32 IEpisodeCurrent(void);
char *PchzStringFromId(s32 *, s32);
s32 SidEpisodeName(s32);
char *strcpy(char *, const char *);
extern s32 B_003DD490;

void GetEpisodeNameText(char *text) {
    strcpy(text, PchzStringFromId(&B_003DD490, SidEpisodeName(IEpisodeCurrent())));
}
