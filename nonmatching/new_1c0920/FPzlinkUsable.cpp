#include "sly2.h"
struct LINK { char pad[0x28]; unsigned long grfo; char pad1[0x120 - 0x30]; int kind; int zoneFrom; int zoneTo; };
struct PLO { char pad[0xE94]; int count; int zones[0x40]; char pad1[0xFE8 - 0xE98 - 0x100]; unsigned grf; };
int FPzlinkUsable(void *graph, LINK *link, PLO *plo)
{
    if (((link->grfo >> 60) & 1) == 0)
        return 0;
    unsigned need = link->kind == 1 ? 3 : 2;
    if ((need & plo->grf) != need)
        return 0;
    int count = plo->count;
    if (count > 0) {
        int index = 0;
        int from = 0;
        int to = 0;
        if (count > 0) {
            from = 1;
            to = 1;
            if (link->zoneFrom != plo->zones[0])
                from = 0;
            if (link->zoneTo != plo->zones[0])
                to = 0;
            if (!from || !to) {
                for (;;) {
                    index++;
                    if (index >= count)
                        break;
                    int zone = plo->zones[index];
                    if (link->zoneFrom == zone)
                        from = 1;
                    if (link->zoneTo == zone)
                        to = 1;
                    if (from && to)
                        break;
                }
            }
        }
        if (!from || !to)
            return 0;
    }
    return 1;
}
