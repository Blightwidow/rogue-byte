extern "C" {
struct ExceptionEntry {
    unsigned int start;
    unsigned int end;
    unsigned int handler;
};

unsigned int old_find_exception_handler(unsigned int pc, struct ExceptionEntry *table) {
    int bestIndex = -1;
    int entryIndex = 0;
    struct ExceptionEntry *entry;
    unsigned int entryStart;
    unsigned int entryEnd;

    if (table != 0) {
      if (table->start != 0xFFFFFFFF) {
        entry = table;
        do {
            entryStart = entry->start;
            entryEnd = entry->end;
            if (pc >= entryStart && pc < entryEnd) {
                if (bestIndex == -1 ||
                    (table[bestIndex].end >= entryEnd && entryStart >= table[bestIndex].start)) {
                    bestIndex = entryIndex;
                }
            } else if (bestIndex != -1 && pc < entryStart) {
                break;
            }
            entry++;
            entryIndex++;
        } while (entry->start != 0xFFFFFFFF);
      }
    }
    if (bestIndex != -1) {
        return table[bestIndex].handler;
    }
    return 0;
}
}
