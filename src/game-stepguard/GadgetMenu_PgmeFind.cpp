struct ENTRY { int id; char pad[0x1C]; };
struct MENU { char pad[0x4C]; int count; ENTRY *entries; };
extern "C" ENTRY *GadgetMenu_PgmeFind(MENU *menu, int id)
{
    int count = menu->count;
    if (count > 0) {
        int index = 0;
        ENTRY *entry = menu->entries;
        do {
            index++;
            if (entry->id == id)
                return entry;
            entry++;
        } while (index < count);
    }
    return 0;
}
