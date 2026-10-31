struct VT_201E88 { char pad[0x48]; short delta; short idx; void (*fn)(void *); };
struct Tgt_201E88 { char pad[0xC]; VT_201E88 *vt; };
struct Item_201E88 { char pad[0x100]; Tgt_201E88 *link; };
struct Rec_201E88 { char pad[0x30]; int count; Item_201E88 *items[1]; };
extern "C" void HideReconLinks(Rec_201E88 *rec) {
    for (int index = 0; index < rec->count; index++) {
        Tgt_201E88 *link = rec->items[index]->link;
        if (link != 0) {
            VT_201E88 *vt = link->vt;
            vt->fn((char *)link + vt->delta);
        }
    }
}