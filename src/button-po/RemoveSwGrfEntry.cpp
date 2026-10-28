struct Entry { Entry *next; int unk0x4; };
struct Sw { char pad0[0x40]; Entry *freeList; };
struct Owner { char pad0[0x3F18]; int freeCount; };
void RemoveSwGrfEntry(Owner *owner, Sw *sw)
{
    Entry *entry = sw->freeList;
    if (((int)entry ^ 1) & 1) {
        sw->freeList = entry->next;
        entry->next = 0;
        entry->unk0x4 = 0;
        owner->freeCount = owner->freeCount + 1;
    }
}
