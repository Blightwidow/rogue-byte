struct G { char pad0[0x394]; unsigned count; int items[8]; };
void AddGuardPriorityClass(G *guard, int value)
{
    unsigned c = guard->count;
    if (c < 3) {
        int *p = &guard->items[c];
        guard->count = c + 1;
        *p = value;
    }
}
