struct BRK { char pad[0x16C]; unsigned count; int classes[4]; };
void AddBrkTouchClass(BRK *brk, int cls)
{
    unsigned n = brk->count;
    if (n < 4) {
        brk->classes[n] = cls;
        brk->count = n + 1;
    }
}
