#include "sly2.h"
struct SlotList { char pad[0x1C]; unsigned count; int items[3]; };
struct Owner { char pad[0x158]; SlotList *list; };
void func_0013C448(Owner *self, int value)
{
    SlotList *list = self->list;
    unsigned count = list->count;
    if (count < 3) {
        list->items[count] = value;
        list->count = count + 1;
    }
}
