extern float g_2dded0;
extern float D_FLT_002BE610;
int PsenseFindNotice(char *, int, int);
int func_00175FF0(char *notice) {
    char *sense = *(char **)(notice + 0x10);
    int found = PsenseFindNotice(sense, *(int *)(notice + 0x30), *(int *)(sense + 0x3CC));
    *(int *)(notice + 0x3C) = found;
    if (found != 0) {
        return 1;
    }
    sense = *(char **)(notice + 0x10);
    if (*(float *)(sense + 0xF04) < g_2dded0) {
        *(float *)(sense + 0xF04) = g_2dded0 + D_FLT_002BE610;
    }
    return 0;
}
