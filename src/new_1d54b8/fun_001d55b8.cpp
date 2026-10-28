#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
extern int g_2c2d8c;
extern int B_003E0FD8;
extern int B_003D4A60;
extern "C" void RefGetGameSaveValue(CRef *, int, int *);
extern "C" void CRef_Destruct(CRef *);
unsigned int func_001D55B8(void)
{
    switch (g_2c2d8c) {
    case 1:
        break;
    case 0:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    default:
        break;
    }
    CRef ref;
    RefGetGameSaveValue(&ref, B_003E0FD8, &B_003D4A60);
    unsigned int on = ref.n;
    CRef_Destruct(&ref);
    return on ^ 1;
}
