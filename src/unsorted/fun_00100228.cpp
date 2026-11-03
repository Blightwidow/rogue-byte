#include "sly2.h"
extern "C" {
int CRef_CopyConstruct(int, char *);
int CRef_Destruct(char *);
int CRef_SetBool(char *, int);
int FIsBasicDerivedFrom(int, int);
int RefSetArgsFromSplice__FiP4CRefP4OTYPe(char *, int, int, int *, int *);
int RefCallFIsBasicDerivedFrom(int arg0, int arg1, int unused, int arg3)
{
    char sp[0x10] __attribute__((aligned(16)));
    int sp10;
    int sp14;
    sp10 = 7;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 1, arg3, &sp10, &sp14);
    CRef_SetBool(sp, FIsBasicDerivedFrom(arg1, sp14) != 0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
