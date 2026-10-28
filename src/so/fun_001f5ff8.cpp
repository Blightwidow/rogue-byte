struct ENTRY {
    int key;
    char pad[0x24];
};
struct SO {
    char pad0[0xB8];
    int count;
    char pad1[4];
    ENTRY *entries;
};
extern "C" ENTRY *func_001F5FF8(SO *so, int key)
{
    for (int index = 0; index < so->count; index++) {
        if (so->entries[index].key == key)
            return &so->entries[index];
    }
    return 0;
}
