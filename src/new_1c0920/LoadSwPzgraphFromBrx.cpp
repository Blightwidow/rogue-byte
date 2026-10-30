extern "C" {
struct ALLOCREQ_1C0EC0 { int size; int align; };
void LoadPzgraphFromBrx(void *, int, int);
void *PvAllocSwClearImpl__Fi(ALLOCREQ_1C0EC0 *);
int U32Read__18CBinaryInputStream(int);
void LoadSwPzgraphFromBrx(char *self, int stream) {
    ALLOCREQ_1C0EC0 req;
    int count = U32Read__18CBinaryInputStream(stream);
    if (count != 0) {
        req.size = 0x30;
        req.align = 0x10;
        void *graph = PvAllocSwClearImpl__Fi(&req);
        *(void **)(self + 0x45CC) = graph;
        LoadPzgraphFromBrx(graph, count, stream);
    }
}
}
