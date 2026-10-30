struct ENTRY_1F1768 { int kind; int second; int third; int value; };
struct OBJ_1F1768 { char pad[0x404]; ENTRY_1F1768 entries[8]; int count; int pad2[2]; int enabled; };
extern "C" void func_001F1768(OBJ_1F1768 *obj, int value) {
    if (obj->enabled != 0) {
        ENTRY_1F1768 *entry = &obj->entries[obj->count++];
        entry->value = value;
        entry->kind = 0x2B3;
        entry->third = -1;
        entry->second = 0;
    }
}
