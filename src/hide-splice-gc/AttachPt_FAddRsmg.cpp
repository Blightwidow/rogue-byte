#include "sly2.h"
extern "C" int FAddRsmg__FP4RSMGiPii3OIDN24(void *, int, int, int, int, int, int, int);
extern char B_003DD490[];
extern "C" int AttachPt_FAddRsmg(char *arg0, int arg1, int arg2, int arg3) {
    return FAddRsmg__FP4RSMGiPii3OIDN24(B_003DD490, (int)(arg0 + 0x11C), 4, (int)(arg0 + 0x118), 1, arg1, arg2, arg3);
}
