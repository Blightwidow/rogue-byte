struct S { char pad0[0x150]; unsigned count; void *items[4]; };
void AddBarrierObject(S *self, void *item)
{
    unsigned count = self->count;
    if (count < 4) {
        self->items[count] = item;
        self->count = count + 1;
    }
}
