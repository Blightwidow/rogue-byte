#include "types.h"
extern "C" {
char *PchzStringFromId(s32 *, s32);
char *strcpy(char *, char *);
extern s32 B_003DD490;

struct T211348 {
    char pad0[0xCC];
    s32 ids[4];
};

void func_00211348(char *arg0, s32 arg1, T211348 *arg2) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, arg2->ids[arg1]));
}

}
