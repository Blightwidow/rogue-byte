struct Guard {
    char pad0[0x3C0];
    unsigned count;
    int items[8];
};
void AddGuardClassFilter(Guard *guard, int value)
{
    unsigned count = guard->count;
    if (count < 2) {
        guard->items[count] = value;
        guard->count = count + 1;
    }
}
