struct Owner { char pad0[0x28]; int count; int items[8]; };
int IndexOfAlertGuard(Owner *owner, int guard)
{
int count = owner->count; int index = 0; if (count > 0) { int *item = owner->items; do { if (guard == *item) return index; index++; item++; } while (index < count); } return -1;
}
