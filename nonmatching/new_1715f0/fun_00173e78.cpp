// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SLOT { void *actor; float tSpawn; float tFree; int pad[9]; };
struct SPAWNER { char pad[0x5C]; int count; SLOT *slots; };
extern float g_2dded0;
extern float D_002BE5E0;
SLOT *func_00173E78(SPAWNER *spawner, void *exclude)
{
    float now = g_2dded0;
    SLOT *best = 0;
    float tOldest = now - D_002BE5E0;
    float tFreeBest = now;
    int count = spawner->count;
    SLOT *slot = spawner->slots;
    for (int index = count; index != 0; index--, slot++) {
        if (slot->actor) {
            if (slot->actor != exclude) {
                if (best && !best->actor)
                    continue;
                if (slot->tSpawn >= tOldest)
                    continue;
                tOldest = slot->tSpawn;
                best = slot;
            }
        } else {
            if (slot->tFree >= tFreeBest)
                continue;
            tFreeBest = slot->tFree;
            best = slot;
        }
    }
    return best;
}
