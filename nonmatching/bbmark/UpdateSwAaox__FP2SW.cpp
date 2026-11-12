struct AaoxEntry { int owner; int field4; float *key; };
struct SW { char pad0[0x3CCC]; int dirty; int count; AaoxEntry *lists[3]; };
extern "C" void UpdateSwPox(SW *, int, int, int);
extern "C" void *memmove(void *, const void *, unsigned);
extern "C" void UpdateSwAaox__FP2SW(SW *sw) {
    if (sw->dirty == 0) return;
    sw->dirty = 0;
    if (sw->count == 0) return;
    int remaining;
    for (int listIndex = 0; listIndex < 3; listIndex++) {
        AaoxEntry *current = sw->lists[listIndex];
        float highest = *current->key;
        AaoxEntry *base = current;
        current++;
        for (remaining = sw->count - 1; remaining > 0; remaining--) {
            float currentKey = *current->key;
            if (highest <= currentKey) {
                highest = currentKey;
            } else {
                AaoxEntry *scan = current - 1;
                while (scan >= base && !(*scan->key <= currentKey)) {
                    if (current->owner != scan->owner)
                        UpdateSwPox(sw, current->field4, scan->field4, 0);
                    scan--;
                }
                scan++;
                AaoxEntry saved = *current;
                memmove(scan + 1, scan, (current - scan) * sizeof(AaoxEntry));
                *scan = saved;
            }
            current++;
        }
    }
}
