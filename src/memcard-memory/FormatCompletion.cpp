extern "C" char B_003D4A60[];
extern "C" char B_003DA530[];
extern "C" char B_003DD490[];
extern "C" char RO_002A6EC8[];
extern "C" int CGc_FFindScreen(char *);
extern "C" int NEpisodeBest();
extern "C" int SidEpisodeName(int);
extern "C" char *PchzStringFromId(char *, int);
extern "C" int NPercentCompleteSaveData(char *, char *);
extern "C" int sprintf(char *, const char *, ...);
void FormatCompletion(char *pchz)
{
    if (CGc_FFindScreen(B_003DA530) == 0)
        sprintf(pchz, RO_002A6EC8, PchzStringFromId(B_003DD490, SidEpisodeName(NEpisodeBest())),
                NPercentCompleteSaveData(B_003DD490 + 0x3A18, B_003D4A60));
}
