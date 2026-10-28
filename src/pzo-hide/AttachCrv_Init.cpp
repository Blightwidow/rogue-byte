#include "sly2.h"
extern "C" void InitCrv(void *);
extern "C" void bevy_player_p6_182c70(void *);
void AttachCrv_Init(void *pcrv)
{
    InitCrv(pcrv);
    bevy_player_p6_182c70((char *)pcrv + 0x190);
    *(int *)((char *)pcrv + 0x1BC) = 3;
}
