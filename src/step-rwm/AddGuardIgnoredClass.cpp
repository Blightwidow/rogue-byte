struct Guard {
    char pad0[0x3A8];
    unsigned count;
    int items[8];
};
void AddGuardIgnoredClass(Guard *guard, int value)
{
    unsigned count = guard->count;
    if (count < 5) {
        guard->items[count] = value;
        guard->count = count + 1;
    }
}
