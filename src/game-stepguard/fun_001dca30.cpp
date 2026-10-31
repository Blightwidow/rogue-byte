typedef int s32;
extern "C" {
char *PchzStringFromId(void *, s32);
char *strcpy(char *, const char *);
extern s32 B_003DA180;
extern char B_003DD490[];

void func_001DCA30(char *arg0) {
    s32 stringId;
    switch (B_003DA180) {
    case -1: stringId = 0xDE; break;
    case 0: stringId = 0xDF; break;
    case 1: stringId = 0xE0; break;
    default:
        *arg0 = 0;
        return;
    }
    strcpy(arg0, PchzStringFromId(B_003DD490, stringId));
}
}
