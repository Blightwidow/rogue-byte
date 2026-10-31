struct Bytes8_149A50 { char b[8]; };
struct Entry_149A50 { int id; Bytes8_149A50 data; int callback; };
extern "C" {
void AppendSlEntry(char *, Entry_149A50 *);
Entry_149A50 *PvAllocSlotheapImpl(char *);
void QueueSwCallback(char *self, int id, long data, int callback) {
    Entry_149A50 *entry = PvAllocSlotheapImpl(self + 0x3C90);
    entry->id = id;
    entry->data = *(Bytes8_149A50 *)&data;
    entry->callback = callback;
    AppendSlEntry(self + 0x3CA8, entry);
}
}
