#include "sly2.h"
struct SW;
extern SW B_003DD490;
extern char B_003D9ED0;
extern char RO_002A6EB8;
int func_001B0078(char *);
char *PchzStringFromId(SW *, int);
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
void func_001ADBB8(char *dest)
{
    int id = func_001B0078(&B_003D9ED0);
    if (id != 0x19) {
        if (id < 0x19) return;
        if (id >= 0x20) return;
        if (id < 0x1E) return;
    }
    strcpy(dest, PchzStringFromId(&B_003DD490, 0x40));
    strcat(dest, &RO_002A6EB8);
}
