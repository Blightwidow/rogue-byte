struct Slot_2267C0 { short delta; short index; void (*fn)(void *, void *); };
struct Vt_2267C0 { char pad[0x80]; Slot_2267C0 slot[2]; };
struct Item_2267C0 { char pad0[0xC]; Vt_2267C0 *vtable; char pad1[0x14 - 0x10]; struct Body_2267C0 *body; };
struct Body_2267C0 { char pad[0x40]; int *ref; };
struct Entry_2267C0 { int flags; Item_2267C0 *item; };
extern "C" struct Iter_2267C0 *g_2dd2fc;
struct List_2267C0;
struct Iter_2267C0 { void *list; char *link; int offset; Iter_2267C0 *prev;
    inline Iter_2267C0(List_2267C0 *source);
    inline ~Iter_2267C0() { g_2dd2fc = prev; } };
struct List_2267C0 { Item_2267C0 *head; int pad; int offset; };
inline Iter_2267C0::Iter_2267C0(List_2267C0 *source)
{
    link = (char *)source;
    list = source;
    offset = source->offset;
    prev = g_2dd2fc;
    g_2dd2fc = this;
}
struct Sw_2267C0 {
    char pad0[0x3D88]; List_2267C0 list;
    char pad2[0x3F14 - 0x3D94]; int count; char pad3[0x3F1C - 0x3F18]; int *pindex; Entry_2267C0 *entries;
};
extern "C" float UpdateAsega(void *, void *);

void UpdateSwPaused(Sw_2267C0 *self)
{
    int i;
    int index;
    index = 0;
    self->pindex = &i;
    i = 0;
    if (self->count > 0) {
        do {
            Entry_2267C0 *entry = self->entries + index;
            if ((entry->flags & 0x102) == 0x102) {
                Item_2267C0 *item = entry->item;
                Vt_2267C0 *vt = item->vtable;
                int delta = vt->slot[0].delta;
                void (*fn)(void *, void *) = vt->slot[0].fn;
                fn((char *)item + delta, item);
            }
            index = ++i;
        } while (index < self->count);
    }
    Iter_2267C0 it(&self->list);
    self->pindex = 0;
    Item_2267C0 *cur = self->list.head;
    it.link = (char *)cur + it.offset;
    if (cur != 0) {
        do {
            int flags = *cur->body->ref;
            if ((flags & 1) == 0)
                flags = *(int *)flags;
            if (flags & 0x100)
                UpdateAsega(cur, cur);
            cur = *(Item_2267C0 **)it.link;
            it.link = (char *)cur + it.offset;
        } while (cur != 0);
    }
    index = 0;
    self->pindex = &i;
    i = 0;
    if (self->count > 0) {
        do {
            Entry_2267C0 *entry = self->entries + index;
            if ((entry->flags & 0x124) == 0x104) {
                Item_2267C0 *item = entry->item;
                Vt_2267C0 *vt = item->vtable;
                int delta = vt->slot[1].delta;
                void (*fn)(void *, void *) = vt->slot[1].fn;
                fn((char *)item + delta, item);
            }
            index = ++i;
        } while (index < self->count);
    }
    self->pindex = 0;
}
