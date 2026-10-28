struct G { char pad0[0x394]; unsigned count; int items[8]; };
void AddGuardPriorityClass(G *guard, int value)
{
unsigned count = guard->count; unsigned next = count + 1; if (count < 3) { guard->count = next; *(int *)((char *)guard + count * 4 + 0x398) = value; }
}
