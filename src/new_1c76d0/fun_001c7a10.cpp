struct Slots { char pad[0x1C]; unsigned count; int items[3]; };
extern "C" void func_001C7A10(char *self, int value)
{
    Slots *slots = *(Slots **)(self + 0x244);
    unsigned n = slots->count;
    if (n < 3) {
        slots->items[n] = value;
        slots->count = n + 1;
    }
}
