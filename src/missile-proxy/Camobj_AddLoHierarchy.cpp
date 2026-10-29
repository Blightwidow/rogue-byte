#include "sly2.h"
extern "C" {
void AddLoHierarchy(char *arg0);
void SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(char *, int, char *, int, char *);
extern char B_002DDF40[];
void Camobj_AddLoHierarchy(char *arg0) {
    AddLoHierarchy(arg0);
    if (*(int *)(arg0 + 0x124) != 0) {
        SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(B_002DDF40, 10, B_002DDF40 + 0x4A8, 0, arg0);
    }
}
}
