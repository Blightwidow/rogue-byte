struct ENTRY_1F0458 { int flags; int pad[1]; };
struct HOLDER_1F0458 { char pad[0x60]; int count; ENTRY_1F0458 *entries; };
extern "C" ENTRY_1F0458 *func_001F0458(HOLDER_1F0458 *holder, int mask) {
    for (int index = 0; index < holder->count; index++) {
        ENTRY_1F0458 *entry = &holder->entries[index];
        if (entry->flags & mask) return entry;
    }
    return 0;
}
