// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
enum RUMS { RUMS_OFF };
struct RUMPAT { int count; char b0; char b1; };
struct RUMBLE { int port; int slot; int rums; RUMPAT *pattern; char pad[8]; float settle; };
extern float g_2ddf10;
extern "C" int scePadSetActDirect(int, int, char *);
void StopRumbleActuators(RUMBLE *);
void SetRumbleRums(RUMBLE *rumble, RUMS rums)
{
    if (rums == rumble->rums)
        return;
    switch (rums) {
    case 0:
    case 1:
        break;
    case 2: {
        char actuators[2];
        RUMPAT *pattern = rumble->pattern;
        actuators[0] = pattern->b0;
        actuators[1] = pattern->b1;
        scePadSetActDirect(rumble->port, rumble->slot, actuators);
        break;
    }
    case 3:
    case 4:
        StopRumbleActuators(rumble);
        rumble->settle = g_2ddf10 * 4.0f;
        break;
    }
    rumble->rums = rums;
}
