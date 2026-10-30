struct ENTRY_1F17B0 { int kind; int second; int third; int value; };
struct OBJ_1F17B0 { char pad[0x404]; ENTRY_1F17B0 entries[8]; int count; int pad2[2]; int enabled; };
extern "C" void func_001F17B0(OBJ_1F17B0 *obj, int kind) {
    if (obj->count <= 0 || obj->enabled != 0) {
        ENTRY_1F17B0 *entry = &obj->entries[obj->count++];
        entry->kind = kind; entry->third = -1; entry->second = 0; entry->value = 1;
    }
}
