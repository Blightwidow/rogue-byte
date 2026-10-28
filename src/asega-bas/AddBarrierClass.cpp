struct S { char pad0[0x164]; unsigned count; void *items[4]; };
void AddBarrierClass(S *self, void *item)
{
    unsigned count = self->count;
    if (count < 4) {
        self->items[count] = item;
        self->count = count + 1;
    }
}
