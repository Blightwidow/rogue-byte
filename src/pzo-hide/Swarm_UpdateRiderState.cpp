#include "sly2.h"
extern "C" float g_2dded0;
extern "C" float D_FLT_002BE884;
extern "C" void Swarm_SetRiderState(void *, void *, int);

void Swarm_UpdateRiderState(void *pswarm, void *prider)
{
    int state;
    do {
        state = ((int *)prider)[0x24 / 4];
        if (state == 1) {
            if (g_2dded0 - ((float *)prider)[0x28 / 4] > D_FLT_002BE884)
                Swarm_SetRiderState(pswarm, prider, 0);
        }
    } while (((int *)prider)[0x24 / 4] != state);
}
