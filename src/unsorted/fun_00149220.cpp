struct S { char pad0[0x2AC]; unsigned count; void *items[8]; };
void func_00149220(S *self, void *item)
{
    unsigned count = self->count;
    if (count < 8) {
        self->items[count] = item;
        self->count = count + 1;
    }
}
