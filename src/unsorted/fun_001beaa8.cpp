struct P { char pad[0xE0]; int count; int items[1]; };
void func_001BEAA8(P *self, int item) {
    if (item) {
        int n = self->count;
        self->items[n] = item;
        self->count = n + 1;
    }
}
