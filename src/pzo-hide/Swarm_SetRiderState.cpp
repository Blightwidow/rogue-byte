#include "sly2.h"
extern "C" float g_2dded0;
extern "C" char B_002DEB30[];
extern "C" void RemoveDlEntry(void *);
extern "C" void AppendDlEntry(void *, void *);
extern "C" void SwarmGroup_LayoutBands(void *, void *);
extern "C" void bevy_camera_follow_activity(void *, int, void *);

void Swarm_SetRiderState(void *pswarm, void *prider, int state)
{
    if (state != ((int *)prider)[0x24 / 4]) {
        ((int *)prider)[0x24 / 4] = state;
        ((float *)prider)[0x28 / 4] = g_2dded0;
        if (state == 2) {
            char *pgroup = (char *)((void **)prider)[0x20 / 4];
            int count = ((int *)pgroup)[0xC / 4] - 1;
            ((int *)pgroup)[0xC / 4] = count;
            RemoveDlEntry(pgroup + 0x10);
            AppendDlEntry((char *)pswarm + 0x28C, prider);
            if (((int *)pgroup)[0xC / 4] == 0)
                bevy_camera_follow_activity(B_002DEB30, 0x3A, pswarm);
            SwarmGroup_LayoutBands(pswarm, pgroup);
        }
    }
}
