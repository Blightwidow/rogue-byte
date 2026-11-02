struct LO { char pad[0x40]; unsigned grf; };
struct ENTRY { char b[8]; };
struct EN { unsigned grf; LO *lo; };
struct SW { char pad[0x3F14]; int count; int dead; int *running; EN *table; };
void AddSwGrfEntry(SW *sw, LO *lo)
{
    if (lo->grf & 0x40)
        return;
    int count = sw->count;
    if (count >= 0x1000 || (float)sw->dead / (float)count > 0.1f) {
        EN *end = sw->table + count;
        EN *runningEntry = sw->running ? sw->table + *sw->running : 0;
        EN *dest = sw->table;
        for (EN *source = sw->table; source < end; source++) {
            if (source == runningEntry)
                runningEntry = dest;
            if (source->lo) {
                source->lo->grf = (unsigned)dest;
                *(ENTRY *)dest = *(ENTRY *)source;
                dest++;
            }
        }
        sw->dead = 0;
        sw->count = dest - sw->table;
        if (sw->running)
            *sw->running = runningEntry - sw->table;
    }
    int index = sw->count;
    sw->count = index + 1;
    EN *entry = sw->table + index;
    entry->lo = lo;
    entry->grf = lo->grf;
    lo->grf = (unsigned)entry;
}
