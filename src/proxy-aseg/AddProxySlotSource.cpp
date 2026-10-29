struct Slot { int source; float x; float y; float w; };
struct Proxy { char pad[0xF0]; int count; Slot *slots; };
extern "C" void AddProxySlotSource(Proxy *self, int source, int x, int y, float w) {
    int count = self->count;
    if (count < 8) {
        Slot *slot = &self->slots[count];
        self->count = count + 1;
        slot->source = source;
        slot->x = (float)x;
        slot->y = (float)y;
        slot->w = w;
    }
}
