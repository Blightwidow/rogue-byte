#include "sly2.h"
struct Entry { int a; int b; int c; };
struct List { char pad[0x54]; int count; Entry *items; };
void func_0014A178(List *self, int a, int b)
{
    int count = self->count;
    if (count < 0x100) {
        Entry *entry = &self->items[count];
        entry->a = a;
        entry->b = b;
        self->count = self->count + 1;
    }
}
