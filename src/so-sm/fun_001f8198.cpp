struct ITEM_1F8198 { char pad[0x18]; int key; };
struct HOLDER_1F8198 { char pad[0xA4]; int count; ITEM_1F8198 **items; };
extern "C" ITEM_1F8198 *func_001F8198(HOLDER_1F8198 *holder, int key) {
    for (int index = 0; index < holder->count; index++) {
        ITEM_1F8198 *item = holder->items[index];
        if (item->key == key) return item;
    }
    return 0;
}
