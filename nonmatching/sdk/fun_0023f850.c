typedef struct Entry {
    int field0;
    int field4;
    unsigned int start;
    unsigned int size;
} Entry;
typedef struct Region {
    unsigned int start;
    unsigned int end;
    int field8;
    Entry **entries;
    unsigned int count;
    struct Region *next;
} Region;
extern Region *B_00450278;
extern void func_0023F710(Region *);
Entry *func_0023F850(unsigned int address) {
    Region *region;
    unsigned int low;
    unsigned int high;
    unsigned int middle;
    Entry *entry;
    for (region = B_00450278; region != 0; region = region->next) {
        if (region->start == 0) {
            func_0023F710(region);
        }
        if (address >= region->start && address < region->end) {
            break;
        }
    }
    if (region != 0) {
        low = 0;
        high = region->count;
        while (low < high) {
            middle = (low + high) >> 1;
            entry = region->entries[middle];
            if (address < entry->start) {
                high = middle;
            } else {
                low = middle + 1;
                if (address < entry->start + entry->size) {
                    return entry;
                }
            }
        }
    }
    return 0;
}
