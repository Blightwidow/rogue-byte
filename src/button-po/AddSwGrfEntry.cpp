#include "sw.h"
struct ENTRY { char b[8]; };
void AddSwGrfEntry(SW *sw, LO *lo)
{
    if (lo->grfSw & 0x40)
        return;
    int count = sw->cgrfentry;
    if (count >= 0x1000 || (float)sw->cgrfentryDead / (float)count > 0.1f) {
        GRFENTRY *end = sw->agrfentry + count;
        GRFENTRY *runningEntry = sw->pigrfentryRunning ? sw->agrfentry + *sw->pigrfentryRunning : 0;
        GRFENTRY *dest = sw->agrfentry;
        for (GRFENTRY *source = sw->agrfentry; source < end; source++) {
            if (source == runningEntry)
                runningEntry = dest;
            if (source->plo) {
                source->plo->pgrfentry = dest;
                *(ENTRY *)dest = *(ENTRY *)source;
                dest++;
            }
        }
        sw->cgrfentryDead = 0;
        sw->cgrfentry = dest - sw->agrfentry;
        if (sw->pigrfentryRunning)
            *sw->pigrfentryRunning = runningEntry - sw->agrfentry;
    }
    int index = sw->cgrfentry;
    sw->cgrfentry = index + 1;
    GRFENTRY *entry = sw->agrfentry + index;
    entry->plo = lo;
    entry->grf = lo->grfSw;
    lo->pgrfentry = entry;
}
