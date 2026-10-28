/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SWL {
    char pad0[0x4154]; void *table[0x100];
    int dirty; int pad4558; void *root; char pad4560[0x4570 - 0x4560]; unsigned global[8];
    unsigned freeBits[8];
};
struct LIGHT {
    char pad0[0xE0]; int e0; char pad1[0x118 - 0xE4]; int index; char pad2[0x15C - 0x11C]; int skip;
    int f160; char pad3[4]; float radius;
};
extern "C" {
QW PosLoWorld(void *);
void AddLightToBspRegions(SWL *, void *, QW, int, float);
}
static inline int IbitLowest(unsigned bit, int base)
{
    int result = base;
    if (bit & 0xAAAAAAAA) result += 1;
    if (bit & 0xCCCCCCCC) result += 2;
    if (bit & 0xF0F0F0F0) result += 4;
    if (bit & 0xFF00FF00) result += 8;
    if (!(bit & 0xFFFF0000)) { } else result += 16;
    return result;
}
extern "C" void AddLightToSw(SWL *sw, LIGHT *light)
{
    if (light->index < 0) {
        unsigned *free = sw->freeBits;
        unsigned iword;
        for (iword = 0; ; iword++) {
            if (iword >= 8) return;
            unsigned bits = free[iword];
            if (bits == 0) continue;
            unsigned lowest = bits & (0u - bits);
            int ilight = IbitLowest(lowest, iword * 32);
            free[iword] &= ~lowest;
            *(void **)((char *)sw + ilight * 4 + 0x4154) = light;
            light->index = ilight;
            break;
        }
    }
    if (sw->dirty != 0 || light->skip != 0) return;
    if (light->e0 != 0 && light->f160 == 0 && sw->root != 0) {
        AddLightToBspRegions(sw, sw->root, PosLoWorld(light), light->index, light->radius);
        return;
    }
    int ilight = light->index;
    sw->global[ilight / 32] |= 1 << ilight;
}
