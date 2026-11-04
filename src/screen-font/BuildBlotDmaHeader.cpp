struct DMAS { char pad[0xC]; int *cur; };
struct Slot { int kind; float scale; int tagAddress; int zero; };
struct BLOT { char pad[0xA4]; int shift; };
extern "C" {
void CopyAqw__FPvT0i(void *, void *, int);
Slot *OnGameLoad__FP4GAME(void);
extern char B_002DF010[];
extern char B_00442210[];
extern DMAS g_2dea28;
}
static inline void Flush(DMAS *dmas) { *dmas->cur = 0x11000000; dmas->cur = dmas->cur + 1; }
static inline void Pad(DMAS *dmas, int remainder) {
    while (((int)dmas->cur & 0xF) != remainder) { *dmas->cur = 0; dmas->cur = dmas->cur + 1; }
}
static inline void Bulk(DMAS *dmas, int tag, void *source, int count) {
    *dmas->cur = tag;
    dmas->cur = dmas->cur + 1;
    CopyAqw__FPvT0i(dmas->cur, source, count);
    dmas->cur = dmas->cur + count * 4;
}
static inline int *PartA(DMAS *dmas, void *source) {
    int *tag = dmas->cur;
    *(long *)tag = 0x10000000;
    dmas->cur = dmas->cur + 4;
    Flush(dmas);
    Pad(dmas, 0xC);
    Bulk(dmas, 0x50000003, source, 3);
    return tag;
}
static inline void PartB(DMAS *dmas, void *source) {
    int *p = dmas->cur;
    if (((int)p & 0xF) != 0xC) {
        do {
            *p = 0;
            dmas->cur = dmas->cur + 1;
            p = dmas->cur;
        } while (((int)p & 0xF) != 0xC);
    }
    Bulk(dmas, 0x50000025, source, 0x25);
}
static inline void PartC(DMAS *dmas) {
    Flush(dmas);
    Pad(dmas, 0);
}
static inline void PartD(DMAS *dmas, int *tag) {
    *tag |= (((int)dmas->cur - (int)tag) >> 4) - 1;
    *(long *)dmas->cur = 0x60000000;
    dmas->cur = dmas->cur + 4;
}
extern "C" void BuildBlotDmaHeader(BLOT *self)
{
    int *tag = PartA(&g_2dea28, B_00442210);
    PartB(&g_2dea28, B_002DF010);
    PartC(&g_2dea28);
    PartD(&g_2dea28, tag);
    Slot *slot = OnGameLoad__FP4GAME();
    slot->kind = 0x15; //P
    slot->scale = (float)(self->shift << 18); //P
    slot->zero = 0; //P
    slot->tagAddress = (int)tag & 0x0FFFFFFF; //P
}
