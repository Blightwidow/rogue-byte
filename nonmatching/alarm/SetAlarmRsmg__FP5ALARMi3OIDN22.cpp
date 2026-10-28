// 0x148B38 SetAlarmRsmg
#include "sly2.h"

extern "C" {
void FAddRsmg__FP4RSMGiPii3OIDN24(const void *, unsigned char *, int, int *, int, int, int, int);
typedef struct { char pad[0x20]; } SwStub;
SwStub g_sw_3dd490;
}

void SetAlarmRsmg__FP5ALARMi3OIDN22(void *pbtn, int fOnTrigger, int oidRoot, int oidSM, int oidGoal)
{
    FAddRsmg__FP4RSMGiPii3OIDN24(&g_sw_3dd490, (unsigned char *)((char *)pbtn + 0xB4), 8, (int *)((char *)pbtn + 0xB0), fOnTrigger, oidRoot, oidSM, oidGoal);
}
