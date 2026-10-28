struct S { char pad0[0x2AC]; unsigned count; void *items[4]; };
void func_001497E0(S *self, void *item)
{
    unsigned count = self->count;
    if (count < 4) {
        self->items[count] = item;
        self->count = count + 1;
    }
}
