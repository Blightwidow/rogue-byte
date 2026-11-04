struct SAVEFLAGS { char pad0[0x100C]; int value100C; int value1010; };
extern "C" {
char *PchzStringFromId(void *, int);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
void RefGetGameSaveValue(void *, int);
void CRef_Destruct(void *);
int func_001A2C98(void);
extern SAVEFLAGS B_002DFC00;
extern char B_002E65E0[];
extern char B_003DD490[];
extern const char RO_STR_002A7A70[];
}
extern "C" void GetTitlePromptText(char *out)
{
    char ref[16];
    float titleFloat = 0.0f;
    const char *newline = RO_STR_002A7A70;
    if (B_002DFC00.value100C == 1 && B_002DFC00.value1010 == 0) {
        strcpy(out, PchzStringFromId(B_003DD490, 9));
        return;
    }
    int which = *(int *)(B_002E65E0 + 0x8000 + 0x7D54);
    if (which != 0) {
        RefGetGameSaveValue(ref, *(int *)(B_003DD490 + 0x3B1C));
        titleFloat = *(float *)(ref + 4);
        CRef_Destruct(ref);
    }
    int idText = (titleFloat == 0.0f) ? 5 : 6;
    strcpy(out, PchzStringFromId(B_003DD490, idText));
    strcat(out, newline);
    strcat(out, PchzStringFromId(B_003DD490, 8));
    if (func_001A2C98() >= 2) {
        strcat(out, newline);
        strcat(out, PchzStringFromId(B_003DD490, 0x56));
    }
}
