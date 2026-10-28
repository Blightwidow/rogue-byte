typedef int QW __attribute__((mode(TI)));
struct Item { QW value; QW pad; };
struct Q { char pad[0x50]; unsigned count; char pad2[0x1C]; Item items[6]; };
void func_001C2148(Q *self, QW value) {
    unsigned n = self->count;
    if (n < 6) {
        Item *slot = &self->items[n];
        self->count = n + 1;
        slot->value = value;
    }
}
