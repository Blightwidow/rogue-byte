struct Entry_1F0808 { int value; int pad; };
struct Table_1F0808 { char pad[0x54]; Entry_1F0808 *entries; };
struct Obj_1F0808 { char pad[0x24]; Table_1F0808 *table; char pad2[0x34 - 0x28]; int index_a; int index_b; };
extern "C" int func_001F0808(Obj_1F0808 *self) {
    int index = self->index_b;
    if (index >= 0) {
        return self->table->entries[index].value;
    }
    index = self->index_a;
    if (index >= 0) {
        return self->table->entries[index].value;
    }
    return -1;
}
